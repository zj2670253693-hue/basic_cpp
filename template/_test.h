//
// Created by huawei on 2026/6/2.
//

#ifndef BASIC_CPP__TEST_H
#define BASIC_CPP__TEST_H
#include <cstring>
#include <iostream>
using namespace std;

template <typename T>
bool compare(T a, T b) {
    cout << "compare" << endl;
    return a>b;
}
template <>
bool compare<const char*>(const char *str,const char *str2) {
    cout << "compare<const char*>" << endl;
    return strcmp(str,str2) > 0;
}
bool compare(const char*a,const char*b) {
    cout << "nomoral compare" << endl;
    return strcmp(a,b) > 0;
}
#endif //BASIC_CPP__TEST_H
