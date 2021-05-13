#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string buffer;

    std::ifstream file("task1.cpp");

    if(!file.is_open()) 
    {
        std::cout<<"Cannot open file" << std::endl;
        return -1;
    }

    std:: cout << "First way: " << std::endl;

    while(!file.eof()) 
    {
        file >> buffer;
        std:: cout << buffer;    
    }

    std:: cout << std::endl << "Second way: " << std::endl;
    file.seekg(0, std::ios::beg);

    while(!file.eof())
    {
        getline(file, buffer);
        std:: cout << buffer;
    }
    
    std:: cout << std::endl << "Third way: " << std::endl;
    file.seekg(0, std::ios::beg);

    char c;

    while(!file.eof())
    {
        file.get(c);
        std:: cout << c;
    }

    std::cout<<std::endl;

    file.close();

    return 0;
}