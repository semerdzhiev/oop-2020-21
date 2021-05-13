#include <iostream>
#include <fstream>

int main() {
    std::ifstream in("text");
    std::cout << in.tellg() << std::endl;
    in.seekg(0, std::ios::end);
    std::cout << in.tellg() << std::endl;

    char buff[256];
    int lines = 0;
    int chars = 0;

    if (in) {
        while (in.get(buff, 256)) {
            std::cout << buff << std::endl;
        }
    }

    std::cout << std::endl << lines << " " << chars << std::endl;

    in.close();

    return 0;
}
