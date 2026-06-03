//
// Created by huawei on 2026/6/3.
//
#include<iostream>
using namespace std;
template <class T>
class Allocator {
public:
    // size_t 类型表示的是 无符号整数类型
    T* allocate(size_t size) {
        return (T*)malloc(size * sizeof(T));
    }
    void deallocate(T* p) {
        free(p);
    }
    // 对象构造
    void construct(T* p, const T& val) {
        new(p) T(val); // 定位 new
    }
    // 对象析构
    void destroy(T* p) {
        p->~T();
    }
};
template<typename T,typename Alloc = Allocator<T> >
// 空间配置器
// 容器的空间配置器
// 内存开辟，释放 对象 构造 析构

class vector {
private:
    T *_first; // 表示的是数组第一个元素的位置指针
    T *_last; // 表示的是数组有效位置的后一个位置的指针
    T *_end; // 表示的是数组全部位数的下一个位置的指针
    Alloc _alloc; // 定义容器的的空间配置器对象
    void expand() {
        // 扩容两倍
        int size = _last - _first;
        // T *new_first = new T[2 * size];
        // 开辟内存
        T *new_first = _alloc.allocate(size * 2);
        for (int i = 0;i < size;i++) {
            _alloc.construct(new_first + i, _first[i]);
            // new_first[i] = _first[i];
        }
        // delete _first;
        // 析构有效对象
        for (T *p = _first; p != _last; p++) {
            _alloc.destroy(p);
        }
        // 内存释放
        _alloc.deallocate(_first);
        _first = new_first;
        _last = _first + size;
        _end = _first + 2 *size;
    }
public:
    vector(int size = 10) {
        // 这里只实现了开辟空间，没有实现构造，就是new出一个对象，只是创建出了内存，在内存中没有创建对象
        _first = _alloc.allocate(size);
        _last = _first;
        _end = _first+size;
    }
    // 拷贝构造
    vector(const vector <T> &v) {
        // 原始内存空间大小
        int size = v._end - v._first;
        _first = _alloc.allocate(size);
        int length = v._last - v._first;
        for (int i = 0; i < length; i++) {
            // 构造对象
            _alloc.construct(_first + i, v._first[i]);
        }
        _last = _first + length;
        _end = _first + size;
    }
    // 赋值重载
    vector<T> &operator=(const vector<T> &v) {
        if (this != &v) {
            return *this;
        }
        //delete[] _first;
        // 把当前容器有效的对象析构掉
        for (T *p = _first; p != _last; p++) {
            _alloc.destroy(p);
        }
        _alloc.deallocate(_first);
        int size = v._end - v._first;
        _first = _alloc.allocate(size);
        int length = v._last - v._first;
        for (int i = 0; i < length; i++) {
            // _first[i] = v._first[i];
            _alloc.construct(_first + i, v._first[i]);
        }
        _last = _first + length;
        _end = _first + size;
        return *this;
    }
    ~vector() {
        // delete[] _first;
        // 释放有效元素
        for (T *p = _first; p != _last; p++) {
            _alloc.destroy(p);
        }
        //释放整个内存
        _alloc.deallocate(_first);
        _first = _last = _end = nullptr;
    }
    // 向容器末尾添加元素
    void push_back(const T &val) {
        if (full()) {
            expand();
        }
        _alloc.construct(_last, val);
        _last++;
    }
    // 删除容器中末尾参数
    void pop_back() {
        if (empty()) {
            return;
        }
        --_last;
        _alloc.destroy(_last);
    }
    // 返回容器末尾元素值
    T back() const {
        return *(_last - 1);
    }
    bool empty() const {
        return _first == _last;
    }
    bool full() const {
        return _last == _end;
    }
    int size() const {
        return _last - _first;
    }
};
class Test {
public:
    Test() {
        cout << "test()" << endl;
    }
    // 拷贝构造
    Test(const Test &t) {
        cout << "const test()" << endl;
    }
    ~Test() {
        cout << "~test()" << endl;
    }
};
int main() {
    Test t1,t2,t3;
    cout << "---------------------------------"<< endl;
    vector<Test> vec;
    vec.push_back(t1);
    vec.push_back(t2);
    vec.push_back(t3);
    cout << "----------------------------------"<< endl;
    vec.pop_back(); // 只析构对象
    cout << "-----------------------------------"<< endl;
    return 0;
}