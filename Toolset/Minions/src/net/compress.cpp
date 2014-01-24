#include "compress.h"
#include <type_traits>
#include <atom/os/memory/CMemory.h>
#include <atom/utility/byteswap/CByteSwap.h>
#include <electron/message/CMessage.h>
#include <electron/compress/minilzo.h>
#include "data_reader.h"


using namespace atom;
using namespace electron;

#define MIN_COMPRESS_LENGTH     64


namespace {

inline void AddToMemory(CMemory& data, const void* buf, size_t len)
{
    assert(buf && len);
    size_t cur_len = data.GetLength();
    byte* pb = (byte*)(void*)data + cur_len;
    memcpy(pb, buf, len);
    data.SetLength(cur_len + len);
}

template <typename T>
inline void operator << (CMemory& data, T val)
{
    static_assert(std::is_pod<T>::value && !std::is_pointer<T>::value, "invalid type");
    size_t cur_len = data.GetLength();
    assert(cur_len + sizeof(val) < data.GetCapacity());
    byte* pb = (byte*)(void*)data + cur_len;
    T new_val = CByteSwap::hton(val);
    memcpy(pb, &new_val, sizeof(new_val));
    data.SetLength(cur_len+ sizeof(val));
}

// Ñ¹Ëõ
CMemory CompressFrame(CMemory& data)
{   
    const int align_size = (LZO1X_MEM_COMPRESS + (sizeof(lzo_align_t)-1)) / sizeof(lzo_align_t);
    static lzo_align_t workset[align_size];

    size_t origin = data.GetLength();
    size_t crypto = origin;
    size_t reduce = origin;
    CMemory compressed = data;
    if (origin > MIN_COMPRESS_LENGTH)
    {
        lzo_uint original_length = static_cast<lzo_uint>( origin );
        lzo_uint compress_length = original_length + original_length / 16 + 67;
        if (original_length && compressed.Alloc(compress_length))
        {
            lzo1x_1_compress((byte*)(void*)data, original_length, 
                (byte*)(void*)compressed, &compress_length, workset);
            compressed.SetLength(compress_length);
        }
        if (compressed && compressed.GetLength())
        {

        }
    }

    uint16_t checksum = internet_checksum(compressed, reduce);

    // frame format: 
    // [frame  length][4 bytes]  
    // [origin length][4 bytes]  
    // [data checksum][2 bytes]
    // [data   stream][n bytes]    
    int32_t frame_length = reduce + sizeof(int32_t) + sizeof(int16_t);
    CMemory frame;
    frame.Alloc(sizeof(int32_t)*2 + sizeof(int16_t) + reduce);
    frame << frame_length;
    frame << origin;
    frame << checksum;
    AddToMemory(frame, (void*)compressed, reduce);
    return frame;
}

bool UnCompressFrame(DataReader& reader, CMemory& result)
{
    int32_t frame_length = reader.Read<int32_t>();
    int32_t compress_length = frame_length - ( sizeof(U32) + sizeof(U16) );
    int32_t origin_length = reader.Read<int32_t>();
    uint16_t checksum = reader.Read<int16_t>();
    int32_t data_length = frame_length - 6;
    CMemory data;
    data.Alloc(compress_length);
    data.Store(reader.GetData(), reader.GetLeft());
    if (internet_checksum(data, compress_length) != checksum)
    {
        data.Clear();
        return false;
    }
    CMemory uncompressed;
    if (uncompressed.Alloc(origin_length))
    {
        if (lzo1x_decompress_safe((uint8_t*)(void*)data, compress_length,
            (uint8_t*)(void*)uncompressed, (lzo_uint*)&origin_length, NULL) == LZO_E_OK)
        {
            uncompressed.SetLength(origin_length);
        }
        else
        {
            return false;
        }
    }
    result = uncompressed;
    return true;
}

} // anonymous namespace 


void SendCompressedMessage(CMessage* msg, sender_type sender)
{
    CHECK(sender && msg);
    CInterface<IStream> stream;
    if (stream.Mount(msg, IID_STREAM))
    {
        CMemory data;
        stream->Swap(data);

        data = CompressFrame(data);
        sender((void*)data, data.GetLength());
    }
    else
    {
        LOG(DEBUG) << "mount message failed.";
    }
}

CMessage* UnCompressMessage(const void* data, size_t bytes)
{
    if (data == NULL || bytes < 10)
    {
        return NULL;
    }

    DataReader reader(data, bytes);
    CMemory memory;
    if (UnCompressFrame(reader, memory))
    {
        CMessage* msg = new CMessage;
        msg->Analyze(memory);
        return msg;
    }
    return NULL;
}
