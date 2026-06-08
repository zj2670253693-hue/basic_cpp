//
// Created by huawei on 2026/6/7.
//
#include<iostream>
#include"global.h"
const int bufferSize2 = 100;
void printBuffSize() {
    std::cout<<"global.cpp" << &bufSize<<std::endl;
    std::cout<< "global_bufferSize2"<< &bufferSize2 << std::endl;
}
int getSize() {
    return 1;
}
