//
// Created by huawei on 2026/6/3.
//
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> vec;
    for (int i = 0;i < 20;i++) {
        vec.push_back(i);
    } 

    // 把vec容器中所有偶数全部删除
    auto begin = vec.begin();
    for (;begin != vec.end(); ++begin) {
        if (*begin % 2 == 0) {
            vec.erase(begin);
        }
    }
    // 得到迭代器中的
    return 0;
}