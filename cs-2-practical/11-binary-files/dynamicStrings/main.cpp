#include <fstream>
#include <iostream>
#include <cstring>


const int MAXN = 1024;

struct Student {

    char *name = nullptr;
    unsigned int fn = 0;

    Student(char *name = nullptr, unsigned int fn = 0) {
        throw std::exception("dadadd");
        copy((*this), name, fn);
    }

    static void copy(Student &s, char *name, unsigned int fn) {
        if (name != nullptr) {
            s.name = new char[strlen(name) + 1];
            strcpy(s.name, name);
            s.fn = fn;
        }
    }

    void free() {
        delete[] name;
        name = nullptr;
    }

    ~Student() {
        free();
    }
};

void readStudentFromStdin(Student &s) {
    char buff[MAXN];
    std::cout << "enter name: ";
    std::cin.get();
    std::cin.getline(buff, MAXN);
    unsigned int fn;
    std::cin >> fn;
    s.free();
    Student::copy(s, buff, fn);
}

void writeStudentToStdout(const Student &s) {
    std::cout << s.name << ' ' << s.fn << '\n';
}


void writeStudentToFile(const Student &s, std::ofstream &ofs) {
    ofs.write((const char *) &s.fn, sizeof(unsigned int));

    size_t len = strlen(s.name);
    ofs.write((const char *) &len, sizeof(size_t));

    //съдържанието на стринга
    ofs.write(s.name, len * sizeof(char)); //len * sizeof(char) -> len
}

void readStudentFromFile(Student &s, std::ifstream &ifs) {
    s.free();
    ifs.read((char *) &s.fn, sizeof(unsigned int));
    size_t len = 0;
    ifs.read((char *) &len, sizeof(size_t));
    s.name = new char[len + 1];
    ifs.read(s.name, len * sizeof(char)); //len * sizeof(char) -> len
    s.name[len] = '\0';
}


bool writeStudents(const char *path) {
    std::ofstream ofs(path, std::ios::binary | std::ios::trunc);
    if (!ofs.is_open())
        return false;
    std::cout << "how many?\n";
    size_t n;
    std::cin >> n;
    Student s;
    for (size_t i = 0; i < n; i++) {
        readStudentFromStdin(s);
        writeStudentToFile(s, ofs);
        s.free();
        if (!ofs)
            return false;
    }
    ofs.close();
    return true;
}


void readStudents(const char *path) {
    std::ifstream ifs(path, std::ios::binary);
    if (!ifs.is_open())
        return;

    while (!ifs.eof()) {
        Student s;
        readStudentFromFile(s, ifs);
        if (ifs.good())
            writeStudentToStdout(s);
        //s.free();
    }
    ifs.close();
}

int main() {
    if (writeStudents("students.bin")) {
        std::cout << "successfully written!\n";
    } else {
        std::cout << "error while writing\n";
    }
    std::cout << "trying to read the information ...\n";
    readStudents("students.bin");
    return 0;
}