//
// Created by rbcheng on 2019/2/11.
// Email: rbcheng@qq.com
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

template <typename T1, typename T2>
auto add(T1 t1, T2 t2)-> decltype(t1 + t2) {
    return t1 + t2;
}

/**
 *
 * @tparam T
 * @param obj : obj must be a container in STL
 */
template <typename T>
void test_decltype(T obj) {
    typedef typename decltype(obj)::iterator i_type;
    i_type first = obj.begin();
    std::cout << *first << std::endl;
}

class Person {

private:
    std::string m_first_name;
    std::string m_last_name;
public:

    friend std::ostream& operator<<(std::ostream& out, const Person& person) {
        out << person.m_first_name << " " << person.m_last_name;
        return out;
    }

    Person(const std::string& first_name, const std::string& last_name): m_first_name(first_name), m_last_name(last_name) {

    }

    void first_name(const std::string& first_name) {
        m_first_name = first_name;
    }

    std::string first_name() const {
        return m_first_name;
    }

    void last_name(const std::string& last_name) {
            m_last_name = last_name;
    }

    std::string last_name() const {
        return m_last_name;
    }
};

int main() {
    /**
     *  Situation 1
     */
    std::cout << "Situation 1: " << std::endl;
    std::cout << add(1, 2) << std::endl;
    std::cout << add(std::string("111"), std::string("22222")) << std::endl;

    /**
     * Situation 2
     */
    std::cout << "Situation 2: " << std::endl;
    std::vector<int> vec = {1, 2, 3, 4};
    std::vector<int>::iterator i = vec.begin();
    test_decltype(vec);

    /**
     * Situation 3
     */

    auto cmp = [](const Person& p1, const Person& p2)-> bool {
        return (p1.last_name() < p2.last_name()) || (p1.last_name() == p2.last_name() && p1.first_name() < p2.first_name());
    };

    std::cout << "Situation 3: " << std::endl;
    std::set<Person, decltype(cmp)> persons(cmp);
    persons.insert({"kobe", "brayant"});
    persons.insert({"james", "jordan"});
    persons.insert({"kevin", "duran"});
    for (auto& person: persons) {
        std::cout << person << std::endl;
    }

}