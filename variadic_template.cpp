// 
// Created by rbcheng on 2019/1/25.
// Email: rbcheng@qq.com
//

#include <iostream>
#include <bitset>
#include <tuple>

void print() {

}

template <typename T, typename... Types>
void print(const T& first_arg, const Types&... args) {
    std::cout << first_arg << std::endl;
    std::cout << "fun1 sizeof args: " << sizeof...(args) << std::endl;
    print(args...);
};

template <typename T>
T maximum(const T& t) {
    return t;
}

template <typename T, typename ...Types>
T maximum(const T& t, const Types&... args) {
    return std::max(t, maximum(args...));
}

/**
 * Version 1
 * 格式化输出tuple
 *
 */

template <int INDEX, int MAX, typename ... Types>
struct PRINT_TUPLE {

    static void print(std::ostream& out, const std::tuple<Types...>& args) {
        out << std::get<INDEX>(args) << ((INDEX + 1) != MAX ? "," : "");
        PRINT_TUPLE<INDEX+1, MAX, Types...>::print(out, args);
    }
};

template <int MAX, typename ... Types>
struct PRINT_TUPLE<MAX, MAX, Types...> {

    static void print(std::ostream& out, const std::tuple<Types...>& args) {
    }
};

template <typename ... Args>
std::ostream& operator<<(std::ostream& out, const std::tuple<Args...>& args) {
    std::cout << "[";
    PRINT_TUPLE<0, sizeof...(Args), Args...>::print(out, args);
    std::cout << "]";
};



int main() {
    print(1, 2, 44.4, "1111", "fff", std::bitset<32>(377));
    std::cout << "max: " << maximum(1, 3, 5, 6, 8) << std::endl;
    std::cout << "string max: " << maximum(std::string("a"), std::string("b"), std::string("c"), std::string("dd")) << std::endl;

    auto m_tuple = std::make_tuple(1, "aaaa", 6.5, 55);
    std::cout << "tuple: " << m_tuple << std::endl;
}
