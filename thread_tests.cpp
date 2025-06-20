#include <iostream>
#include <thread>
#include <string>
#include <mutex>

std::mutex m;

void func_1(){
    for (int i = 0; i < 20 ; i++){
        std::cout << "FUNC_1 "  << i << std::endl;
    }
}

void func_2(){
    for(int i=0; i<20 ; i++){
        std::cout << "FUNC_2 " << i << std::endl;
    }
}

void func_3(const std::string& text){
    for(int i = 0; i < 100 ; i++){
        //m.lock();
        std::lock_guard<std::mutex> lg(m); // unlocks when out of scope and the object get destroyed
        std::cout << "FUNC_3 " << i << " " << text << std::endl;
        //m.unlock();
    }
}

int main(){
    std::thread t1(func_1);
    std::thread t2(func_2);
    t1.join();
    t2.join();

    std::thread t3(func_3, "THREAD 3");
    std::thread t4(func_3, "THREAD 4");
    t3.join();
    t4.join();
}