#include <iostream>

void simple_function(){
    // instantiate x just 1 time
    static int x = 0;
    x++;
    std::cout << "VALUE X: " << x << std::endl;
}

int main(){
    // const int a; //ERROR
    const int x = 123;
    const int x2 = x;
    const auto& const_x = x;

    int variable = 456;
    constexpr int y = 1;
    static_assert(y  == 1, "The y isnt initialized properly");
    // constexpr int z = variable; // ERROR variable used instead expresion

    simple_function();
    simple_function();
    simple_function();

}
