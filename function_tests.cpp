#include <iostream>
#include <functional>

void main_fun();

int my_sum(int, int);
void reference_param(int&);
void const_ref_param(const int&);

int my_sum(int x, int y){
    return x + y;
}
void reference_param(int& val){
    val++;
    std::cout << "ARGUMENT PASSED BY REFERENCE:" << val << std::endl;
}
void const_ref_param(const int& val){
    // val++; // ERROR
    // val = 123; // ERROR
    // auto& val2 = val;
    // val2 = 123; ERROR
}

void function_params(){
    int x = 123;
    auto& y = x;
    std::cout << my_sum(1,2) << std::endl;
    reference_param(y);
    std::cout << "VAL OF X:" << x << std::endl;
    std::cout << "VAL OF Y:" << y << std::endl;
    const_ref_param(y);
}

void lambda_expression(){
    auto my_lambda = [](){
        std::cout << "VOID LAMBDA" << std::endl;
    };
    my_lambda();

    std::function<int(int, int)>  lambda_params = [](int a, int b){
        return a+b;
    };
    std::cout << "SUM USING LAMBDA= " << lambda_params(5,7) << std::endl;

     auto lambda_scope = [lambda_params](int a, int b) {
         auto sum = lambda_params(a,b);
         return a*b*sum;
     };
    std::cout << "PROD USING LAMBDA= " << lambda_scope(10,20) << std::endl;

    std::vector<int> my_vector{1,2,3,4,5,6,7,8,9,10, 11, 12};
    int divisible_3 = std::count_if(my_vector.begin(), my_vector.end(), [](int elem){
        return elem % 3 == 0;
    });
    std::cout << "NUMBERS DIVISBLES BY 3: " << divisible_3 << std::endl;
}

int main(){
    function_params();
    lambda_expression();
}