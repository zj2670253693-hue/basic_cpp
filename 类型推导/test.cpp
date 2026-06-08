//
// Created by huawei on 2026/6/8.
//
#include <iostream>
typedef double wages;
typedef wages base,*p;
typedef char * pstring;
using int64_t = long long;
#define base2 double;

int main() {
    wages w = 100.0;
    base wages2 = w;
    p wage_ptr = &w;
    int64_t num = 100;
    // 这里的str不是一个常量指针 不是 const char * 类型的，而是一个char * const类型的，它是一个指针常量
    const pstring str = "hello world";
    // char * const 类型实际上const修饰的是指针，而不是指针指向的内存空间
    // 所以指针的指向是不能修改的，但是指针指向的内存的内容是可以修改的
    //str++;
    // char * temp = "hello";
    // *str = *temp;
    // 表示的是一个 char * const * 类型
    // 这里表示的是指针 str2指向的是一个指针常量，其实就是指向了一个不能修改的地址
    const pstring * str2 = &str;
    // 得到str2指向的内存空间的地址
    std::cout << *str2 << std::endl;
    std::cout << **str2 << std::endl;
    int a = 10,b = 20;
    auto c = a + b;
    // 在cuto 中可以定义多个类型
    auto i = 0,*p = &i;
    // 但是在一条语句中不能定义多个类型的变量
    // auto j =0,pi = 3.14;
    {
        int  i = 0,&r = i;
        // 在类型推导中，如果遇到了引用类型，那么就使用引用类型指向的类型来推导变量的类型
        auto a = r;
        // auto 会忽略掉顶层的const
        char * str_s = "hello";
        char * const str = str_s;
        auto str2 = str;
        str2++;
        std::cout << str2 << std::endl;
    }
    {
        int i = 0,&r = i;
        auto a = r;
        // 这里的const相当于顶层const
        // 这里的cr 的类型是 const int & 类型
        const int ci = i,&cr = ci;
        auto b = ci;
        // 这里的cr是一个const int & 类型 在类型推导的时候会忽略掉顶层的const，并且cr指向的是一个int类型，推导得出int
        auto c = cr;
        auto d = &i;
        // 这里的const表示的是一个底层const
        auto e = &ci;
    }
    return 0;
}