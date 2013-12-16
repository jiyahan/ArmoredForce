#include "CMaintainerThread.h"
#include "../os/memory/CMemoryScheduler.h"
#include "../os/timer/CMilisecondTimer.h"
#include "../utility/tool/CInterface.h"
#include "../interface/IMaintainable.h"
#include "../interface/IMaintainerTimeline.h"
#include "../interface/IInstanceContainer.h"
#include "../enumeration/INTERFACE_ID.h"
//Begin section for file CMaintainerThread.cpp
//TODO: Add definitions that you want preserved
//End section for file CMaintainerThread.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CMaintainerThread::CMaintainerThread() : 
CThread("Maintainer"),nest(NULL),active(false)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CMaintainerThread::~CMaintainerThread() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CMaintainerThread::SetActive(bool value)
{
    //TODO Auto-generated method stub
    active = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CMaintainerThread::GetActive()
{
    //TODO Auto-generated method stub
    return active;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CMaintainerThread::IncRef() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CMaintainerThread::DecRef() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CMaintainerThread::GetRef() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::IInterface * atom::CMaintainerThread::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CMaintainerThread::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) nest = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CMaintainerThread::OnThreadBegin() 
{
    //TODO Auto-generated method stub
    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CMaintainerThread::OnThreadClose() 
{
    //TODO Auto-generated method stub
    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U32 atom::CMaintainerThread::Run() 
{
    //TODO Auto-generated method stub
    CInterface<IInstanceContainer>  segment_1;
    CInterface<IMaintainerTimeline> segment_2;

    if( segment_1.Mount(this, IID_INSTANCE_CONTAINER ) &&
        segment_2.Mount(this, IID_MAINTAINER_TIMELINE) )
    {
        U64 elapse(0), now(0);
        CMilisecondTimer timer; CU64Array indices;

        for( ;; )
        {
            // 记录工作开始时间；
            timer.Record();
            now = CMilisecondTimer::Now();

            // 获取时间到期的对象；
			indices.clear();
            segment_2 -> Forward( now, indices );
            
            // 遍历对象，并调用维护接口；
            for( size_t i = 0, j = indices.size(); i < j; ++ i )
            {
                // 查询对象，如果对象存在，则继续；
                CObjectPtr object = segment_1 -> Obtain( indices[i] );
                if( object )
                {
                    // 如果存在接口，则调用接口，并重新放入时间线；
                    CInterface<IMaintainable> maintainbale;
                    if( maintainbale.Mount(object, IID_MAINTAINABLE) ) 
					{
						// 执行接口，并获取下一次唤醒的绝对时间，判断是否是INFINITE，
						// 如果不是，则再次放入时间线内；
						U64 next  = maintainbale -> OnMaintenance( now );
						if( next != U64(INFINITE) ) {
							segment_2 -> Mark( next, object -> GetName() );
						}
                    }
                }
            }

            // 如果需要终止循环，则终止；
            if( !active ) break;

            // 调用内存分配器的维护接口；
            CMemoryScheduler::GetInstance() -> Maintain();

            // 获取工作时间，并判断需要休眠多少毫秒
            elapse = timer.GetElapsedTime();
            if( elapse < 50 ) {
                CThread::Sleep( 50 - elapse );
            }
        }
    }
    return 0;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CMaintainerThread::OnBegin() 
{
    //TODO Auto-generated method stub
    SetActive( true );
    return Begin( TP_BELOW_NORMAL );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CMaintainerThread::OnClose() 
{
    //TODO Auto-generated method stub
    SetActive( false );
    Close( U64(INFINITE) );
    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CMaintainerThread::OnAwake()
{
    //TODO Auto-generated method stub
}
