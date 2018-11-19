//
// Created by rbcheng on 11/19/18.
//

#include <iostream>

class Parent {
protected:
    std::string name;
    int age;
public:
    Parent(std::string name, int age): name(name), age(age) {

    }

    Parent(const Parent& parent) {
        std::cout << "parent copy" << std::endl;
        this->name = parent.name;
        this->age = parent.age;
    }

    virtual ~Parent() {
        std::cout << "delete parent" << std::endl;
    }
};

class Child: public Parent {
private:
    std::string talent;
public:
    Child(std::string name, int age, std::string talent): Parent(name, age), talent(talent) {

    }

    Child(const Child& child): Parent(child) {
        std::cout << "child copy" << std::endl;
        this->talent = child.talent;
    }

    ~Child() {
        std::cout << "delete child" << std::endl;
    }
};

int main() {

    Parent* p = new Child("child", 11, "fly");

    delete p;
}
