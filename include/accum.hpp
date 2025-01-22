#pragma once
#include <iostream>
#include "accumtraits.hpp"

template <typename T>
inline typename AccumTraits<T>::AccT accum(T const* beg, T const* end)
{
    typedef typename AccumTraits<T>::AccT AccT;
    //问题：无法保证AccT()能够初始化为想要的值
    // AccT未必具有默认构造函数
    AccT total = AccT();
    while (beg != end)
    {
        total += *beg;
        ++beg;
    }
    return total;
}

template <typename T>
inline typename AccumTraits<T>::AccT accumUseZero(T const* beg, T const* end)
{
    typedef typename AccumTraits<T>::AccT AccT;
    AccT total = AccumTraits<T>::zero();
    while (beg != end)
    {
        total += *beg;
        ++beg;
    }
    return total;
}

template<typename T, typename AT = AccumTraits<T>>
class Accum
{
    public:
    static typename AT::AccT accum(T const* beg, T const* end)
    {
        typename AT::AccT total = AT::zero();
        while (beg != end)
        {
            total += *beg;
            ++beg;
        }
        return total;
    }
};

//引入辅助函数简化上面基于类的接口使用
template<typename T>
inline typename AccumTraits<T>::AccT accumUseClass(T const* beg, T const* end)
{
    return Accum<T>::accum(beg, end);
}

template<typename Traits,typename T>
inline typename Traits::AccT accumUseClass(T const* beg, T const* end)
{
    return Accum<T, Traits>::accum(beg, end);
}

void accumTest()
{
    int a[] = {1, 2, 3, 4, 5};
    float b[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char  c[] = {"templates"};
    double d[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::cout << accum(a, a + 5) << std::endl;
    std::cout << accum(b, b + 5) << std::endl;
    std::cout << accum(c, c + sizeof(c) - 1) << std::endl;

    std::cout << accumUseClass(c, c + sizeof(c) - 1) << std::endl;
    //如果没有特化double类型，则会在编译期报错
    // std::cout << accumUseZero(d, d + 5) << std::endl;
}