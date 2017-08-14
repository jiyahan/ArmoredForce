#include "CMaintainerThread.h"
#include "../os/memory/CMemoryScheduler.h"
#include "../os/timer/CMilisecondTimer.h"
#include "../utility/tool/CInterface.h"
#include "../interface/IMaintainable.h"
#include "../interface/IMaintainerTimeline.h"
#include "../interface/IInstanceContainer.h"
#include "../enumeration/INTERFACE_ID.h"


atom::CMaintainerThread::CMaintainerThread() : 
CThread("Maintainer"),nest(NULL),active(false)
{
}

atom::CMaintainerThread::~CMaintainerThread() 
{
}

void atom::CMaintainerThread::SetActive(bool value)
{
    active = value;
}

bool atom::CMaintainerThread::GetActive()
{
    return active;
}

int atom::CMaintainerThread::IncRef() 
{
    int result = 0;
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> IncRef();
        }
    }
    return result;
}

int atom::CMaintainerThread::DecRef() 
{
    int result = 0;
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> DecRef();
        }
    }
    return result;
}

int atom::CMaintainerThread::GetRef() 
{
    int result = 0;
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> GetRef();
        }
    }
    return result;
}

atom::IInterface * atom::CMaintainerThread::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CMaintainerThread::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

bool atom::CMaintainerThread::OnThreadBegin() 
{
    return true;
}

bool atom::CMaintainerThread::OnThreadClose() 
{
    return true;
}

U32 atom::CMaintainerThread::Run() 
{
    CInterface<IInstanceContainer>  segment_1;
    CInterface<IMaintainerTimeline> segment_2;

    if( segment_1.Mount(this, IID_INSTANCE_CONTAINER ) &&
        segment_2.Mount(this, IID_MAINTAINER_TIMELINE) )
    {
        U64 elapse(0), now(0);
        CMilisecondTimer timer; CU64Array indices;

        for( ;; )
        {
            // ��¼������ʼʱ�䣻
            timer.Record();
            now = CMilisecondTimer::Now();

            // ��ȡʱ�䵽�ڵĶ���
			indices.clear();
            segment_2 -> Forward( now, indices );
            
            // �������󣬲�����ά���ӿڣ�
            for( size_t i = 0, j = indices.size(); i < j; ++ i )
            {
                // ��ѯ�������������ڣ��������
                CObjectPtr object = segment_1 -> Obtain( indices[i] );
                if( object )
                {
                    // ������ڽӿڣ�����ýӿڣ������·���ʱ���ߣ�
                    CInterface<IMaintainable> maintainbale;
                    if( maintainbale.Mount(object, IID_MAINTAINABLE) ) 
					{
						// ִ�нӿڣ�����ȡ��һ�λ��ѵľ���ʱ�䣬�ж��Ƿ���INFINITE��
						// ������ǣ����ٴη���ʱ�����ڣ�
						U64 next  = maintainbale -> OnMaintenance( now );
						if( next != U64(INFINITE) ) {
							segment_2 -> Mark( next, object -> GetName() );
						}
                    }
                }
            }

            // �����Ҫ��ֹѭ��������ֹ��
            if( !active ) break;

            // �����ڴ��������ά���ӿڣ�
            CMemoryScheduler::GetInstance() -> Maintain();

            // ��ȡ����ʱ�䣬���ж���Ҫ���߶��ٺ���
            elapse = timer.GetElapsedTime();
            if( elapse < 50 ) {
                CThread::Sleep( 50 - elapse );
            }
        }
    }
    return 0;
}

bool atom::CMaintainerThread::OnBegin() 
{
    SetActive( true );
    return Begin( TP_BELOW_NORMAL );
}

bool atom::CMaintainerThread::OnClose() 
{
    SetActive( false );
    Close( U64(INFINITE) );
    return true;
}

void atom::CMaintainerThread::OnAwake()
{
}
