#pragma once

#include"Furniture.h"

enum class ChairType {
    Wood = 0,
    Metal,
    Plastic
};

class Chair : public Furniture {
public:
    const ChairType type;

    Chair(unsigned int ID = 0, unsigned int width = 0,
          unsigned int height = 0, unsigned int length = 0,
          int quantity = 0, float price = 0.f,
          ChairType type = ChairType::Wood);

    void print(std::ostream &os) const override;

    void toFile(std::ofstream &os) const override;

    FurnitureType getType() const  override;
    void toFileBinary(std::ostream &os) const;
};
