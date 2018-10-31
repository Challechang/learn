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
    INT operator++(int) {
        INT temp = *this;
        ++(*this);
        return temp;
    }

    INT operator+(const INT& other) {
        INT temp(this->m_i + other.m_i);
        return temp;
    }

    INT operator-(const INT& other) {
        INT temp(this->m_i - other.m_i);
        return temp;
    }



    friend std::ostream& operator << (std::ostream& out, const INT& anInt) {
        out << anInt.m_i;
        return out;
    }

    friend INT operator*(const INT& first, const INT& second);
};

INT operator*(const INT& first, const INT& second) {
    INT temp(first.m_i * second.m_i);
    return temp;
}

int main() {
    INT anInt(4), anInt1(5);
    std::cout << ++anInt << std::endl;
    std::cout << anInt++ << std::endl;
    INT sum = anInt1 + anInt;
    std::cout << anInt * anInt1 << std::endl;
    std::cout << sum << std::endl;
    std::cout << anInt << std::endl;
    std::cout << anInt1 << std::endl;
}