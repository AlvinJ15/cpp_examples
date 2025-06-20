#include <iostream>
template<typename T, typename U>
void print_template(T t, U u){
    std::cout << "T: " << t << " " << "U: " << u << std::endl;
}

// template specialization for specific params
template<>
void print_template(int arg, std::string arg2){
    std::cout << "SPECIAL int string T: " << arg << " " << "U: " << arg2 << std::endl;
}

void any_function(std::string arg) {
    std::cout << arg << std::endl;
}

int main() {
    std::string abc = "asd";
    any_function(abc);
    print_template("123", "123");
    print_template(456,abc);
}