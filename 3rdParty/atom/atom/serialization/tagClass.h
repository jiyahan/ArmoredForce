#ifndef TAGCLASS_H
#define TAGCLASS_H



// Ϊ���л�����ر�׼����ȱʡģ�庯����
template<class A, class T>
inline void Serialize(A& ar, T& t, bool save)
{
	t.Serialize( ar, save );
}

namespace atom
{

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_gQx30KxjEdyG2OUyJIn0qA"
	template <class A, class T, bool save>
	struct tagClass
	{
	
	    public:
	
	        inline static void Invoke(A & ar, T & t)
	        {
	        	Serialize( ar, t, save );
	        }
	
	};  //end struct tagClass
	
} // end namespace atom

#endif
