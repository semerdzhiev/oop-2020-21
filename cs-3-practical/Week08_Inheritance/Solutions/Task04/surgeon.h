#ifndef SURGEON_H
#define SURGEON_H

#include "doctor.h"

class Surgeon : public Doctor
{
    void copy(const char *name);

public:
    Surgeon();
    Surgeon(const char *name);
    Surgeon(Surgeon const &otherSurgeon);
    Surgeon &operator=(Surgeon const &otherSurgeon);
    ~Surgeon();

    void operation() override;

    void print();
};

#endif /* ifndef SURGEON_H */