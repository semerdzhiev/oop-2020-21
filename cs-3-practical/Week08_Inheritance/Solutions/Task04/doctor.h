#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
#include <string.h>

class Doctor
{
    char *name;

protected:
    void copy(const char *name);

public:
    Doctor();
    Doctor(const char *name);
    Doctor(Doctor const &otherDoctor);
    Doctor &operator=(Doctor const &otherDoctor);
    virtual ~Doctor();

    virtual void operation();

    char *getName() const { return this->name; }
};

#endif /* ifndef DOCTOR_H */
