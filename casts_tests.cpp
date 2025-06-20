#include <iostream>
#include <algorithm>
#include <cstring>
class BaseClass {
public:
    virtual ~BaseClass(){};
};

class DerivedClass : public BaseClass {
};

int main2() {

    int x = 123;
    int* p = &x;
    void* p_void = p; // implicit cast, any pointer can be casted to void*
    int* p2 = static_cast<int*>(p_void); // static_cast only can be used for cast to pointers
    std::cout << *p2 << std::endl;
    std::cout << *p << std::endl;

    BaseClass* base = new DerivedClass();
    DerivedClass* derived= new DerivedClass();

    if (dynamic_cast<DerivedClass*>(base)){ // dynamic_cast only is used for cast pointers in inheritance
        std::cout << "CONVERSION OK" << std::endl;
    }
    else {
        std::cout << "CONVERSION ERROR" << std::endl;
    }

    if (dynamic_cast<BaseClass*>(derived)) {
        std::cout << "OK CONVERSION" << std::endl;
    }
    else {
        std::cout << "ERROR CONVERSION" << std::endl;
    }
    // always delete pointers
    delete base;
    delete derived;
}
bool number_is_prime(long long);
bool is_in(std::vector<int>, int);
int main(){
    //std::cout << number_is_prime(98473 )<<std::endl;
    std::cout << is_in(std::vector<int>{1,2,3,5,7,9,10,15,20,30,40,50}, 12);

}
#include <math.h>
bool number_is_prime(long long number){
    int N = 7920;
    bool primes[N];
    std::memset(primes, 1, sizeof(bool) * N);
    primes[0] = primes[1] = false;
    for (int i = 2;i<N; i++){
        for (int j = i*i; j<N; j+=i){
            primes[j] = false;
        }
    }
    std::vector<int> v_primes;


    for (int i=0; i<N; i++){
        if(primes[i]){
            v_primes.emplace_back(i);
        }
    }

    int max_divisor = ceil(sqrt(number));
    for (int n: v_primes){
        if (n > max_divisor)
            break;
        if (number%n == 0)
            return false;
    }
    return true;
}

bool is_in(std::vector<int> elements, int value){
    int start = 0;
    int end = elements.size()-1;
    int middle = (start+end)/2;
    while(start <= end){
        middle = (start+end)/2;
        if (elements[middle] == value)
            return true;
        if (value < elements[middle]){
            end = middle-1;
        } else{
            start = middle+1;
        }
    }
    if (elements[middle] == value)
        return true;
    return false;
}