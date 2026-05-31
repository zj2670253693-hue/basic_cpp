#include <filesystem>
#include <type_traits>
//
// Created by huawei on 2026/5/29.
//
// 实现一个顺序栈
#include<iostream>
using namespace std;
class MyStack {
public:
    // 初始化
    MyStack() {}
    MyStack(int size = 10) {
        cout << this << endl;
        _stack = new int[size];
        _top = -1;
        _size = size;
    }
    // 析构函数 自动的释放资源
    ~MyStack() {
        cout << this << endl;
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
    MyStack *_my_stack = new MyStack(20);
    _my_stack->push(1);
    _my_stack->push(2);
    _my_stack->push(3);
    _my_stack->pop();
    cout << _my_stack->get_top() << endl;
    delete _my_stack;
    // 先调用ps->~my_stack() 然后free(my_stack)

    MyStack my_stack(20);
    my_stack.push(10);
    my_stack.push(20);
    cout << my_stack.get_top() << endl;
    my_stack.pop();
    cout << my_stack.get_top() << endl;
    my_stack.pop();
    cout << my_stack.is_empty() << endl;
   // 释放成员变量占用的外部堆内存
    // cout << my_stack.get_top() << endl;
}