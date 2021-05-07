#ifndef DENTIST_H
#define DENTIST_H

#include "doctor.h"

class Dentist : public Doctor
{
    void copy(const char *name);

public:
    Dentist();
    Dentist(const char *name);
    Dentist(Dentist const &otherDentist);
    Dentist &operator=(Dentist const &otherDentist);
    ~Dentist();

    void operation() override;

    void print();
};

#endif /* ifndef DENTIST_H */