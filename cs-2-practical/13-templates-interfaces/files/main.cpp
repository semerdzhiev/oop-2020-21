#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    std::uint32_t data = 0x1234567;
    std::cout << std::setfill('0') << std::setw(8) << std::hex << data << std::endl;
    std::cout << data << '\n';
    ofstream oFile("data.bin", std::ios::ate | std::ios::binary | std::ios::in);
    if (!oFile)
        return 1;

    // char c = 69;
    // oFile.write((const char *)&c, sizeof(char));

    //get size
    long cur = oFile.tellp();
    oFile.seekp(0, std::ios::end);
    size_t size = oFile.tellp();
    oFile.seekp(cur, std::ios::beg);
    std::cout << size;

    //edit with offset
    size_t offset = 1;
    uint8_t byte = 88;
    oFile.seekp(offset, std::ios::beg);
    std::cout << oFile.tellp();
    oFile.write((const char *)&byte, sizeof(uint8_t));

    // //writing one byte to the end
    // byte = 255;
    // oFile.seekp(0, std::ios::end);
    // oFile.write((const char *)&byte, sizeof(uint8_t));

    oFile.close();

    //reading
    ifstream iFile("data.bin", std::ios::binary | std::ios::in);
    offset = 3;
    size_t limit = 5;
    iFile.seekg(offset, std::ios::beg);
    uint8_t *arr = new uint8_t[limit];
    for (int i = 0; i < limit; i++)
        iFile.read((char *)&arr[i], sizeof(uint8_t));
    iFile.close();
    std::cout << "\n--------------------\n";
    std::cout << std::setfill('0') << std::setw(8) << std::hex << offset << ' ';
    for (int i = 0; i < limit; ++i)
        std::cout << std::setfill('0') << std::setw(2) << std::hex << (int)arr[i] << ' ';
    std::cout << '\n';
    delete[] arr;
    return 0;
}
