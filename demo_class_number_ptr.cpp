//
// Created by huawei on 2026/6/1.
//
#include <iostream>
using namespace std;
class Test {
public:
    void func() {
        cout << "call Test::func" << endl;
    }
    static void static_func() {
        cout << "Test::static_func()" << endl;
    }
    int ma;
    static int mb;
};
int Test::mb;
int main() {
    // 使用普通的指针指向成员变量
    //int *q = &Test::ma; // 无法从 int Test::转化为int
    //int Test::*q = &Test::ma; // 这里脱离了对象
    Test test; // 在栈上创建一个对象 test
    Test *new_test = new Test();// 在堆上创建一个对象 new_test
    int Test::*p = & Test::ma;
    // 指向成员函数的指针
    void (Test::*pfunc)() = &Test::func;
    (test.*pfunc)();
    (new_test->*pfunc)();


    //定义函数指针指向类的静态成员函数
    void (*pstatic_func)() = &Test::static_func;
    pstatic_func();

    test.*p = 100;
    cout << "test.ma " << test.ma << endl;
    cout << "test.*p " << test.*p << endl;


    new_test->*p = 20;
    cout << "new_test->ma " << new_test->ma << endl;
    cout << "new_test->*p " << new_test->*p << endl;
    int *ptr = &Test::mb;
    *ptr = 100;
    cout << "Test::mb " << Test::mb << endl;
    cout << "*ptr " << *ptr << endl;
    delete new_test;
    return 0;
}