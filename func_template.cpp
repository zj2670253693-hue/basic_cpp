//
// Created by huawei on 2026/6/2.
//
#include <iostream>
using namespace std;
// 使用类模板实现一个顺序栈
template <typename T>
class SeqStack{
private:
    int _top;
    int _size;
    T *_pStack;
    // 顺序栈进行扩容,按照原来的两倍进行扩容
    void expand() {
        T *temp = new T[_size * 2];
        for (int i = 0;i< _top;i++) {
            temp[i] = _pStack[i];
        }
        delete[] _pStack;
        _pStack = nullptr;
    }
public:
    // 默认构造,对成员变量进行初始化
    SeqStack(int size = 10): _top(-1), _size(size), _pStack(new T[_size]){}
    // 拷贝构造 防止共用一块内存空间
    SeqStack(const SeqStack<T> &s):_top(s._top), _size(s._size) {
        T *temp = new T[_size];
        for (int i = 0; i < _size; i++) {
            temp[i] = s._pStack[i];
        }
    }
    // 赋值重载
    SeqStack<T> &operator=(const SeqStack<T> &s) {
        if (this != &s) {
            delete[] _pStack;
        }

    }
    void push(T val) {
        if (full()) {
            expand(); // 扩容
            _pStack[++_top] = val;
        }

    }
    void pop() {

    }
    T getTop() {

    }
    bool empty() {

    }
    bool full() {

    }
    ~SeqStack() {
        delete[] _pStack;
        _pStack = nullptr;
    }
};
int main(){
    SeqStack<int> s;
    s.push(1);
    s.push(2);
    SeqStack s2 = s;
    return 0;
}