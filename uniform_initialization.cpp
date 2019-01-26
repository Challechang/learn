// 
// Created by rbcheng on 2019/1/26.
// Email: rbcheng@qq.com
//

#include <iostream>
#include <vector>
#include <complex>

int main() {

    BigThree big;

    int i;
    int j{};
    /*int z{4.4}; //类型不符合，编译出错*/
    std::cout << "i: " << i << std::endl;
    std::cout << "j: " << j << std::endl;

    int values[] {1, 2, 3, 4, 5};
    std::vector<int> v{2, 4, 6, 8, 10};
    std::vector<std::string> cities{
            "New York", "Beijing", "Berlin"
    };
    std::complex<double> c{4.4, 5.3};

    for(auto& val: values) {
        std::cout << val << std::endl;
    }

    std::cout << "------------------------------------" << std::endl;

    for (auto& vv: v) {
        std::cout << vv << std::endl;
    }

    std::cout << "------------------------------------" << std::endl;

    for (auto& city: cities) {
        std::cout << city << std::endl;
    }

    std::cout << "------------------------------------" << std::endl;

    std::cout << c << std::endl;

}