// 
// Created by rbcheng on 2019/1/26.
// Email: rbcheng@qq.com
//

class uncopyable {
private:
    uncopyable(const uncopyable& u) = delete;
    const uncopyable& operator=(uncopyable& u) = delete;
};

int main() {

}