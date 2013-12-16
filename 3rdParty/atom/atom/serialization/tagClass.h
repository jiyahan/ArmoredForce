#ifndef TAGCLASS_H
#define TAGCLASS_H
//Begin section for file tagClass.h
//TODO: Add definitions that you want preserved
//End section for file tagClass.h



// 为序列化类而特别准备的缺省模板函数。
template<class A, class T>
inline void Serialize(A& ar, T& t, bool save)
{
	t.Serialize( ar, save );
}

namespace atom
{

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_gQx30KxjEdyG2OUyJIn0qA"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <class A, class T, bool save>
	struct tagClass
	{
	
	    //Begin section for si::tagClass
	    //TODO: Add attributes that you want preserved
	    //End section for si::tagClass
	    public:
	
	        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	        inline static void Invoke(A & ar, T & t)
	        {
	        	//TODO Auto-generated method stub
	        	Serialize( ar, t, save );
	        }
	
	};  //end struct tagClass
	
} // end namespace atom

#endif
