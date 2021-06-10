#include "../Headers/Table.h"

Table::Table(unsigned int ID, unsigned int width, unsigned int height,
             unsigned int length, int quantity,
             float price,
             TableType type) : Furniture(ID, width, height, length, quantity, price),
                               type(type) {}

void Table::print(std::ostream &os) const{
    os<<"Table: "<<ID<<' '<<width<<' '<<height<<' ' <<length<<' '<<quantity<<' '
    <<price<<' '<<(type == TableType::LivingRoom ?
    "Living room" : "Kitchen") <<std::endl;
}

void Table::toFile(std::ofstream &os) const {
    os<<"Table: "<<ID<<' '<<width<<' '<<height<<' ' <<length<<' '<<quantity<<' '
      <<price<<' '<<(type == TableType::LivingRoom ?
      "Living room" : "Kitchen") <<std::endl;
}

FurnitureType Table::getType() const {
    return FurnitureType::Table;
}

void Table::toFileBinary(std::ostream &os) const {
    os.write((const char*)FurnitureType::Table,sizeof(FurnitureType));
    os.write((const char*)(this),sizeof(Table));
}