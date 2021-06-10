#pragma once
#include"Furniture.h"
enum class TableType {
   LivingRoom=0,
   Kitchen
};
class Table : public Furniture{
public:
    const TableType type;
    Table(unsigned int ID=0, unsigned int width=0,
              unsigned int height=0, unsigned int length=0,
              int quantity = 0, float price =0.f,
              TableType type=TableType::LivingRoom);
    void print(std::ostream& os) const override;
    void toFile(std::ofstream& os) const override;
    FurnitureType getType() const override;
    void toFileBinary(std::ostream &os) const;
};
