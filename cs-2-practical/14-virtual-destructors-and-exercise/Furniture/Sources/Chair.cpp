#include "../Headers/Chair.h"
Chair::Chair(unsigned int ID, unsigned int width, unsigned int height,
             unsigned int length, int quantity,
             float price,
             ChairType type) : Furniture(ID, width, height, length, quantity, price),
                               type(type) {}

void Chair::print(std::ostream &os) const {
    os<<"Chair: "<<ID<<' '<<width<<' '<<height<<' ' <<length<<' '<<quantity<<' '
      <<price<<' '<<(type == ChairType::Wood ?
                     "Wood" : type==ChairType::Metal ? "Metal" : "Plastic")
                     <<std::endl;
}

void Chair::toFile(std::ofstream &os) const{
    os<<"Chair: "<<ID<<' '<<width<<' '<<height<<' ' <<length<<' '<<quantity<<' '
      <<price<<' '<<(type == ChairType::Wood ?
                     "Wood" : type==ChairType::Metal ? "Metal" : "Plastic")
                     <<std::endl;
}

FurnitureType Chair::getType() const {
    return FurnitureType::Chair;
}