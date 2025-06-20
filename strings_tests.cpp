#include <iostream>
#include <string_view>

int main(){
    std::string first_string = "Hello ";
    first_string += "world";
    first_string += '!';
    std::cout << first_string << std::endl;
    std::cout << first_string[0] << std::endl;
    std::cout << first_string.at(0) << std::endl;
    if (first_string == "Hello world!"){
        std::cout << "String are equals!" << std::endl;
    }

    // Input line
    std::string name;
    //std::getline(std::cin, name);
    std::cout << name << std::endl;

    // pointers to string
    std::string my_string = "TWILIGHT SPARKLE";
    const char * string_pointer = my_string.c_str();
    std::cout << string_pointer << std::endl; // return const char* to the string variable
    std::cout << string_pointer[1] << std::endl;
    std::string my_substring = my_string.substr(1, 3);
    std::cout << "SUBSTRING: "<< my_substring << std::endl;
    if (my_string.find("TWIs") != std::string::npos){
        std::cout << "STRING FOUND !!!" << std::endl;
    }
    else {
        std::cout << "STRING NOT FOUND" << std::endl;
        std::cout << std::string::npos << std::endl;
    }

    // C++17 STRING VIEW
    std::string_view sv = "MY LARGE STRING";
    auto substring_1_2 = sv.substr(3,5);
    std::cout << substring_1_2 << std::endl;
}