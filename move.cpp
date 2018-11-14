//
// Created by rbcheng on 18-11-6.
// Email: rbcheng@qq.com
//
#include <iostream>
#include <functional>

typedef std::function<void(const std::string&)> Callback;

struct TestMove {

    Callback cb;

    void init(const Callback&& cb) {
        this->cb = cb;
    }

    void test() {
        a(std::move(this->cb));
        b(std::move(this->cb));
    }

    void a(const Callback&& cb) {
        cb("aaaa");
    }

    void b(const Callback&& cb) {
        cb("bbbb");
    }
};



int main() {

    TestMove test;
    test.init([](std::string s) {
        std::cout << "test" << s << std::endl;
    });

    test.test();
}

