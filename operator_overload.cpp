//
// Created by rbcheng on 18-10-30.
// Email: rbcheng@qq.com
//

#include <iostream>

class INT {
private:
    int m_i;
public:

    INT(int i): m_i(i) {}

    // increment and fetch
    INT& operator++() {
        this->m_i ++;
        return *this;
    }

    // fetch and increment
    INT& operator++(int) {
        INT temp = *this;
        ++(*this);
        return temp;
    }

    INT& operator+(const INT& other) {
        INT temp(this->m_i + other.m_i);
        return temp;
    }

    friend std::ostream& operator << (std::ostream& out, INT& anInt) {
        out << anInt.m_i;
        return out;
    }
};

int main() {
    INT anInt(4), anInt1(5);
    std::cout << ++anInt << std::endl;
    std::cout << anInt++ << std::endl;
}