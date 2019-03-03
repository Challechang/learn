//
// Created by rbcheng on 2019/3/2.
// Email: rbcheng@qq.com
//

#include <string>
#include <unordered_set>
#include <iostream>

class PersonHash;

struct Person {
private:
    std::string name;
    std::string sex;
    short age;
public:
    Person() = default;

    Person(const std::string& name, const std::string& sex, const short age) {
        this->name = name;
        this->sex = sex;
        this->age = age;
    }

//    bool operator==(const Person& p1) {
//        return ((this->name == p1.name)&&(this->age == p1.age)&&(this->sex == p1.sex));
//    }

    friend class PersonHash;
    friend class std::hash<Person>;
    friend bool operator==(const Person& p1, const Person& p2);

};

bool operator==(const Person& p1, const Person& p2) {
    return ((p1.name == p2.name)&&(p1.sex == p2.sex)&&(p1.age == p2.age));
}

class PersonHash {

public:
    size_t operator()(const Person& person) const {
        return std::hash<std::string>()(person.name) + std::hash<std::string>()(person.sex) + std::hash<short>()(person.age);
    }
};

namespace std {

    template <>
    struct hash<Person> {
    public:
        size_t operator()(const Person& person) const {
            return std::hash<std::string>()(person.name) + std::hash<std::string>()(person.sex) + std::hash<short>()(person.age);
        }
    };

}


int main() {
    std::unordered_set<Person> persons;
    persons.insert({"bob", "man", 11});
    persons.insert({"bob", "man", 11});

    std::unordered_multiset<Person, PersonHash> persons1;
    persons1.insert({"alice", "woman", 11});
    persons1.insert({"alice", "woman", 11});
    std::cout << std::endl;
}