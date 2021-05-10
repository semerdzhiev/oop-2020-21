#include <fstream>
#include <iostream>
#include <cstring>

const int MAXN = 1024;

struct Student {
    char *name = nullptr;
    unsigned int fn = 0;
};

void freeStudentMem(Student &s) {
    delete[] s.name;
    s.name = nullptr;
}

void readStudentFromStdin(Student &s) {
    char buff[MAXN];
    std::cout << "enter name: ";
    std::cin.get();
    std::cin.getline(buff, MAXN);
    size_t inputLen = strlen(buff);
    s.name = new char[inputLen + 1];
    strcpy(s.name, buff);
    std::cout << "enter fn: ";
    std::cin >> s.fn;
}

void writeStudentToStdout(const Student &s) {
    std::cout << s.name << ' ' << s.fn << '\n';
}


void writeStudentToFile(const Student &s, std::ofstream &ofs) {
    ofs.write((const char *) &s.fn, sizeof(unsigned int));

    size_t len = strlen(s.name);
    //след това размера на стринга
    ofs.write((const char *) &len, sizeof(size_t));

    //съдържанието на стринга
    ofs.write(s.name, len); //len * sizeof(char) -> len
}

void readStudentFromFile(Student &s, std::ifstream &ifs) {
    ifs.read((char *) &s.fn, sizeof(unsigned int));
    size_t len = 0;
    ifs.read((char *) &len, sizeof(size_t));
    delete[] s.name;
    s.name = new char[len + 1];
    ifs.read(s.name, len); //len * sizeof(char) -> len
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
        freeStudentMem(s);
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
    Student s;
    while (!ifs.eof()) {
        readStudentFromFile(s, ifs);
        if (ifs)
            writeStudentToStdout(s);
        freeStudentMem(s);
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