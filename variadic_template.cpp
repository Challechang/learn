// 
// Created by rbcheng on 2019/1/25.
// Email: rbcheng@qq.com
//

#include <iostream>

void print() {

}

template <typename T, typename... Types>
void print(const T& first_arg, const Types&... args) {
    std::cout << first_arg << std::endl;
    std::cout << "fun1 sizeof args: " << sizeof...(args) << std::endl;
    print(args...);
};

int main() {
    print(1, 2, 44.4, "1111", "fff");
}
