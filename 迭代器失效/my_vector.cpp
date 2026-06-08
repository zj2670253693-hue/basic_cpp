//
// Created by huawei on 2026/6/4.
//
#include<iostream>
#include <vector>
using namespace std;
template <typename T>
class my_vector {



    class iterator {
    public:
        friend class my_vector<T,Alloc>;
        iterator(my_vector<T,Alloc> *vec,T *ptr = nullptr):ptr(ptr),_pVec(pvac) {
            Iterator_Base *it = new Iterator_Base(this,_pVec->_head.next);
        }
    }
};
int main () {

    return 0;
}