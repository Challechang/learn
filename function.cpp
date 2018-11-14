//
// Created by rbcheng on 18-11-12.
// Email: rbcheng@qq.com
//
#include <iostream>

struct tag {
    char ch;
    long num;
};

template <typename T=void>
class PC {
    T val;
};

int main() {
    PC<tag> pc;
}