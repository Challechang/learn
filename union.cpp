//
// Created by rbcheng on 11/6/18.
//

#include <iostream>
#include <backward/auto_ptr.h>

union obj {
    union obj* free_link_list;
    char client_data[1];
};

int main() {
    std::string a = "abc";
    char* p = const_cast<char*>(a.data());
    obj* p1 = (obj*)p;
    std::cout << p1->client_data << std::endl;
    return 0;
}