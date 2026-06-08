//
// Created by huawei on 2026/6/3.
//
#include <iostream>
#include <vector>
using namespace std;
void vec_erase(vector<int> &vec) {
    // 删除容器中所有偶数
    auto it = vec.begin();
    while(it != vec.end()) {
        if (*it % 2 == 0) {
            // 对迭代器进行更新
            it = vec.erase(it);
        }else {
            ++it;
        }
    }
    for (int num : vec) {
        cout << num << endl;
    }
}
// 在容器中的偶数位置添加上偶数-1
void vec_insert(vector<int> &vec) {
    auto it = vec.begin();
    while (it != vec.end()) {
        if (*it % 2 == 0) {
            it = vec.insert(it,*(it - 1));
            it += 2;
        }else {
            ++it;
        }
    }
    for (int num : vec) {
        cout << num << endl;
    }
}
int main() {
    vector<int> vec;
    for (int i = 0;i < 20;i++) {
        vec.push_back(i);
    }
    // vec_erase(vec);
    vec_insert(vec);
    // 为vec容器中所有的偶数前面添加一个小于偶数值1的数字
    // 把vec容器中所有偶数全部删除
    // 得到迭代器中的
    return 0;
}