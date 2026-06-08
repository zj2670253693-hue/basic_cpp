//
// Created by huawei on 2026/6/7.
//

#ifndef BASIC_CPP_GLOBAL_H
#define BASIC_CPP_GLOBAL_H
const int bufSize = 1024;
extern void printBuffSize();
extern const int bufferSize2;
extern int getSize();
inline constexpr  int getSizeConst() {
    return 1;
}
#endif //BASIC_CPP_GLOBAL_H
