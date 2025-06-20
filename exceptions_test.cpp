#include <iostream>

int main(){
    try {
        std::cout << "forcing and exception: " << std::endl;
        throw 123;
    }
    catch(int a){
        std::cout << "EXECPTION: "<< a << std::endl;
    }

    try {
        std::cout << "forcing another exception" << std::endl;
        throw std::string("my_string");
    }
    catch(const std::string& str){
        std::cout << "EXCEPTION: " << str << std::endl;
    }
}
