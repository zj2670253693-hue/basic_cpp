#include <filesystem>
#include <type_traits>
//
// Created by huawei on 2026/5/29.
//
// 实现一个顺序栈
#include <cstring>
#include<iostream>
using namespace std;
// 循环队列
class Queue {
    
};
class String {
public:
    // 普通构造
    String(const char *str = nullptr) {
        cout << this <<"common String(const String &str)" << endl;
        if (str != nullptr) {
            m_data = new char[strlen(str) + 1];
            strcpy(m_data, str);
        }else {
            m_data = new char[1];
            *m_data = '\0';
        }
    }
    // 拷贝构造
    String(const String &str) {
        cout << this <<"String(const String &str)" << endl;
        m_data = new char[strlen(str.m_data) + 1];
        strcpy(m_data, str.m_data);
    }
    ~String() {
        cout << this <<"~String" <<  endl;
        delete [] m_data;
        m_data = nullptr;
    }
    // 赋值重载
    String &operator=(const String &str) {
        cout << this <<"operator=(const String &str)" << endl;
        if (this == &str) {
            return *this;
        }
        delete [] m_data;
        m_data = new char[strlen(str.m_data) + 1];
        strcpy(m_data, str.m_data);
        return *this;
    }

private:
    char *m_data;
};
/**
 * 对象的深拷贝和浅拷贝
 * this指针 ---> 类 ---> 很多对象 ----> 共享一套成员方法
 * 成员方法，方法的参数都会添加一个this指针
 * .data对象 程序启动时构造 程序结束时析构
 * heap new的时候构造，delete的时候析构
 * stack
 */
class MyStack {
public:
    // 初始化
    MyStack() {
        cout << this <<"_stack" <<  endl;
    }
    MyStack(int size = 10) {
        cout << this <<"_stack" <<  endl;
        _stack = new int[size];
        _top = -1;
        _size = size;
    }
    // 自定义拷贝构造函数 对象的浅拷贝现在出现了问题
    MyStack(const MyStack &src) {
        cout << this <<" const MyStack &src" <<  endl;
        _stack = new int[src._size];
        for (int i = 0; i < src._size; i++) {
            _stack[i] = src._stack[i];
        }
        _top = src._top;
        _size = src._size;
    }
    // 运算符重载
    void operator=(const MyStack &src) {
        // 需要先释放当前对象占用的外部资源
        if (this == &src) {
            return;
        }
        delete [] _stack;
        cout << this <<"coperator" <<  endl;
        _stack = new int[src._size];
        for (int i = 0; i < src._size; i++) {
            _stack[i] = src._stack[i];
        }
        _top = src._top;
        _size = src._size;
    }
    // 析构函数 自动的释放资源
    ~MyStack() {
        cout << this << "~_stack" <<  endl;
        delete [] _stack;
        _stack = nullptr;
    }
    void push(int x) {
        if (is_full()) {
            resize();
        }
        _stack[++_top] = x;
    }
    bool pop() {
        if (is_empty()) {
            return false;
        }else {
            --_top;
            return true;
        }
    }
    bool is_empty() {
        return _top == -1;
    }
    //得到栈顶元素
    int get_top() {
        return _stack[_top];
    }
    // 判断栈是否溢出
    bool is_full() {
        return _top  == _size -1;
    }
    // 判断栈是否为空
private:
    int *_stack;
    int _top;
    int _size;
    void resize() {
        int *temp = new int[_size *2];
        for (int i = 0; i < _size; i++) {
            temp[i] = _stack[i];
        }
        delete [] _stack;
        _stack = temp;
    }
};

int main() {
    // 构造函数：定义对象时，自动调用的，可以重载，构造完成，对象产生了
    // 析构函数：不带参数，不能重载，只有一个析构函数，析构完成，对象就不存在了
    // MyStack *_my_stack = new MyStack(20); // malloc 内存开辟 +my_stack()对象构造
    // _my_stack->push(1);
    // _my_stack->push(2);
    // _my_stack->push(3);
    // _my_stack->pop();
    // cout << _my_stack->get_top() << endl;
    // delete _my_stack;
    // // 先调用ps->~my_stack() 然后free(my_stack)
    //
    // MyStack my_stack(20);
    // my_stack.push(10);
    // my_stack.push(20);
    // cout << my_stack.get_top() << endl;
    // my_stack.pop();
    // cout << my_stack.get_top() << endl;
    // my_stack.pop();
    // cout << my_stack.is_empty() << endl;
   // 释放成员变量占用的外部堆内存
    // cout << my_stack.get_top() << endl;
    // 在没有提供任何构造函数的时候，会生成默认的构造和析构函数
    // MyStack my_stack1(20);
    // MyStack my_stack2 = my_stack1; // 浅拷贝 调用了拷贝构造函数 做的是内存的拷贝
    // // 对象如果占用外部资源，那么此时浅拷贝就出现问题了
    // my_stack2 = my_stack1; // 做直接的内存拷贝
    String str1;
    String str2("hi");
    String str3 = "hi";
    String str4 = str3; // 调用拷贝构造
    str1 = str2;
}