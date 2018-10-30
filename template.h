//
// Created by rbcheng on 18-10-29.
// Email: rbcheng@qq.com
//

#ifndef LEARN_TEMPLATE_H
#define LEARN_TEMPLATE_H

template <typename T>
class Template {

public:
    void print(T t);

    template <typename O>
    void out(O o) {
        std::cout << "out: " << o << std::endl;
    }

};

template <typename T>
class Ptr {
    T* p;
public:
    Ptr(T* p) {
        this->p  = p;
    }

    template <typename T2>
    operator Ptr<T2>();

};

#endif //LEARN_TEMPLATE_H
