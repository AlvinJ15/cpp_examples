#include <iostream>

enum MyFirstEnum {
    ZERO,
    FIRST = 5,
    SECOND
};
int main(){
    MyFirstEnum o = MyFirstEnum::SECOND;
    std::cout <<  MyFirstEnum::ZERO << std::endl;
    std::cout <<  MyFirstEnum::FIRST << std::endl;
    std::cout <<  MyFirstEnum::SECOND << std::endl;


}