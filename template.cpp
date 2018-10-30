//
// Created by rbcheng on 18-10-24.
// Email: rbcheng@qq.com
//

#include <iostream>
#include <future>
#include "template.h"

template <typename T = std::string>
class Complex {
private:
    std::string val;
    T t;
public:

    Complex(std::string val, T t) {
        this->val = val;
        this->t = t;
    }

    friend std::ostream& operator<<(std::ostream& out, Complex& complex) {
        out << complex.val << ": " << complex.t;
        return out;
    }
};
double test_double = 1.0;
template <typename T, std::string& a, typename K = std::string, typename V = std::string, double& b = test_double>
class Demo {
private:
    T t;
    V v;

};

void test(int i, float j = 0, int k = 0, double h = 0) {

}

template <class T>
class List {

};

template <class T>
class List<T*> {

};

template <>
class List<void *> {

};



template <class T = std::string>
T sqrt(T t) {
    std::cout << t << std::endl;
    return t;
}

template <class T>
Complex<T> sqrt(Complex<T> t) {

    std::cout << t << std::endl;
    return t;
}

double sqrt(double t) {
    std::cout << t << std::endl;
    return t;
}

void f(Complex<double> z) {
    auto a = sqrt(z);
    sqrt(2);
}

template <class T>
T max(T t1, T t2) {
    return t1 > t2 ? t1: t2;
}

void k() {
    max(1, 2);
    max('a', 'b');

//    max('a', 1);
//    max(2.7, 4);
}

template <typename T>
void Template<T>::print(T t) {
    std::cout << "print: " << t << std::endl;
}

template <>
void Template<std::string>::print(std::string t) {
    std::cout << "print: string - " << t << std::endl;
}


template <typename T>
    template <typename T2>
//    template <typename T, typename T2>    // 错误, 一个模板的模板参数表与其模板成员的模板参数表不能组合在一起
    Ptr<T>::operator Ptr<T2>() {
    return Ptr<T2>(p);
}

template <class T>
struct plus {
    T operator()(const T& x, const T& y) const {
        return x + y;
    }
};



int main() {

    auto c = new Complex<double>("111", 222.0);
    auto c1 = new Complex<>("test", "ffff");
    sqrt(*c1);
    std::cout << *c1 << std::endl;
    f(*c);
    auto a = sqrt(*c);
    std::cout << a << std::endl;

    k();
    Template<int> t;
    t.out(1);

    Template<int> t1;
    t1.print(1);

    plus<int> plu_obj;
    std::cout << "plus: " << plu_obj(1, 2) << std::endl;

}

