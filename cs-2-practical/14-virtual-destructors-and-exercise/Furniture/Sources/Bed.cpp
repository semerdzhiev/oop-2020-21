//
// Created by petko on 03/06/2021.
//

#include "../Headers/Bed.h"

Bed::Bed(unsigned int ID, unsigned int width, unsigned int height,
             unsigned int length, int quantity,
             float price) : Furniture(ID, width, height,
                                      length, quantity, price){}

void Bed::print(std::ostream &os) const {
    os<<"Bed: "<<ID<<' '<<width<<' '<<height<<' ' <<length<<' '<<quantity<<' '
      <<price<<' '<<std::endl;
}

void Bed::toFile(std::ofstream &os) const {
    os<<"Bed: "<<ID<<' '<<width<<' '<<height<<' ' <<length<<' '
    <<quantity<<' '<<price<<' '<<std::endl;
}

FurnitureType Bed::getType() const {
    return FurnitureType::Bed;
}

void Bed::toFileBinary(std::ostream &os) const {
    os.write((const char*)FurnitureType::Bed,sizeof(FurnitureType));
    os.write((const char*)(this),sizeof(Bed));
}