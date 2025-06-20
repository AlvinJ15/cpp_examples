#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>
#include <span>

template <typename T>
concept MustBeIncrementable = requires (T x) { x+=1;};

template <typename T>
concept MustBeDivisible = requires (T x) { x/=1; };

template<MustBeIncrementable T>
void my_func(T t){
    std::cout << t << std::endl;
}

template <MustBeDivisible T>
void my_divisible_func(T t) {
    std::cout << t << std::endl;
}

template <typename T> requires MustBeDivisible<T> && MustBeDivisible<T>
void my_number_func(T t){
    std::cout << t << std::endl;
}

int main(){
    my_func<std::string>("hjk");
    // my_divisible_func<std::string>("asd"); ERROR not  divisible type
    my_number_func<int>(123);
    // my_number_func<std::string>("asd"); // ERROR desn't satisfy both templates requirements

    std::vector<int> v{1,2,3,4,5,6,7,8};
    auto filtered = v | std::views::filter([](int elem){ return elem % 2 == 0;}) |
            std::views::transform([](int elem){ return elem*10;}); // views doesn't modify the object
    for (auto e : filtered) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // std::ranges::sort(v, [](int a, int b){return a > b;});
    std::ranges::sort(v, std::greater());
    for (auto e : v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // span
    std::vector<int> v_2 = {1,2,3,4,5};
    std::span<int> my_int_span = v_2;
    my_int_span[2] = 256;
    for (auto e: my_int_span){
        std::cout << e << " ";
    }
    std::cout<<std::endl;

    

}