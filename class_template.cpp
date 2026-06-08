// //
// // Created by huawei on 2026/6/3.
// //
// #include<iostream>
// using namespace std;
// template <class T>
// class  Allocator {
// public:
//     // size_t 类型表示的是 无符号整数类型
//     T* allocate(size_t size) {
//         return (T*)malloc(size * sizeof(T));
//     }
//     void deallocate(T* p) {
//         free(p);
//     }
//     // 对象构造
//     void construct(T* p, const T& val) {
//         new(p) T(val); // 定位 new
//     }
//     // 对象析构
//     void destroy(T* p) {
//         p->~T();
//     }
// };
// // 空间配置器
// // 容器的空间配置器
// // 内存开辟，释放 对象 构造 析构
// template<typename T,typename Alloc = Allocator<T>>
// class vector {
// private:
//     T *_first; // 表示的是数组第一个元素的位置指针
//     T *_last; // 表示的是数组有效位置的后一个位置的指针
//     T *_end; // 表示的是数组全部位数的下一个位置的指针
//     Alloc _alloc; // 定义容器的的空间配置器对象
//
//     // 容器迭代器失效增添代码
//     struct Iterator_Base {
//         Iterator_Base(iterator *c = nullptr,Iterator_Base *n = nullptr):_cur(c),_next(n) {}
//         iterator *_cur;
//         Iterator_Base *_next;
//     };
//     Iterator_Base *_head;
//
//     void expand() {
//         // 扩容两倍
//         int size = _last - _first;
//         // T *new_first = new T[2 * size];
//         // 开辟内存
//         T *new_first = _alloc.allocate(size * 2);
//         for (int i = 0;i < size;i++) {
//             _alloc.construct(new_first + i, _first[i]);
//             // new_first[i] = _first[i];
//         }
//         // delete _first;
//         // 析构有效对象
//         for (T *p = _first; p != _last; p++) {
//             _alloc.destroy(p);
//         }
//         // 内存释放
//         _alloc.deallocate(_first);
//         _first = new_first;
//         _last = _first + size;
//         _end = _first + 2 *size;
//     }
// public:
//     vector(int size = 10) {
//         // 这里只实现了开辟空间，没有实现构造，就是new出一个对象，只是创建出了内存，在内存中没有创建对象
//         _first = _alloc.allocate(size);
//         _last = _first;
//         _end = _first+size;
//     }
//     // 拷贝构造
//     vector(const vector <T> &v) {
//         // 原始内存空间大小
//         int size = v._end - v._first;
//         _first = _alloc.allocate(size);
//         int length = v._last - v._first;
//         for (int i = 0; i < length; i++) {
//             // 构造对象
//             _alloc.construct(_first + i, v._first[i]);
//         }
//         _last = _first + length;
//         _end = _first + size;
//     }
//     // 赋值重载
//     vector<T> &operator=(const vector<T> &v) {
//         if (this != &v) {
//             return *this;
//         }
//         //delete[] _first;
//         // 把当前容器有效的对象析构掉
//         for (T *p = _first; p != _last; p++) {
//             _alloc.destroy(p);
//         }
//         _alloc.deallocate(_first);
//         int size = v._end - v._first;
//         _first = _alloc.allocate(size);
//         int length = v._last - v._first;
//         for (int i = 0; i < length; i++) {
//             // _first[i] = v._first[i];
//             _alloc.construct(_first + i, v._first[i]);
//         }
//         _last = _first + length;
//         _end = _first + size;
//         return *this;
//     }
//     ~vector() {
//         // delete[] _first;
//         // 释放有效元素
//         for (T *p = _first; p != _last; p++) {
//             _alloc.destroy(p);
//         }
//         //释放整个内存
//         _alloc.deallocate(_first);
//         _first = _last = _end = nullptr;
//     }
//     // 向容器末尾添加元素
//     void push_back(const T &val) {
//         if (full()) {
//             expand();
//         }
//         _alloc.construct(_last, val);
//         _last++;
//     }
//     // 删除容器中末尾参数
//     void pop_back() {
//         if (empty()) {
//             return;
//         }
//         --_last;
//         _alloc.destroy(_last);
//     }
//     // 返回容器末尾元素值
//     T back() const {
//         return *(_last - 1);
//     }
//     bool empty() const {
//         return _first == _last;
//     }
//     bool full() const {
//         return _last == _end;
//     }
//     int size() const {
//         return _last - _first;
//     }
//     T& operator[](int i){
//         if (i < 0 || i >= size()) {
//             throw "index out of range error";
//         }
//         return _first[i];
//     }
//     // 迭代器一般实现成容器的嵌套类型
//     class iterator {
//     public:
//         friend class vector<T,Alloc>;
//         iterator(vector<T,Alloc> *_pvec= nullptr,T *ptr = nullptr)
//         :_ptr(ptr),_pVec(_pvec) {
//             //this 新生成当前容器某一个位置元素的的迭代器
//             Iterator_Base *itb = new Iterator_Base(this,_pVec->_head->_next);
//             _pVec->_head->_next = itb;
//         }
//         bool operator!=(const iterator &it) const {
//             // 使用在一个容器中的迭代器(指针)才可以比较，不同容器中的迭代器是比较不了的
//             // 检查迭代器都有效性
//             if (_pVec == nullptr || _pVec != it._pVec) {
//                 throw "iterator not compatible";
//                 return false;
//             }
//             return _ptr != it._ptr;
//         }
//          T& operator*(){
//             if (_pVec == nullptr) {
//                 throw "iterator not compatible";
//             }
//             return *_ptr;
//         }
//         const T& operator*() const {
//             return *_ptr;
//         }
//         // 前置++
//         void operator++() {
//             if (_pVec == nullptr) {
//                 throw "iterator not compatible";
//             }
//             _ptr++;
//         }
//         // 不同容器的迭代器是不能进行比较运算的
//     private:
//         T *_ptr;
//         // 当前迭代器是哪个容器的迭代器
//         // 这里的_pVec指向的是这个容器的内存，就说说一个容器一个地址，这里定义一个这个就是为了，让不同的容器的迭代器比较不了
//         vector<T,Alloc> *_pVec;
//     };
//     iterator begin() {return iterator(this,_first);}
//     iterator end() {return iterator(this,_last);}
//     // 检查迭代器失效
//     void verify(T *first,T *last) {
//         Iterator_Base *pre = &this->_head;
//         Iterator_Base *it = this->_head->_next;
//         while (it != nullptr) {
//             if (it->_cur->_ptr >= first && it->_cur->_ptr <= last) {
//                 // 迭代器失效，把iterator持有的容器指针值为nullptr
//                 it->_cur->_pVec = nullptr;
//                 // 删除当前迭代器节点，继续判断后面的迭代器节点是否有效
//                 pre->next = it->_next;
//                 delete it;
//                 it = pre->next;
//             }else {
//                 pre = it;
//                 it = it->next;
//             }
//         }
//     }
// };
// class Test {
// public:
//     Test() {
//         cout << "test()" << endl;
//     }
//     // 拷贝构造
//     Test(const Test &t) {
//         cout << "const test()" << endl;
//     }
//     ~Test() {
//         cout << "~test()" << endl;
//     }
// };
// int main() {
//     // Test t1,t2,t3;
//     // cout << "---------------------------------"<< endl;
//     // vector<Test> vec;
//     // vec.push_back(t1);
//     // vec.push_back(t2);
//     // vec.push_back(t3);
//     // cout << "----------------------------------"<< endl;
//     // vec.pop_back(); // 只析构对象
//     // cout << "-----------------------------------"<< endl;
//     vector<int> vec;
//     for (int i = 0;i < 20;i++) {
//         vec.push_back(i);
//     }
//     vector<int>::iterator it = vec.begin();
//     for (;it != vec.end(); ++it) {
//         cout << *it << endl;
//     }
//     int size = vec.size();
//     for (int i = 0;i < size;i++) {
//         cout << vec[i] << endl;
//     }
//     cout << vec[10] << endl; //O(1) 内存是连续的
//     return 0;
// }



