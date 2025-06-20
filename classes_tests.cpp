#include <iostream>

using int2 = long; // alliases
// Struct have their members public by default
struct PublicClass {
    void do_something();
};

void PublicClass::do_something() {
    std::cout << "STRUCT DO SOMETHING" << std::endl;
}

// Class has their members private by default
class PrivateClass {
public:
    int2 x;
    int* y;
    std::string str;
public:
    PrivateClass() = default; // with default the default constructor don't need implementation
    // PrivateClass() = delete; // delete the default implementation for base constructor
    PrivateClass(int, int, std::string);
    PrivateClass(const PrivateClass&);
    PrivateClass& operator=(const PrivateClass&);
    PrivateClass(PrivateClass&&);
    PrivateClass& operator=(PrivateClass&&);
    void do_something();

    void do_something_else();
};

//PrivateClass::PrivateClass() {}
PrivateClass::PrivateClass(int xx, int yy, std::string s) : x{xx}, y{new int{yy}}, str{s} {
    std::cout << "CONSTRUCTOR INVOKED" << std::endl;
}

PrivateClass::PrivateClass(const PrivateClass& obj): x{obj.x}, y{new int{*obj.y}}{}

void PrivateClass::do_something() {
    std::cout << "DO SOMETHING" << std::endl;
}

void PrivateClass::do_something_else() {
    std::cout << "DO SOMETHING ELSE" << std::endl;
}

PrivateClass& PrivateClass::operator=(const PrivateClass& obj){
    x = obj.x;
    y = new int{*obj.y};
    return *this;
}

PrivateClass::PrivateClass(PrivateClass&& obj): x{std::move(obj.x)}, y{new int{std::move(*obj.y)}}, str{std::move(obj.str)}{}

PrivateClass& PrivateClass::operator=(PrivateClass&& obj){
    x = std::move(obj.x);
    y = new int{std::move(*obj.y)};
    str = std::move(obj.str);
}

// PrivateClass& PrivateClass::operator++(const PrivateClass)


class SecondClass : public PrivateClass {
    int firstMethod(){
        return x;
    }
};
int main() {
    PublicClass o2;
    o2.do_something();

    PrivateClass o{1, 2, "aaa"};
    PrivateClass o_copy = o;
    o.x = 3'000;
    o.y = new int{4};
    (&o)->do_something();
    std::cout << "O: " << o.x << " " << o.y << std::endl;
    std::cout << "O_COPY: " << o_copy.x << " " << *o_copy.y << std::endl;

    PrivateClass o_copy_operator;
    o_copy_operator = o;
    *o.y = 7;
    std::cout << "O: " << o.x << " " << *o.y << " " << o.str << std::endl;
    std::cout << "O_COPY_OPERATOR: " << o_copy_operator.x << " " << *o_copy_operator.y << " " << o_copy_operator.str << std::endl;

    std::cout << "*****************************" << std::endl;
    std::cout << "O: " << o.x << " " << *o.y << " " << o.str << std::endl;
    std::cout << "o_copy_operator: " << o_copy_operator.x << " " << *o_copy_operator.y << " " << o_copy_operator.str<< std::endl;

    PrivateClass moved_o_constructor = std::move(o);
    std::cout << "O: " << o.x << " " << *o.y << " " << o.str << std::endl;
    std::cout << "moved_o_constructor: " << moved_o_constructor.x << " " << *moved_o_constructor.y << " " << moved_o_constructor.str << std::endl;

    PrivateClass moved_o_equal = o_copy_operator;
    std::cout << "o_copy_operator: " << o_copy_operator.x << " " << *o_copy_operator.y << " " << o_copy_operator.str << std::endl;
    std::cout << "moved_o_equal: " << moved_o_equal.x << " " << *moved_o_equal.y << " " << moved_o_equal.str << std::endl;

}

