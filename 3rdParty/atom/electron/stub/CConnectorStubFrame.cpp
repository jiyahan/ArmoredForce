#include "CConnectorStubFrame.h"
#include "../message/CMessageAllocator.h"
#include "../compress/minilzo.h"
#include "../interface/IConnectorStubHeartBeat.h"
#include "../interface/IConnectorStubStatistics.h"
#include "../interface/IMessageQueueController.h"
#include "../enumeration/EVENT_ID.h"
#include "../enumeration/MESSAGE_ID.h"
#include "../enumeration/INTERFACE_ID.h"
const static U64 header_length = sizeof(U32) + sizeof(U32) + sizeof(U16);


electron::CConnectorStubFrame::CConnectorStubFrame() : 
nest(NULL),
#ifdef _SHIPPING_
cast(NULL),
#endif
length(0),record(0),lasted(0),entity(0)
{
    frames.reserve( 32 );
}

electron::CConnectorStubFrame::~CConnectorStubFrame() 
{
}

void electron::CConnectorStubFrame::OnSendFrame() 
{
    if( locker.Increase() != 1 ) {
        locker.Decrease(); return;
    }

    bool loop(true); U08 time(0);
    tagFrame::CFrameArray units; units.reserve( 32 );
        
    // Enter export section, and try to send data;
    export_region.Enter();
    for( ; loop; units.clear() )
    {
        // Entry frame buffer section, and obtain pending frames.
        frames_region.Enter();

        // If frame buffer is empty or loop time greater than 5, 
        // the loop will be end;
        if( frames.empty() ) {
            loop = false;
        } else {
            loop = ++ time < 5; units.swap( frames );
        }

        // If loop end, locker must be decrease in frame section, 
        // to avoid frame send event lose.
        if( !loop ) locker.Decrease(); 
        frames_region.Leave();

        // Write frame data to export stream;
        CInterface<IConnectorStubStatistics> segment;
        if( segment.Mount(this, IID_CONNECTOR_STUB_STATISTICS) )
        {
            for( size_t i = 0, j = units.size(); i < j; ++ i )
            {
                // frame format: 
                // [frame  length][4 bytes]  
                // [origin length][4 bytes]  
                // [data checksum][2 bytes]
                // [data   stream][n bytes]

                writer.Write( static_cast<U32>( units[i].length.reduce + sizeof(U32) + sizeof(U16) ) );
                writer.Write( static_cast<U32>( units[i].length.origin ) );
                writer.Write( units[i].verify );
                writer.Write( units[i].memory, units[i].length.reduce );
                writer.Flush();

                // submit send bytes, for statistics;
                segment -> OnSendFrame( 
                    units[i].length.origin + header_length, 
                    units[i].length.reduce + header_length );
            }
        }
    }
    export_region.Leave();
}

bool electron::CConnectorStubFrame::PreReadFrame(tagFrame & frame) 
{
    bool result = false;
    if( frame.memory )
    {
        // first, check sum;
        U16 checksum = internet_checksum( frame.memory, frame.length.reduce );
        if( checksum == frame.verify )
        {
            // if frame's origin length == reduce length, no need to decompress;
            result = ( frame.length.origin == frame.length.reduce );

            // if frame's reduce length < origin length, decompress;
            if( frame.length.reduce < frame.length.origin )
            {
                lzo_uint original_length = static_cast<lzo_uint>( frame.length.origin );
                lzo_uint compress_length = static_cast<lzo_uint>( frame.length.reduce );

                CMemory after;
                if( after.Alloc(original_length) )
                {
                    // decompress
                    if( LZO_E_OK == lzo1x_decompress_safe( 
                        frame.memory.Query<unsigned char>(),   compress_length, 
                        after       .Query<unsigned char>(), & original_length, NULL ) ) 
                    {
                        result = true;
                        after.SetLength( original_length ); 
                        frame.memory = after;
                    }
                }
            }
        }
    }
    return result;
}

