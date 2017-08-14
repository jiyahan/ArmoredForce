#ifndef COMMON_CONFIG_H
#define COMMON_CONFIG_H

//
// ʹ�ú������ֿ�Server��Client��string���ʹ��
//
// Ե��: 1, ��ͬ��STL�汾��std::stringʵ�ֲ�ͬ��ͬһ���Ż�������һ����������ƽ̨
//          Visual C++          SSO (���ַ����Ż�)
//          g++ string          COW (Copy on Write)
//          Clang libc++        SSO
//          SGI STL             eager copy(ֱ�ӿ���������vector�ķ�ʽ)
//
//       2��Server�˴������ڴ����Ĳ����ϸ������ڣ�������ǰ�Ż�����ǰ��ʹ��RAII��
//          ����ָ�롢ScopeGuard�ȼ����������ڴ�(��������Դ)�ķ�����ͷš�
//          �����ٿ����Ƿ�������������ڴ��Ż�����(boost.pool��tcmalloc, jemalloc)��
//          ����Visual C++�ٷ��ṩ�ķ�����(allocator.h)��
//              allocator_unbounded
//              allocator_fixed_size
//              allocator_variable_size
//              allocator_suballoc
//              allocator_chunklist
//          @see http://msdn.microsoft.com/en-us/library/ee292134(v=vs.110).aspx
//
//      3������Server�˴����atom�������
//

#ifdef NOT_USE_ATOM_ALLOCATOR
typedef std::string     String;
#else
typedef atom::a_string  String;
#endif

#endif // COMMON_CONFIG_H
