#include <iostream>
#include <memory>

class MyClass {
public:
    void print_message() {
        std::cout << "MESSAGE" << std::endl;
    }
};

int main() {
    int* a = new int{123};
    int *b = new int{123};

    std::unique_ptr<int> p(new int{123});
    std::unique_ptr<int> p2 = std::unique_ptr<int>(new int{123});
    std::unique_ptr<int> p3 = std::make_unique<int>(123); // -std=c++14
    //std::unique_ptr<int> p4 = p; // unique_ptr can't be copied
    std::cout << *p << std::endl;
    std::cout << p2.operator*() << std::endl;
    std::cout << *p3 << std::endl;

    std::unique_ptr<MyClass> o = std::make_unique<MyClass>();
    o->print_message(); // uses -> for access attributes from pointer

    std::shared_ptr<int> s = std::make_shared<int>(10);
    std::shared_ptr<int> s2 = s;
    std::shared_ptr<int> s3 = s;
    std::cout << "s: " << *s << std::endl;
    std::cout << "s2: " << *s2 << std::endl;
    std::cout << "s3: " << *s3 << std::endl;

    *s = 20;
    std::cout << "s: " << *s << std::endl;
    std::cout << "s2: " << *s2 << std::endl;
    std::cout << "s3: " << *s3 << std::endl;

    *s3 = 50;
    std::cout << "s: " << *s << std::endl;
    std::cout << "s2: " << *s2 << std::endl;
    std::cout << "s3: " << s3* << std::endl;
}