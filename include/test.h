#include <iostream>
#include "accum.hpp"

//测试使用特征
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

// 测试使用代理
void testPolicy() {
    int a[]   = {1, 2, 3, 4, 5};
    std::cout<<"The product of the integer values is "<< Accum<int,MultPolicy>::accum(a,a + 5)<<std::endl;
    std::cout<<"The product of the integer values is "<< Accum<int>::accum(a,a + 5)<<std::endl;
}