//
// Created by rbcheng on 2019/1/31.
// Email: rbcheng@qq.com
//

#include <vector>
#include <string>
#include <iostream>

const int SIZE = 1000;

template <typename Param, template <typename U> typename Container>
class Xcls {
private:
    Container<Param> container;
public:
    Xcls() {
        for (int i = 0; i < SIZE; ++i) {
            container.insert(container.end(), Param());
        }
    }
};

template <typename T>
using Vec = std::vector<T, std::allocator<T>>;

int main() {

    Xcls<int, Vec> xcls;
}