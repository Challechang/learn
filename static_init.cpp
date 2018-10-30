//
// Created by rbcheng on 18-10-30.
// Email: rbcheng@qq.com
//

#include <iostream>

template <typename T>
class TestClass {
public:
    static const int _datai = 5;
    static const long _datal = 4L;
    static const char _datac = 'a';
    static const short _datas = 8;
    static const long long _datall = 400L;
//    static const long double _datald = 55.32L;              // 错误, long double不是整型类别
//    static const float _dataf = 5.4f;                     // 错误, float不是整型类别
//    static const double _datad = 5.4;                     // 错误, double不是整型类别
//    static const std::string _datastr = "test_string";    // 错误, std::string不是整型类别
};

int main() {
    std::cout << TestClass<int>::_datai << std::endl;
    std::cout << TestClass<int>::_datal << std::endl;
    std::cout << TestClass<int>::_datac << std::endl;
    std::cout << TestClass<int>::_datas << std::endl;
    std::cout << TestClass<int>::_datall << std::endl;
}