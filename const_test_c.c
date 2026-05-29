//
// Created by huawei on 2026/5/29.
//
#include<stdio.h>
// 在C语言中 const修饰的变量，可以不进行初始化 默认为0
// 但是如果在想给const修饰的变量赋值，那么赋值是不成功的
// 所以在C 语言中 const修饰的量，不叫做常量，叫做常变量
int main() {
    const int a = 20;
    // 这里指针p 指向的是常量a 的地址
    int *p = &a;
    //int *p = ((int*)&a);
    *p = 100;
    printf("%d %d %d\n",a,*p,*(&a));
    return 0;
}
