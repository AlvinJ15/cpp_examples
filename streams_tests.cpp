#include <iostream>
#include <fstream>
#include <sstream>

void file_streams(){
    std::fstream fs{"my_file.txt"};
    int number;
    char c;
    std::string s;

    while(fs >> std::noskipws >> c) {
        std::cout << c;
    }
    fs = std::fstream{"my_file.txt"};
    while(fs){
        //std::getline(fs, s);
        //std::cout << s << std::endl;
        fs >> number;
        if (fs)
            std::cout << number << std::endl;
    }

    std::fstream fs_out{"my_output_file", std::ios::out};
    // std::fstream fs_out{"my_output_file", std::ios::app}; // append to existing file
    fs_out << "hola" << std::endl;
    fs_out << "123" << std::endl;
    fs_out << "456" << std::endl;
}

void string_streams(){
    std::stringstream ss{"Hello world LAST"};
    std::cout << ss.str() << std::endl;
    std::string s1, s2, s3;
    ss >> s1 >> s2;
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    ss >> s3;
    std::cout << s3 << std::endl;

    std::stringstream ss_2;
    ss_2 << "Holi";
    ss_2 << " Boli"g;
    std::cout << ss_2.str() << std::endl;
}

int main(){
    file_streams();
    string_streams();
}