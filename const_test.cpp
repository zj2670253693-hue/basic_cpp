//
// Created by huawei on 2026/5/29.
//
#include <iostream>
using namespace std;
// const 指针 引用 在函数中的引用
// const 怎样理解 C 和C++中const的区别
// const修饰的变量不能够再作为左值，初始化完成之后，值不能被修改
// 在出++中 b必须初始化，叫做常量

int main() {
    const int a = 10;
    int *p = (int *)&a;
    *p = 100;
    // 在clion中，编译器没有进行优化，所以这里*(&a) 也是100
    // 这里就相当于&a拿到了a的地址，然后通过地址获取到了a的值，所以*(&a) 也是100
    // 但是在vs上，编译器进行了优化，所以这里*(&a) 不是100，而是100
    printf("%d %d %d\n",a,*p,*(&a));
    return 0;
}