#include <cstring>
#include<iostream>
using namespace std;
// 内联函数: 在编译过程中，就没有函数的调用开销，在函数的调用点直接把函数的代码进行展开处理了
// inline函数不再生成相应的函数序号
// 不是所有的inline都会被编译器处理成内联函数 比如递归
// inline只是建议编译器把这个函数处理成内联函数
// 在debug版本上，inline 是不起作用的，inline只有在release版本下才能出现
// g++ -c main.cpp -02 objdump -t main.o
inline int sum(int a, int b) {
    return a + b;
}
//普通函数
// 此处有标准函数调用过程，参数压栈，函数栈帧的开辟和回退过程，有函数调用的开销
int sum_b(int a,int b) {
    return a + b;
}
/*
    函数重载
 c++为什么支持函数重载？为什么C语言不支持函数重载？
 编译器产生编译代码的规则是不一样的
    C++代码在产生函数符号的时候，函数名+参数列表类型组成的
    C代码产生函数符号的时候，函数名来决定
 函数重载需要注意什么？
 1. 所以在使用函数重载的时候，所有的重载函数要处在同一个作用域下
 C++和C语言代码之间如何互相调用
 什么是函数重载：
     1.一组函数，其中函数名相同，参数列表的个数或者类型不同，，那么这一组函数就是函数重载
     2.一组函数要称得上是重载，一定先处在同一个作用域下
     3. const或者volatile 修饰的参数，不能作为函数重载的参数
     4. 一组函数，函数名相同，参数列表也相同，仅仅是返回值不同，不叫函数重载
 */
bool compare(int a, int b) {
    cout <<"compare_int_int"<< endl;
    return a > b;
}
bool compare(double a, double b) {
    cout <<"compare_double_double"<< endl;
    return a > b;
}
bool compare(const char*a, const char* b) {
    cout <<"compare_string"<< endl;
    return strcmp(a,b);
}
// 所以对于编译器来说const int 其实和 int 是一样的，所以这里不构成函数重载
// void func(int a) {
//
// }
// void func(const int a) {
//
// }
int main() {
    int a = 10;
    const int b = 20;
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;

    bool compare(int a,int b); // 函数声明
    // 这里会飘红的原因是因为：在main函数局部已经声明了一个compare函数，并且这个函数的两个参数是int类型的，第二个compare调用compare函数的时候，调用刚才在main函数局部声明的这个函数
    // 不适用全局的compare函数，那么这里此时就会报警告，double转为int 会有数据损失
    // 在第三个函数调用compare函数的时候，因为参数是const char*类型是无法转成int类型的，所以这里就会报警告
    compare(10,20);
    //compare(10.0,20.0);
    //compare("zhou","jin");
    // int a, b;
    // cin >> a >> b;
    // cout << sum(a, b) << endl;
    return 0;
}