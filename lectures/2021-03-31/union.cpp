#include <iostream>
#include <cassert>

union ipaddr_t {
    uint32_t addr;
    uint8_t octet[4];
};

void print_addr(ipaddr_t a)
{
    std::cout
        << (int)a.octet[0] << '.'
        << (int)a.octet[1] << '.'
        << (int)a.octet[2] << '.'
        << (int)a.octet[3] << " ("
        << std::hex << a.addr << std::dec << ')';
}

struct Variant {
    enum { INT, CHAR, DOUBLE } type;
    union {
        int i;
        char c;
        double d;
    };
};

void process(Variant& v)
{
    switch (v.type)
    {
    case Variant::CHAR:
        std::cout << "A char: '" << v.c << '\'';
        break;

    case Variant::DOUBLE:
        std::cout << "A double: " << v.d;
        break;

    case Variant::INT:
        std::cout << "An int: " << v.i;
        break;

    default:
        assert(false); // should never reach this point
    }

    std::cout << std::endl;
}

union X {
    struct {
        int i;
        int j;
    };

    double d;
};

int main()
{
    ipaddr_t a;
    a.addr = 0x0100007f;
    print_addr(a);
    std::cout << "\n";

    Variant v;
    v.type = Variant::INT;
    v.i = 42;
    process(v);
    v.type = Variant::CHAR;
    v.c = 'a';
    process(v);
}