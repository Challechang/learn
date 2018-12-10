//
// Created by rbcheng on 12/10/18.
//
#include <functional>
#include <iostream>

typedef std::function<void()> Callback;

Callback callback;
Callback callback1;

// lambda 值捕获局部变量值
void set_cb(int i) {
    int j = 100;
    callback = [=]()mutable {
        std::cout << "j: " << j << std::endl;
        j++;
    };
}
// lambda 引用捕获局部变量值
void set_cb1() {
    int z = 100;
    callback1 = [&]() {
        std::cout << "z: " << z << std::endl;
    };
}

int main() {
    set_cb(0);
    set_cb1();
    for (int i = 0; i < 10; ++i) {
        callback();
    }

    callback1();

}
