#ifndef COMMON_CONFIG_H
#define COMMON_CONFIG_H

//
// 使用宏来区分开Server和Client对string类的使用
//
// 缘由: 1, 不同的STL版本对std::string实现不同，同一个优化方案不一定适用所有平台
//          Visual C++          SSO (短字符串优化)
//          g++ string          COW (Copy on Write)
//          Clang libc++        SSO
//          SGI STL             eager copy(直接拷贝，类似vector的方式)
//
//       2，Server端代码在内存管理的策略上更倾向于，避免提前优化，在前期使用RAII、
//          智能指针、ScopeGuard等技巧来完善内存(和其他资源)的分配和释放。
//          后期再考虑是否引入第三方的内存优化方案(boost.pool，tcmalloc, jemalloc)，
//          或者Visual C++官方提供的分配器(allocator.h)：
//              allocator_unbounded
//              allocator_fixed_size
//              allocator_variable_size
//              allocator_suballoc
//              allocator_chunklist
//          @see http://msdn.microsoft.com/en-us/library/ee292134(v=vs.110).aspx
//
//      3，减少Server端代码对atom库的依赖
//

#ifdef NOT_USE_ATOM_ALLOCATOR
typedef std::string     String;
#else
typedef atom::a_string  String;
#endif

#endif // COMMON_CONFIG_H
