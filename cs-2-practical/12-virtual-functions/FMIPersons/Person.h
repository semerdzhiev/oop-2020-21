#pragma once
//abstract class
class Person {
protected:
    char* name;
    char* ucn;
public:
    Person(const char* name, const char* ucn);
    ~Person();
    Person(const Person& other) = delete;
    Person& operator=(const Person& other) = delete;
    virtual void printJobTittle()=0;

    const char* getName() const;
    const char* getUCN() const;
};