#include <iostream>
using namespace std;

template <class T>
class Allocator {
public:
    T* allocate(size_t size) {
        return (T*)malloc(size * sizeof(T));
    }
    void deallocate(T* p) {
        free(p);
    }
    void construct(T* p, const T& val) {
        new(p) T(val);
    }
    void destroy(T* p) {
        p->~T();
    }
};

template<typename T, typename Alloc = Allocator<T>>
class vector {
public:
    // 定义在前面，方便 iterator 使用
    class iterator;

private:
    T *_first;
    T *_last;
    T *_end;
    Alloc _alloc;

    // 迭代器追踪节点
    struct Iterator_Base {
        Iterator_Base(iterator *c = nullptr, Iterator_Base *n = nullptr)
            : _cur(c), _next(n) {}
        iterator *_cur;
        Iterator_Base *_next;
    };
    Iterator_Base *_head; // 考勤表头

public:
    // 迭代器类定义
    class iterator {
    public:
        friend class vector<T, Alloc>;

        iterator(vector<T, Alloc> *_pvec = nullptr, T *ptr = nullptr)
            : _ptr(ptr), _pVec(_pvec) {
            // 如果关联了容器，就注册到容器的链表中
            if (_pVec != nullptr) {
                Iterator_Base *itb = new Iterator_Base(this, _pVec->_head->_next);
                _pVec->_head->_next = itb;
            }
        }

