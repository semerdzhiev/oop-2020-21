#pragma once
class Student {
public:
    Student();
    Student(unsigned int _fn,const char* _name, const char* _major, unsigned short _group);
    Student(const Student&);
    Student& operator=(const Student& other);

public:
    bool operator==(const Student& other) const;

public:
    unsigned getFacultyNumber() const;
    const char* getName() const;
    const char* getMajor() const;
    unsigned short getGroup() const;

    void setMajor(const char* newMajor);
    void setGroup(unsigned short newGroup);

public:
    void printInformation() const;
    void readFromConsole();

private:
    static bool isValidFN(unsigned int _FN) ;
    static bool isValidGroup(unsigned short _group) ;
    bool isValidMajor(const char* _major) const;

public:
    friend std::ostream& operator<<(std::ostream& os, const Student& s);
    friend std::istream &operator>>( std::istream &input, Student& s );

private:
    static const unsigned short majorN=5;
    const char* majors[majorN] = {
            "Informatics",
            "Computer Science",
            "Software Engineering",
            "Mathematics and Informatics",
            "Mathematics"
    };
private:
    unsigned int FN;
    char name[51];
    char major[33];
    unsigned short group;
};




