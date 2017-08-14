#include "CInstanceLifeController.h"
#include "../factory/CInstanceFactory.h"
#include "../../utility/tool/CInterface.h"
#include "../../interface/IInstanceLifeReference.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CInstanceLifeController.cpp
//TODO: Add definitions that you want preserved
//End section for file CInstanceLifeController.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CInstanceLifeController::CInstanceLifeController() : 
nest(NULL)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CInstanceLifeController::~CInstanceLifeController() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CInstanceLifeController::IncRef() 
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
int atom::CInstanceLifeController::DecRef() 
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
int atom::CInstanceLifeController::GetRef() 
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
atom::IInterface * atom::CInstanceLifeController::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CInstanceLifeController::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) nest = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CInstanceLifeController::Create(U32 type) 
{
    //TODO Auto-generated method stub
	U64 result = 0;
	if( type )
	{
        CInterface<IInstanceLifeReference> segment;
		if( segment.Mount(this, IID_INSTANCE_LIFE_REFERENCE) )
        {
    	    result = CInstanceFactory::GetInstance() -> Product( type );
    	    if( result )
    	    {
                // ����ɹ��������Ƴ�ʱ������ע��ö���
                if( segment -> Insert(result) ) {
					Remove( result, 120000 );
                }

                // ���ʧ�ܣ�������ʵ����
                else
				{
                    CInstanceFactory::GetInstance() -> Destroy( result );
					result = 0;
                }
            }
    	}
	}
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstanceLifeController::Remove(U64 instance, U64 time) 
{
    //TODO Auto-generated method stub
	if( instance ) {
		remove.Insert( CMilisecondTimer::Now() + time, instance );
	}
	return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstanceLifeController::Remove(CU64Array & instances, U64 time) 
{
    //TODO Auto-generated method stub
	for( size_t i = 0, j = instances.size(); i < j; ++ i ) {
		Remove( instances[i], time );
	}
    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CInstanceLifeController::Delete(U64 instance) 
{
    //TODO Auto-generated method stub
    if( instance )
    {
		// �Ƴ�ʵ��
        CInterface<IInstanceLifeReference> segment;
		if( segment.Mount(this, IID_INSTANCE_LIFE_REFERENCE) )
        {
            // �������Ϊ0����ע��ʵ������ɾ�������ü�����
            if( segment -> Remove(instance) )
            {
                // ֪ͨ����ɾ��ʵ����
				CInstanceFactory::GetInstance() -> Destroy( instance );
            }
        }
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CInstanceLifeController::Delete(CU64Array & instances) 
{
    //TODO Auto-generated method stub
    CInterface<IInstanceLifeReference> segment;
	if( segment.Mount(this, IID_INSTANCE_LIFE_REFERENCE) )
    {
        // �������Ϊ0����ע��ʵ������ɾ�������ü�����
		for( size_t i = 0, j = instances.size(); i < j; ++ i )
		{
			// ����Ƴ��ɹ�����֪ͨ����ɾ��ʵ����
			if( segment -> Remove(instances[i]) ) {
				CInstanceFactory::GetInstance() -> Destroy( instances[i] );
			}
		}
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CInstanceLifeController::OnProcess(U64 time) 
{
    //TODO Auto-generated method stub
	CU64Array indices;
	remove.Obtain( time, indices );
	if( !indices.empty() ) Delete( indices );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstanceLifeController::Initiate() 
{
    //TODO Auto-generated method stub
	return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstanceLifeController::Shutdown() 
{
    //TODO Auto-generated method stub
	remove.Clear();
	return true;
}
