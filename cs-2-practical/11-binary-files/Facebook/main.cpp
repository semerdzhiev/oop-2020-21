#include <iostream>
#include<fstream>
#include "UserData.h"

bool writePictureData(std::ofstream& ofs, const PictureData& pic) {
    size_t sizeOfPic = sizeof(pic);
    ofs.write((const char*) &sizeOfPic,sizeof(size_t));
    ofs.write((const char*) &pic,sizeof(pic));
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
