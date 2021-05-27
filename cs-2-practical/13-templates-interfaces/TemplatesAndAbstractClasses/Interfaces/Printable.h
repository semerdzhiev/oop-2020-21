#pragma once
#include<fstream>

class Printable {
public:
    virtual void print(std::ostream& os) const = 0;
};
