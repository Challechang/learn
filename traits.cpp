//
// Created by rbcheng on 11/7/18.
//

#include <iostream>

template <typename T>
struct MyIter {
    typedef T value_type;
    T* ptr;
    MyIter(T* p = nullptr): ptr(p){}

    T operator*() {
        return *ptr;
    }
};

template <typename I>
typename I::value_type func(I iter) {
    return *iter;
}

int main() {
    MyIter<int> iter(new int(10));

    std::cout << func(iter) << std::endl;
}