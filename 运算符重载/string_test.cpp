//
// Created by huawei on 2026/6/3.
#include <cstring>
#include <iostream>
using namespace std;
class String {
public:
    String(const char* p = nullptr) {
        if (p != nullptr) {
            _pstr = new char[strlen(p) + 1];
            strcpy(_pstr, p);
        }else {
            _pstr = new char[1];
            *_pstr = '\0';
        }
    }
    String(const String& p) {
        _pstr = new char[strlen(p._pstr) + 1];
        strcpy(_pstr, p._pstr);
    }
    String& operator=(const String& str1) {
        if (this == &str1) {
            return *this;
        }
        delete[] _pstr;
        _pstr = new char[strlen(str1._pstr) + 1];
        strcpy(_pstr, str1._pstr);
        return *this;
    }
    ~String() {
        delete[] _pstr;
        _pstr = nullptr;
    }
    bool operator>(const String& str1) {
        return strcmp(_pstr, str1._pstr) > 0;
    }
    bool operator<(const String& str1) {
        return strcmp(_pstr, str1._pstr) < 0;
    }
    bool operator==(const String& str1) {
        return strcmp(_pstr, str1._pstr) == 0;
    }
    // 改
    char& operator[](int i) {
        return _pstr[i];
    }
    // 读
    const char & operator[](int i) const {
        return _pstr[i];
    }
    int length()const {
        return strlen(_pstr);
    }
    const char* c_str() const {
        return _pstr;
    }
    class iterator {
    public:
        iterator(char* p = nullptr):_p(p) {}
        bool operator!=(const iterator& it) {
            return _p != it._p;
        }
        void operator++() {
            ++_p;
        }
        char &operator*() {
            return *_p;
        }
    private:
        char *_p;
    };
    iterator begin() {
        return iterator(_pstr);
    }
    iterator end() {
        return iterator(_pstr + length());
    }
private:
    char *_pstr;
    friend ostream& operator<<(ostream& os, const String& str1);
    friend String operator+(const String& str1, const String& str2);
};
String operator+(const String& str1, const String& str2) {
    int len1 = strlen(str1._pstr);
    int len2 = strlen(str2._pstr);
    char *temp = new char[len1 + len2 + 1];
    strcpy(temp, str1._pstr);
    strcat(temp, str2._pstr);
    String str(temp); // 因为要返回String类型，所以在这里要创建对象，所以就要进行构造，在构造的时候，又创建内存
    delete[] temp; // 释放 析构
    return str;
}
ostream& operator<<(ostream& os, const String& str1) {
    os << str1._pstr << endl;
    return os;
}
int main() {
    // String str1;
    // String str2 = "aaa";
    // String str3 = "bbb";
    // String str4 = str2 + str3;
    // cout <<"str4" << str4 << endl;
    String str = "hello world";
    // 容器的迭代器
    // 迭代器可以透明的访问容器内部的元素的值
    // 提供一种统一的方式，来透明的遍历容器
    String::iterator it = str.begin();
    // auto it = str.begin();
    // str.end()表示的是字符串末尾的下一个位置的指针
    for (; it != str.end(); ++it) {
        cout << *it << endl;
    }

    // 底层还是通过迭代器
    for (char c : str) {
        cout << c << endl;
    }
    return 0;
}
