//
// Created by rbcheng on 18-11-2.
// Email: rbcheng@qq.com
//

#include <iostream>

struct Obj {
    int m_i;
    double m_j;

    Obj(int i = 0, double j = 0.0): m_i(i), m_j(j) {
        std::cout << "obj construct" << std::endl;
    }

    ~Obj() {
        std::cout << "obj decontruct" << std::endl;
    }
};

typedef Obj* pointer;

int main() {
    int size = 1 << 2;  // 4
    pointer p = (pointer)(::operator new((size_t)(size * sizeof(Obj))));

    pointer obj = new(p)Obj(1, 1.5);
    p->~Obj();
    ::operator delete(p);
    std::cout << obj->m_i << std::endl;
    std::cout << std::endl;
}