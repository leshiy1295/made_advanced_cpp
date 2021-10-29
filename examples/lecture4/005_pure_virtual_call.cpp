#include <iostream>

struct A {
        virtual void foo() = 0;
        void bar() { A::foo(); }
        A() { bar(); /*A::foo();*/ }
};
void A::foo() { std::cout << "A::foo()\n"; }

struct B : A {
        B() { foo(); }
        void foo() { std::cout << "B::foo()\n"; A::foo(); }
};

int main() {

    B().bar();

}
