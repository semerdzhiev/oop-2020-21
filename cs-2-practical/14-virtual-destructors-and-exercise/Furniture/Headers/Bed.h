#pragma once
#include"Furniture.h"
class Bed : public Furniture{
public:
    Bed(unsigned int ID=0, unsigned int width=0,
          unsigned int height=0, unsigned int length=0,
          int quantity = 0, float price =0.f);
    void print(std::ostream& os) const override;
    void toFile(std::ofstream& os) const override;
    FurnitureType getType() const override;
};

