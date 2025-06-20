#include <iostream>
#include <string>
int main() {
    // REFERENCES: -------------------------------------------------------------
    int x = 123;
    int& ref_x = x;
    std::cout << "Value of x = " << x << std::endl;
    std::cout << "Value of ref_x = " << ref_x << std::endl;

    x = 456;
    std::cout << "Value of x = " << x << std::endl;
    std::cout << "Value of ref_x = " << ref_x << std::endl;

    ref_x = 789;
    std::cout << "Value of x = " << x << std::endl;
    std::cout << "Value of ref_x = " << ref_x << std::endl;

    auto& auto_ref_x = x;
    const auto& const_auto_ref_x = x;
    auto_ref_x = 12;
    std::cout << "AUTO REF: " << auto_ref_x << std::endl;
    std::cout << "X: " << x<< std::endl;

    // POINTERS: -------------------------------------------------------------
    // int* p; // INCORRECT SEGSEGV ERROR
    int* p = new int;
    std::cout << "VALUE OF P: " << *p << std::endl;
    *p = 123;
    std::cout << "VALUE OF P: " << *p << std::endl;
    delete p;
    std::cout << "VALUE OF P: " << *p << std::endl;

    int* arr = new int[3];
    std::cout << "The values ar: " << arr[0] << ' ' << arr[1] << ' ' << arr[2] << std::endl;
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    std::cout << "The values ar: " << arr[0] << ' ' << arr[1] << ' ' << arr[2] << std::endl;
    delete[] arr;
    std::cout << "The values ar: " << arr[0] << ' ' << arr[1] << ' ' << arr[2] << std::endl;
}
