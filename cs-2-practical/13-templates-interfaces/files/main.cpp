#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {
    std::uint32_t data = 0x12345678;
    std::cout << std::setfill('0') << std::setw(8) << std::hex << data << std::endl;
    std::cout << data << '\n';
    ofstream oFile("data.bin", std::ios::ate | std::ios::binary | std::ios::in);
    if (!oFile)
        return 1;

    // uint8_t c = 70;
    // oFile.write((const char *)&c, sizeof(uint8_t));

    //tellp/seekp -> ofstream (put)
    //tellg/seekg -> ifstream (get)

    //get size
    size_t cur = oFile.tellp();
    oFile.seekp(0, std::ios::end);
    size_t size = oFile.tellp();
    oFile.seekp(cur, std::ios::beg);
    std::cout << std::dec << "Size:" << size << std::endl;

    //edit with offset
    size_t offset = 3;
    uint8_t byte = 255;
    oFile.seekp(offset, std::ios::beg);
    std::cout << oFile.tellp();
    oFile.write((const char *)&byte, sizeof(uint8_t));

    if(!oFile.good()) {
        oFile.close();
        return 1;
    }
        

    // //writing one byte to the end
    // byte = 255;
    // oFile.seekp(0, std::ios::end);
    // oFile.write((const char *)&byte, sizeof(uint8_t));

    oFile.close();

    //reading
    ifstream iFile("data.bin", std::ios::binary);
    offset = 3;
    size_t limit = 6;
    iFile.seekg(offset, std::ios::beg);
    uint8_t *arr = new uint8_t[limit];
    // for (int i = 0; i < limit; i++)
    //     iFile.read((char *)&arr[i], sizeof(uint8_t));
    iFile.read((char *)arr, sizeof(uint8_t) * limit);
    iFile.close();
    std::cout << "\n--------------------\n";
    std::cout << std::setfill('0') << std::setw(8) << std::hex << offset << ' ';
    for (int i = 0; i < limit; ++i)
        std::cout << std::setfill('0') << std::setw(2) << std::hex << (int)arr[i] << ' ';
    std::cout << '\n';
    delete[] arr;
    return 0;
}
