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
    //const int a = 10;
    // int *p = (int *)&a;
    //*p = 100;
    // 在clion中，编译器没有进行优化，所以这里*(&a) 也是100
    // 这里就相当于&a拿到了a的地址，然后通过地址获取到了a的值，所以*(&a) 也是100
    // 但是在vs上，编译器进行了优化，所以这里*(&a) 不是100，而是100
    //printf("%d %d %d\n",a,*p,*(&a));
    //int num = 20;
    //const int *ptr = &num;
    // 把限制大的转换成限制小的是不行的，只能把 限制小的转化为限制大的
    // 只能把 const int* <= int *
    // 在这里是把 int * <= const int * 不能把整型常量的地址给到普通指针
    // int *_ptr = ptr;
    int c = 20;
      // 这样p就是一个常量指针，并且常量指针指向的东西也不能修改
    // &p 表示的是 const int *const*
    const int *p = &c;
    const int*const* ptr = &p;
    // 此时的const修饰的是 *ptr
    cout << **ptr << endl;
    // 相当于 const int ** <= int **，但是这是不成立的
    // 二级指针 ptr 的 一级解引用 *ptr 和 p指向的是同一块内存空间
    // 那么此时的 *ptr就是一个整型常量地址，然而这个整型常量地址又指向了普通指针p，所以这里是错误的
    // ptr是一个指针，指向一个const指针，这个const指针指向了const int
    return 0;
}