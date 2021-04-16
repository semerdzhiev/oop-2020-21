#ifndef TICKET
#define TICKET

using std::ostream;
using std::istream;

class Ticket
{

private:
    const static int MAX_STRING = 128;
    static int idGen;

    int id;
    char* name;
    char* phone;


public:
    Ticket();
    Ticket(const char *name, const char *phone);
    Ticket(const Ticket &other) : Ticket(other.getName(), other.getPhone()) {};

    const int getId() const;
    const char* getName() const;
    const char* getPhone() const;

    void setName(const char* name);
    void setPhone(const char *phone);

    Ticket &operator=(const Ticket &ticket);
    friend ostream &operator<<(ostream &out, const Ticket &ticket);
    friend istream &operator>>(istream &in, Ticket &ticket);

    ~Ticket();
};


#endif