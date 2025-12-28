#include <iostream>
#include <typeinfo>
int main() {
    auto p = 1 + 0.5 + '1';
    std::cout << p << typeid(p).name() << std::endl;
    return 0;
}