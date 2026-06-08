//
// Created by huawei on 2026/6/5.
//
#include <iostream>
int  gloabl_i = 10;
#include "global.h"
// using namespace std;
// 左值：可以被修改的值
// 右值： 不可以修改的值，比如函数返回值 字面量等
// 绑定带左值的引用叫做左值引用

// 绑定到右值的引用叫做右值引用
std::string foo() {
    return std::string("hello world");
}

int main() {



    // constexpr int num = 10;
    // constexpr int num2 = getSizeConst();
    int num = 10;
    constexpr int * p = nullptr;
    // 这里的相当于 int const *q = &gloabl_i;
    // 所以这里的q 不能指向别的地址，可以修改q指向的东西的值
    constexpr int * q = &gloabl_i;
    *q = 100;
    std::cout << num << std::endl;
    // 这里就相当于 const int *const r = &gloabl_i;
    constexpr const int * r = &gloabl_i;
    std::cout << *r << std::endl;


    // 一个constexptr 指针的初始化必须是一个nullptr，或者是 0 不能是一个普通指针，否则会报错
    // 或者存储于某个固定地址中的对象
    // constexpr int num2 = getSize();
}
//
// int main() {
//     int m =10;
//     // 左值引用
//     // int& m_r = m;
//     // 右值引用
//     int &&m_rr = 10;
//     // 这里使用右值引用接受foo()的返回值，因为在foo中已经创建出了一个string对象，如果不使用右值引用，那么就会进行拷贝构造
//     // 就会重新开辟一个新的空间，然后把原始对象拷贝进去，这里就涉及到两次对象的创建和析构，为了减小开销，所以这里使用右值引用
//     // 如果用右值引用，那么这里的str就是函数返回值的一个别名，在函数中值一次构造和析构对象
//     // 右值引用的引入主要是为了支持移动语义，它允许我们在对象被销毁前 窃取 其资源 而不是进行深拷贝，这样可以显著提高性能，特别是在处理
//     // 大型对象或容器时
//     std::string&& str = foo();
//     // std::cout << str << std::endl;
//     // // 不能用一个左值类型去绑定一个右值
//     // // Non-const lvalue reference 'M_r' to type int cannot bind to rvalue of type int
//     // // int &M_r = 10;
//     // int init = 42;
//     // int *pinit = nullptr;
//     // // 这里的pinit 其实就是一个指针(地址) 然后这里的rpinit表示的是这个指针的别名
//     // // 这修改了指针别名的指向，原本和pinit同时指向nullptr,现在rpinit = &init
//     // // 所以 指向了init的地址
//     // int *&rpinit = pinit;
//     // rpinit = &init;
//     // std::cout << pinit << std::endl;
//     // std::cout << &init << std::endl;
//     // std::cout << rpinit << std::endl;
//
//     return 0;
// }