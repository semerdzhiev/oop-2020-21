#pragma once
#include<iostream>
#include<fstream>

enum class FurnitureType {
    Bed = 0,
    Chair,
    Table
};

class Furniture {
protected:
    int quantity;
    float price;

public:
    const unsigned int ID;
    const unsigned int width,height,length;
    bool operator==(const Furniture& other) const;
    bool operator!=(const Furniture& other) const;
    Furniture(unsigned int ID=0, unsigned int width=0,
              unsigned int height=0, unsigned int length=0,
              int quantity = 0, float price =0.f);
    int getQuantity() const;
    float getPrice() const;
    void setQuantity(int quantity);
    void setPrice(float price);

    virtual void print(std::ostream&) const = 0;
    virtual void toFile(std::ofstream& os) const= 0;
    virtual FurnitureType getType() const= 0;

    virtual void toFileBinary(std::ostream& os) const = 0;

    virtual ~Furniture() = default;
};
