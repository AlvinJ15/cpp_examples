#include <iostream>
#include <vector>
#include <set>
#include <array>
#include <map>
#include <algorithm>
#include <filesystem>
#include <any>
#include <string>
#include <variant>

union MyUnion {
    int x;
    char c;
    double d;
};

int main() {
    // VECTOR
    std::cout << "VECTOR: ************************************" << std::endl;
    std::vector<int> my_vector{10, 2, 3, 4, 5};
    std::cout << my_vector[1] << std::endl;
    for (auto elem: my_vector) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::vector<std::string> my_vector_string{"Hello", "Hola", "ola"};
    for (std::string& elem: my_vector_string){
        std::cout << elem << std::endl;
    }
    std::cout << std::endl;

    // ARRAY
    std::cout << "ARRAY: ************************************" << std::endl;
    std::array<int, 4> my_array{6, 10, 18, 29};
    std::cout << *(my_array.begin()+2) << std::endl;
    for (auto elem: my_array) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // SET
    std::cout << "SET: ************************************" << std::endl;
    std::set<int> my_set{10,1,4,15};
    std::cout << *(++++my_set.begin()) << std::endl;

    // MAP
    std::cout << "MAP: ************************************" << std::endl;

    std::map<int, std::string>  my_map{{1,"a"}, {2, "b"}, {3, "c"}};
    my_map[2] = "bb";
    my_map[7000] = "abcde";
    my_map.insert({4, "d"});
    for (std::pair<const int, std::string>& elem: my_map){
    //for (auto& elem: my_map){
        elem.second+="*";
        std::cout << elem.first << " " << elem.second << std::endl;
    }
    std::cout << std::endl;
    for (auto& elem: my_map){
        elem.second+="*";
        std::cout << elem.first << " " << elem.second << std::endl;
    }
    std::cout << std::endl;

    auto it = my_map.find(4);
    if (it == my_map.end()) {
        std::cout << "NOT FOUND." << std::endl;
    }
    else {
        std::cout << "VALUEL: " << (*it).second << std::endl;
        std::cout << "VALUEL: " << it->second << std::endl;
    }

    auto it_upper = --my_map.upper_bound(4);
    if (it_upper == my_map.end()) {
        std::cout << "NOT FOUND." << std::endl;
    }
    else {
        std::cout << "VALUEL: " << (*it_upper).second << std::endl;
        std::cout << "VALUEL: " << it_upper->second << std::endl;
    }

    // ALGORITHM
    std::cout << "ALGORITHM: ************************************" << std::endl;
    std::vector<int> my_vector_2{8, 2, 13, 4, -5};

    std::sort(my_vector_2.begin(), my_vector_2.end(), std::greater<int>());
    for (auto elem: my_vector_2) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    const auto& it_find = std::find(my_vector_2.begin(), my_vector_2.end(), -5);
    if (it_find != my_vector_2.end()){
        std::cout << "VALUE FOUND: " << *it_find << std::endl;
    }
    else {
        std::cout << "VALUE NOT FOUND: " << std::endl;
    }

    // C++17
    // FileSystem
    /*std::filesystem::path folder_path = "C://MyFolder//";
    if (std::filesystem::exists(folder_path)){
        std::cout << "FOLDER EXITS" << std::endl;
    }
    else {
        std::cout << "FOLDER DOESN'T EXIST" << std::endl;
    }

    auto my_folder_2 = "C:\\MYFOLDER\\";
    for (auto el : std::filesystem::directory_iterator(my_folder_2)){
        std::cout << el.path() << std::endl; // print all files
    }*/

    // ANY
    std::any any_int = 123;
    std::cout << "INT: " << std::any_cast<int>(any_int) << std::endl;
    any_int = 12.3;
    std::cout << "DOUBLE: " << std::any_cast<double>(any_int) << std::endl;
    any_int = "abc";
    std::cout << std::any_cast<const char*>(any_int) << std::endl;

    // UNION can hold just 1 value at time
    MyUnion u;
    u.x = 4;
    std::cout << "U.x: " << u.x << std::endl;
    u.d = 56.56;
    std::cout << "U.d: " << u.d << std::endl;
    std::cout << "U.x: " << u.x << std::endl; // no value, just memory dummy
    std::variant<char, int , double> var{123};
    std::cout << "INT: " << std::get<int>(var) << " " << std::get<1>(var); // use try catch

}
