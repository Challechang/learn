//
// Created by rbcheng on 11/1/18.
//

#include <iostream>

class A {
public:
    int a;
    float b;
    A() {
        std::cout << "invoke 1" << std::endl;
    }
    A(int a, float b): a(a), b(b) {
        std::cout << "invoke 2" << std::endl;
    }

    A(const A& a) {
        std::cout << "invoke 3" << std::endl;
    }
};

void print(std::initializer_list<int> vals) {
    for (auto& val: vals) {
        std::cout << val << std::endl;
    }
}

int main() {
    A a = {1, 1.2};
    A a1 = {2, 3.3};
    A arr[2] = {a, a1};

    print({1, 2, 3, 4, 5, 6});
    std::cout << std::endl;
}