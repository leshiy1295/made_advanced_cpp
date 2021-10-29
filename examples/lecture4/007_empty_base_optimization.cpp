#include <iostream>

struct Alpha {};

struct Beta : Alpha {
    int a;
};

struct Gamma : Alpha { // база размера 1
    Alpha a; // атрибут размера 1
    int n;
};

struct Delta : public Alpha { // база размером 1
    Beta b; // атрибут размера sizeof(int);
    int n;
};

int main() {
    std::cout << "sizeof(Alpha) == " << sizeof(Alpha) << "\n";
    std::cout << "sizeof(Beta)  == " << sizeof(Beta) << "\n";
    std::cout << "sizeof(Gamma) == " << sizeof(Gamma) << "\n";
    std::cout << "sizeof(Delta) == " << sizeof(Delta) << "\n";
    return 0;
}
