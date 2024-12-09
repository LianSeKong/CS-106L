#include<iostream>
#include<string>
#include<fstream>
int main() {
    std::string str;
    std::ifstream ifs("./README.md");
    if (ifs.is_open()) {
        std::cout << "open\n";
        while(std::getline(ifs, str)) {
            std::cout << str << "\n";
        }

    }

}