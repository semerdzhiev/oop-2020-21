#include <iostream>
#include <fstream>

int main() {
    std::ifstream file1("file2", std::ios::binary);
    std::ifstream file2("file1", std::ios::binary);
    std::ofstream out("output", std::ios::binary | std::ios::trunc);

    uint32_t x, y;

    while (1) {
        file1.read((char*)&x, sizeof(x));
        if (!file1) {
            break;
        }
        file1.read((char*)&y, sizeof(y));
        file2.seekg(x * sizeof(uint32_t), std::ios::beg);

        uint32_t temp;
        for (int i = 0; i < y; ++i) {
            file2.read((char*)&temp, sizeof(temp));
            out.write((const char*)&temp, sizeof(temp));
        }
    }

    file1.close();
    file2.close();
    out.close();

    return 0;
}