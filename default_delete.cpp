// 
// Created by rbcheng on 2019/1/26.
// Email: rbcheng@qq.com
//
#include <iostream>

class uncopyable {
private:
    uncopyable(const uncopyable& u) = delete;
    const uncopyable& operator=(uncopyable& u) = delete;

public:
    uncopyable() = default;
};

class Person : public uncopyable {
private:
    friend std::ostream& operator<<(std::ostream& out, const Person& p);
    int age;
    std::string name;
public:
    Person(const std::string& name, int age): name(name), age(age) {}

};

std::ostream& operator<<(std::ostream& out, const Person& p) {
    out << "[ " << p.name << ", " << p.age << " ]";
    return out;
}

int main() {
    Person p = {"aaa", 1};
    /*Person p1(p);         // 编译错误 */
    std::cout << p << std::endl;
}