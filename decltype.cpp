//
// Created by rbcheng on 2019/2/11.
// Email: rbcheng@qq.com
//

#include <iostream>
#include <unordered_map>
#include <vector>

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
    std::cout << "Situation 3: " << std::endl;
    auto my_func = [](int i)->void {
        std::cout << "my _func: " << i << std::endl;
    };

    std::unordered_map<int, decltype(my_func)> m_map;
    m_map.insert({1, my_func});
    m_map.insert({2, my_func});
    for (auto& _m_map: m_map) {
        _m_map.second(_m_map.first);
    }
}