        // <--- 修改点：增加析构函数，当迭代器销毁时，从容器链表中摘除
        ~iterator() {
            if (_pVec != nullptr && _pVec->_head != nullptr) {
                Iterator_Base *pre = _pVec->_head;
                Iterator_Base *it = _pVec->_head->_next;
                while (it != nullptr) {
                    if (it->_cur == this) {
                        pre->_next = it->_next;
                        delete it;
                        break;
                    }
                    pre = it;
                    it = it->_next;
                }
            }
        }

        bool operator!=(const iterator &it) const {
            if (_pVec == nullptr || _pVec != it._pVec) {
                throw "iterator incompatibility!";
            }
            return _ptr != it._ptr;
        }

        T& operator*() {
            if (_pVec == nullptr) { // <--- 检查是否失效
                throw "iterator invalid! (after expand or erase)";
            }
            return *_ptr;
        }

        void operator++() {
            if (_pVec == nullptr) {
                throw "iterator invalid!";
            }
            _ptr++;
        }

    private:
        T *_ptr;
        vector<T, Alloc> *_pVec;
    };

    // vector 方法实现
    vector(int size = 10) {
        _first = _alloc.allocate(size);
        _last = _first;
        _end = _first + size;
        _head = new Iterator_Base(); // <--- 修改点：初始化哨兵节点
    }

    ~vector() {
        for (T *p = _first; p != _last; p++) {
            _alloc.destroy(p);
        }
        _alloc.deallocate(_first);

        // 清理链表节点
        Iterator_Base *it = _head;
        while(it != nullptr) {
            Iterator_Base *tmp = it;
            it = it->_next;
            if(tmp->_cur) tmp->_cur->_pVec = nullptr; // 通知还活着的迭代器容器没了
            delete tmp;
        }
        _first = _last = _end = nullptr;
    }

    void expand() {
        int size = _last - _first;
        T *new_first = _alloc.allocate(size * 2);
        for (int i = 0; i < size; i++) {
            _alloc.construct(new_first + i, _first[i]);
        }

        // <--- 修改点：释放前检查所有迭代器，指向这块区域的全部标记失效
        verify(_first, _last);

        for (T *p = _first; p != _last; p++) {
            _alloc.destroy(p);
        }
        _alloc.deallocate(_first);

        _first = new_first;
        _last = _first + size;
        _end = _first + 2 * size;
    }

    void push_back(const T &val) {
        if (full()) {
            expand();
        }
        _alloc.construct(_last, val);
        _last++;
    }

    void pop_back() {
        if (empty()) return;

        // <--- 修改点：标记指向最后一个元素的迭代器失效
        verify(_last - 1, _last - 1);

        --_last;
        _alloc.destroy(_last);
    }

    // 检查迭代器失效的核心函数
    void verify(T *first, T *last) {
        Iterator_Base *pre = _head;
        Iterator_Base *it = _head->_next;
        while (it != nullptr) {
            // 如果迭代器指向的地址在即将销毁的范围内
            if (it->_cur->_ptr >= first && it->_cur->_ptr <= last) {
                it->_cur->_pVec = nullptr; // 关键：标记失效！
                pre->_next = it->_next;    // 从链表摘除
                delete it;
                it = pre->_next;
            } else {
                pre = it;
                it = it->_next;
            }
        }
    }

    iterator begin() { return iterator(this, _first); }
    iterator end() { return iterator(this, _last); }
    bool full() const { return _last == _end; }
    bool empty() const { return _first == _last; }
    int size() const { return _last - _first; }
};

int main() {
    vector<int> vec(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    // 1. 获取一个迭代器，指向元素 1
    vector<int>::iterator it = vec.begin();
    cout << "Before expand, first element: " << *it << endl;

    // 2. 触发扩容（导致内存迁移）
    vec.push_back(4);
    cout << "Vector expanded." << endl;

    // 3. 尝试访问之前的迭代器（应该抛出异常）
    try {
        cout << "Try to access old iterator: " << *it << endl;
    } catch (const char* msg) {
        cerr << "Caught error: " << msg << endl; // 这里会被捕获
    }

    return 0;
}