bool electron::CConnectorStubFrame::PreSendFrame(tagFrame & frame) 
{
    static TLS_DECLARE lzo_align_t 
        workset[( LZO1X_MEM_COMPRESS + ( sizeof(lzo_align_t) - 1 ) ) / sizeof(lzo_align_t)];

    // if not support tls, use critical section to protect it;
    #if defined(TLS_NOT_SUPPORT)
    static CCriticalSection workset_section;
    #endif

    bool result = false;
    if( frame.memory )
    {
        result = true;
        frame.length.origin = frame.memory.GetLength();
        frame.length.crypto = frame.length.origin;
        frame.length.reduce = frame.length.origin;
        
        // 目前仅仅执行压缩，暂时不执行加密
        if( frame.length.origin > MIN_COMPRESS_LENGTH )
        {
            // frame length > MIN_COMPRESS_LENGTH, compress data;
            result = false;
            lzo_uint original_length = static_cast<lzo_uint>( frame.length.origin );
            lzo_uint compress_length = original_length + original_length / 16 + 67;

            CMemory prior, after;
            prior = frame.memory;
        
            if( original_length && after.Alloc(compress_length) ) 
            {
                #if defined(TLS_NOT_SUPPORT)
                CCriticalSectionScope scope( workset_section );
                #endif

                lzo1x_1_compress( 
                    prior.Query<unsigned char>(),   original_length,
                    after.Query<unsigned char>(), & compress_length, workset );
                after.SetLength( compress_length );
            }

            if( after && after.GetLength() ) 
            {
                result = true;
                if( after.GetLength() < frame.length.origin )
                {
                    frame.memory        = after;
                    frame.length.reduce = after.GetLength();
                }
            }
        }

        // if succeeded, calculate data's sum;
        if( result ) {
            frame.verify = internet_checksum( frame.memory, frame.length.reduce );
        }
    }
    return result;
}

int electron::CConnectorStubFrame::IncRef() 
{
    int result = 0;
	#ifdef _SHIPPING_
	if( cast )
	{
		result = cast -> IncRef();
	}
	#else
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> IncRef();
        }
    }
	#endif
    return result;
}

int electron::CConnectorStubFrame::DecRef() 
{
    int result = 0;
	#ifdef _SHIPPING_
	if( cast )
	{
		result = cast -> DecRef();
	}
	#else
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> DecRef();
        }
    }
	#endif
    return result;
}

int electron::CConnectorStubFrame::GetRef() 
{
    int result = 0;
	#ifdef _SHIPPING_
	if( cast )
	{
		result = cast -> GetRef();
	}
	#else
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> GetRef();
        }
    }
	#endif
    return result;
}

IInterface * electron::CConnectorStubFrame::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void electron::CConnectorStubFrame::SetNest(IInterface * value) 
{
    if( value ) 
	{
		nest = value;
		#ifdef _SHIPPING_
		cast = dynamic_cast<IReferencedInterface *>( nest );
		#endif
	}
}

bool electron::CConnectorStubFrame::Open(U64 connector, U64 queuename) 
{
    bool result = false;
    if( !nest || !connector || !queuename ) return result;

    CCriticalSectionScope scope( stream_region );
    entity = connector;
    object = CInstanceUtility::ObtainInstance( connector );
    queues = CInstanceUtility::ObtainInstance( queuename );

    if( object && queues )
    {
        CInterface<IEventEmitter> segment;
        if( segment.Mount(object, IID_EVENT_EMITTER) ) 
        {
            CObjectPtr object;
            object = CInstanceUtility::MakeObject( nest );
            if( object ) {
                result = segment -> Attach( object );
            }
        }

        if( result )
        {
            import_region.Enter();
            reader.Attach( object ); 
            lasted = CMilisecondTimer::Now();
            import_region.Leave();

            export_region.Enter();
            writer.Attach( object );
            export_region.Leave();
        }
    }

    if( !result )
    {
        object = NULL;
        queues = NULL;
    }
    return result;
}

bool electron::CConnectorStubFrame::Shut() 
{
    frames_region.Enter();
    frames.clear();
    frames_region.Leave();

    CCriticalSectionScope scope( stream_region );

    import_region.Enter();
    reader.Close ();
    reader.Detach();
    length = 0;
    record = 0;
    import_region.Leave();

    export_region.Enter();
    writer.Close ();
    writer.Detach();
    export_region.Leave();

    // if connector exist, shutdown it.
    if( object ) {
        CInstanceUtility::ShutdownInstance( object );
    }

    object = NULL;
    queues = NULL;
    entity = 0;
    return true;
}

