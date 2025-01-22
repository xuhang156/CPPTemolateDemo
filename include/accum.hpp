#pragma once
#include "accumtraits.hpp"
#include "sumpolicy.hpp"

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

template<typename T, typename Policy = SumPolicy, typename AT = AccumTraits<T>>
class Accum
{
    public:
    static typename AT::AccT accum(T const* beg, T const* end)
    {
        //这样设计虽然能够使用代理，但是对于不同的代理，使用AT::zero()可能会不对
        //例如求积的代理初始化为0则出错
        //不同的代理会手机用不同的trait
        typename AT::AccT total = AT::zero();
        while (beg != end)
        {
            Policy::accumulate(total, *beg);
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