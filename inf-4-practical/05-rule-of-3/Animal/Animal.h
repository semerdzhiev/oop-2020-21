

#ifndef UNTITLED1_ANIMAL_H
#define UNTITLED1_ANIMAL_H


class Animal
{
public:
    Animal();
    Animal(const char* name, const char* type, unsigned int age, double lifespan);
    Animal(const Animal& rhs);
    Animal& operator=(const Animal& rhs);
    ~Animal();

    const char *getName() const;
    const char* getType() const;
    unsigned int getAge() const;
    double getLifespan() const;

    void setName(const char *name);
    void setType(const char *type);
    void setAge(unsigned int age);
    void setLifespan(double lifespan);

private:
    char* name;
    char* type;
    unsigned int age;
    double lifespan;

    void copy(const Animal& rhs);
};


#endif //UNTITLED1_ANIMAL_H
