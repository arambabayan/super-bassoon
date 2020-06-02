#include <iostream>

class A {
    public:
    A() {
        std::cout<<"A create\n";
    }
    ~A() {
        std::cout<<"A delete\n";
    }
};
class B:A {
    public:
    B() {
        std::cout<<"B create\n";
    }
    ~B() {
        std::cout<<"B delete\n";
    }
};
class C:A {
    public:
    C() {
        std::cout<<"C create\n";
    }
    ~C() {
        std::cout<<"C delete\n";
    }
};
class D:B {
    public:
    D() {
        std::cout<<"D create\n";
    }
    ~D() {
        std::cout<<"D delete\n";
    }
};

int main () {
    D d;
    return 0;
}
