//
// Created by rbcheng on 2019/1/31.
// Email: rbcheng@qq.com
//

#include <string>
#include <iostream>

class Pen;

class Teacher {
private:
    std::string name;
    int age;
public:
    Teacher() = default;
    Teacher(const std::string& name, int age): name(name), age(age) {}
    void use(Pen);
private:
    friend std::ostream& operator<<(std::ostream& out, const Teacher& teacher);
};

class Pen {
public:
    Pen() = default;
    Pen(int len, const std::string& producer, double price): len(len), producer(producer), price(price){}
    friend void Teacher::use(Pen pen);

private:
    friend std::ostream& operator<<(std::ostream& out, const Pen& pen);
    int len;
    std::string producer;
    double price;
};

void Teacher::use(Pen pen) {
    std::cout << *this << std::endl;
    std::cout << pen << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Teacher& teacher) {
    out << std::string("teacher:\n { name: ") << teacher.name << ", \n { age: " << teacher.age << " }";
    return out;
}

std::ostream& operator<<(std::ostream& out, const Pen& pen) {
    out << "pen: [ len: " << pen.len << " price: " << pen.price << " producer: " << pen.producer << " ]";
    return out;
}

int main() {
    Pen pen {5, "Guang Ming", 2.5};
    Teacher teacher {"Challe", 24};
    teacher.use(pen);
}
