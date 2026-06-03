//
// Created by huawei on 2026/6/3.
//
/**
 * 使对象的运算标签和编译器内置类型一样
 */
#include<iostream>
using namespace std;
// 复数类
class CComplex {
public:
    CComplex(int r = 0, int i = 0) : mreal(r), mimage(i) {};
    // CComplex operator+(const CComplex& num) const {
    //     // CComplex result;
    //     // result.mreal = mreal + num.mreal;
    //     // result.mimage = mimage + num.mimage;
    //     // return result;
    //     return CComplex(this->mreal + num.mreal, this->mimage + num.mimage);
    // }
    // 后置++
    CComplex operator++(int){
        // 保留旧值，然后++
        return CComplex(mreal++,mimage++);
    }
    CComplex& operator++() {
        mreal+=1;
        mimage+=1;
        return *this;
    }
    CComplex operator+=(CComplex& c) {
        return CComplex(mreal+=c.mreal,mimage+=c.mimage);
    }
    void show() const {
        cout << mreal << " + " << mimage << "i" << endl;
    }
    int get_mreal() const {return mreal;}
    int get_mimage() const {return mimage;}
private:
    int mreal;
    int mimage;
    // 全局的函数 成为类的朋友，然后就可以访问私有成员变量
    friend CComplex operator+(const CComplex& num1, const CComplex& num2);
    friend ostream& operator<<(ostream& os, const CComplex& num);
    friend istream& operator>>(istream& is, CComplex& num);
};
// 定义一个友元函数
CComplex operator+(const CComplex& num1, const CComplex& num2) {
    return CComplex(num1.mreal + num2.mreal, num1.mimage + num2.mimage);
}
// 输出对象运算符重载
ostream& operator<<(ostream& os, const CComplex& num) {
    os << num.mreal << " + " << num.mimage;
    return os;
}
istream& operator>>(istream& is, CComplex& num) {
    is >> num.mreal >> num.mimage;
    return is;
}
int main() {
    CComplex c1(1,2);
    CComplex c2(2,3);
    // c1.operator+(c2)
    CComplex c3 = c1+c2;
    c3.show();
    CComplex c4 = c1 + 20;
    c4.show();
    CComplex c5 = 30 + c1;
    c5.show();
    // operator++() 前置++
    // operator++(int) 后置++
    c5 = c1++;
    c1.show();
    c5.show();
    c5 = ++c1;
    c1.show();
    c5.show();
    // c1.operator+=(c2);
    c1+=c2;
    c1.show();
    cout << c1 << endl;
    cin >> c1;
    cout << c1 << endl;
    return 0;
}