bool electron::CConnectorStubFrame::Read(U64 time) 
{
    CMemory prior; U16 checksum(0); 
    bool splited(false), succeed(false);
    U64 original_length(0), compress_length(0); 
    
    import_region.Enter();
    lasted = time;
    if( length == 0 )
    {
        length = reader.ReadU32();
        if( record < length )
        {
            record = length;
            CInterface<IConnectorStubStatistics> segment_0;
            if( segment_0.Mount(this, IID_CONNECTOR_STUB_STATISTICS) ) {
                segment_0 -> OnLongFrame( record );
            }

            CInterface<IEventEmitter> segment_1;
            if( segment_1.Mount(this, IID_EVENT_EMITTER) )
            {
                tagEvent value;
                value.handle = EID_LARGEST_FRAME_LENGTH;
                value.source = CInstanceUtility::GetInstanceName( nest );
                value.append = record;
                segment_1 -> Report( value );
            }
        }
    }

    // 如果流数据的长度足够，那么开始拆分压缩帧。
    if( length && reader.Available() >= length )
    {
        splited = true;
        if( length > ( sizeof(U32) + sizeof(U16) ) )
        {
            // 读取原始数据长度；
            compress_length = length - ( sizeof(U32) + sizeof(U16) );
            original_length = reader.ReadU32();
            checksum        = reader.ReadU16();

            // 读取压缩数据内容；
            if( prior.Alloc( static_cast<size_t>(compress_length) ) )
            {
                U64 bytes_readed = reader.ReadBytes( prior, compress_length );
                succeed = ( bytes_readed == compress_length );
                prior.SetLength( static_cast<size_t>(bytes_readed) );
            }

            // 重置数据；
            length = 0; reader.Truncate();
        }
    }
    import_region.Leave();

    if( splited ) 
    {
        if( !succeed )
        {
            CInterface<IEventEmitter> segment;
            if( segment.Mount(this, IID_EVENT_EMITTER) )
            {
                tagEvent value;
                value.handle = EID_SPLITE_FRAME_FAILED;
                value.source = CInstanceUtility::GetInstanceName( nest );
                value.append = record;
                segment -> Report( value );
            }
            return false;
        }

        tagFrame frame;
        frame.memory = prior;
        frame.verify = checksum;
        frame.length.origin = original_length;
        frame.length.crypto = original_length;
        frame.length.reduce = compress_length;
             
        if( !PreReadFrame( frame ) )
        {
            CInterface<IEventEmitter> segment;
            if( segment.Mount(this, IID_EVENT_EMITTER) )
            {
                tagEvent value;
                value.handle = EID_SPLITE_FRAME_FAILED;
                value.source = CInstanceUtility::GetInstanceName( nest );
                value.append = record;
                segment -> Report( value );
            }
            return false;
        }

        CInterface<IConnectorStubStatistics> segment;
        if( segment.Mount(this, IID_CONNECTOR_STUB_STATISTICS) ) {
			segment -> OnReadFrame( 
				frame.length.origin + header_length, 
				frame.length.reduce + header_length );
        }

        // alloc message, and store message in message queue
        CMessage * message = CMessageAllocator::GetInstance() -> Allocate();
        if( message )
        {
            bool remove = false;
            if( message -> Analyze(frame.memory) )
            {
                stream_region.Enter();
                if( entity && queues )
                {
                    succeed = true;
                    message -> SetConnector( entity );
                    switch( message -> GetCommandID() )
                    {
                    case MID_HEART_BEAT_REQUEST:
                    case MID_HEART_BEAT_RESPOND:
                        {
                            CInterface<IConnectorStubHeartBeat> segment;
                            if( segment.Mount(this,  IID_CONNECTOR_STUB_HEART_BEAT) ) {
                                segment -> OnMessage( message ); remove = true;
                            }
                        }
                        break;
                    default:
                        {
                            CInterface<IMessageQueueController> segment;
                            if( segment.Mount(queues, IID_MESSAGE_QUEUE_CONTROLLER) ) {
                                succeed = segment -> Insert( entity, message );
                            }
                        }
                        break;
                    }
                }
                stream_region.Leave();
            }

            // if failed, or message is reserved, release message;
            if( !succeed || remove ) {
                CMessageAllocator::GetInstance() -> Released( message );
            }
        }
    }
    return splited;
}

bool electron::CConnectorStubFrame::Send(CMessage * message) 
{
    if( !message ) return false;

    bool result = false;
    CInterface<IStream> segment;
    if( segment.Mount(message, IID_STREAM) )
    {
        tagFrame frame;
        if( segment -> Clone(frame.memory) )
        {
            if( PreSendFrame(frame) )
            {
                // store frame in frame list;
                frames_region.Enter();
                frames.push_back( frame );
                frames_region.Leave();

                // try to send frame, if frame unit not busy.
                result = true;
                OnSendFrame(); 
            }
        }
    }
    return result;
}

U64 electron::CConnectorStubFrame::LastReceive() 
{
    CCriticalSectionScope scope( import_region );
    return lasted;
}
