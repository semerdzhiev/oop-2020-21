#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void print_file(const char* file_name)
{
    ifstream file(file_name);
    if (file.is_open())
    {
        string str;
        while (getline(file, str))
        {
            cout << str << endl;
        }
        file.close();
    }
}

void print_lines_count(const char* file_name)
{
    ifstream file(file_name);
    size_t num_lines = 0;
    string str;
    if (file.is_open())
    {
        while (getline(file, str))
        {
            num_lines++;
        }
        cout << "The number of lines is: " << num_lines << endl;
        file.close();
    }
}

void print_file_size_1(const char* file_name)
{
    ifstream file(file_name, ios::binary);
    if (file.is_open())
    {
        file.seekg(0, ios::end);
        cout << "The size in bytes is: " << file.tellg() << endl;
        file.close();
    }
}

void print_file_size_2(const char* file_name)
{
    ifstream file(file_name, ios::binary | ios::ate);
    if (file.is_open())
    {
        cout << "The size in bytes is: " << file.tellg() << endl;
        file.close();
    }
}

int main()
{
    print_file("asd.txt");
    print_file_size_1("asd.txt");
    print_file_size_2("asd.txt");
    print_lines_count("asd.txt");

    system("PAUSE");
    return 0;
}