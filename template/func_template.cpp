//
// Created by huawei on 2026/6/1.
//
#include <iostream>
#include "_test.h"
using namespace std;

// 模板代码是不能在一个文件中定义，在另外一个文件中使用的
// 模板代码调用之前，一定要看到模板定义的地方，这样的话，模板才能够进行正常的实例化，产生能够被编译器编译的代码
// 所以模板代码都要放到头文件中，然后在源文件中直接进行#include引入


// 模的定义： 对类型可以实现参数化
// 函数模板
// 模版的实例化
// 模板函数
// 模板类型参数
// 模板非类型参数
// 模板的实参推演 ： 可以根据用户传入的实参 自动的推演模板类型参数
// 模板的特例化
// 模板函数，模板的特例化，非模板函数的重载关系


// 函数模板 是不进行编译的，因为类型好不知道
// 模板的实例化 函数调用点进行实例化
// 模板函数 才是要被编译器所编译的
// template <typename T>
// void my_swap(T &a, T &b);
//
// template <typename T>
// void my_swap(T *a,T *b,int length);

// template <typename T>
// bool compare(T a, T b);


// bool compare(const char *str,const char *str2);
/**
 * 在函数调用点 编译器用用户指定的类型 从圆模板实例化一份函数代码出来
 * 模板函数
 * bool compare<int>(int a, int b) {
 *     return a>b;
 * }
 *
 * bool compare<const char*>(const char* a, const char* b) {
 *     return strcmp(a,b);
 * }
 * @return
 */
int main () {
    // 函数的调用点
    compare(10,20);
    // 编译器优先把compare处理成函数名字，没有的话，才去找compare模板
    compare("aaa","bbb");
    return 0;
}