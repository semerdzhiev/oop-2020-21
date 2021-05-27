#include <iostream>
#include<fstream>

struct Student {
    char name[24] = "unknown";
    unsigned int fn = 0;
};

size_t getFileSize(std::ifstream &ifs) {
    long cur = ifs.tellg();
    ifs.seekg(0, std::ios::end);
    size_t size = ifs.tellg();
    ifs.seekg(cur, std::ios::beg);
    return size;
}

bool writeStudents(const char *path) {
    std::ofstream ofs(path, std::ios::binary | std::ios::trunc);
    if (!ofs.is_open())
        return false;
    Student students[] = {
            {"Pesho",  45460},
            {"Stefan", 45728},
            {"Ivan",   71433},
            {"Georgi", 11111}
    };

//    size_t size = sizeof(students) / sizeof(Student);
//    for (size_t i = 0; i < size; i++)
//      ofs.write((const char*) &students[i], sizeof(Student));
    ofs.write((const char *) students, sizeof(students));
    if (!ofs.good())
        return false;

    ofs.close();
    return true;
}

//чете предварително неизвестен брой студенти записани в двойчен файл
bool readStudents(const char *path) {
    std::ifstream ifs(path, std::ios::binary);
    if (!ifs.is_open())
        return false;
    size_t fileSize = getFileLen(ifs);
    if (fileSize == 0)
        return false;
    size_t objCount = fileSize / sizeof(Student);
    Student *students = new Student[objCount];

    ifs.read((char *) students, fileSize);

    if (!ifs.good())
        return false;

    for (size_t i = 0; i < objCount; i++)
        std::cout << students[i].name << ' ' << students[i].fn << std::endl;

    // Прочитаме студент на произволна позиция
    std::cout<<"Student at random pos:\n";
    ifs.seekg(std::ios::beg);
    srand(time(nullptr));
    size_t randomIndex = rand() % objCount;
    ifs.seekg(randomIndex * sizeof(Student));


    Student student;
    ifs.read((char *) &student, sizeof(Student));
    std::cout << student.name << ' ' << student.fn << std::endl;

    delete[] students;
    ifs.close();
    return true;
}

bool writeStudentsInEndOfFile(const char *path) {
    std::ofstream ofs(path, std::ios::binary | std::ios::app); // разлика с std::ios::ate
    //'app' comes from 'append' - all output will be added (appended) to the end of the file.
    // In other words you cannot write anywhere else in the file but at the end.
    //'ate' comes from 'at end' - it sets the stream position at the end of the file when you open it,
    // but you are free to move it around (seek) and write wherever it pleases you.
    if (!ofs.is_open())
        return false;
    Student students[] = {
            {"Ivo",      45260},
            {"Viktoria", 45726},
            {"Petar",    61433}
    };

    //записваме ги във файла един по един
    //size_t size = sizeof(students) / sizeof(Student);
    //for (size_t i = 0; i < size; i++)
    //ofs.write((const char*)&students[i], sizeof(Student));

    ofs.write((const char *) students, sizeof(students));

    if (!ofs.good())
        return false;

    ofs.close();
    return true;
}

// How we write numbers
void writeNumbers(const char *fileName) {
    std::ofstream ofs(fileName, std::ios::binary);
    if (!ofs.is_open())
        return;
    unsigned short n;
    std::cout << "How many numbers?\n";
    std::cin >> n;
    std::cout << "Enter numbers:\n";
    int num;
    for (unsigned short i = 0; i < n; i++) {
        std::cin >> num;
        ofs.write((const char *) &num, sizeof(int));
    }
    if (ofs.good())
        std::cout << "successfully written!\n";
    ofs.close();
}

void readNumbers(const char *fileName) {
    std::ifstream ifs(fileName, std::ios::binary);
    if (!ifs.is_open())
        return;

    int num;
    while (!ifs.eof()) {
        ifs.read((char *) &num, sizeof(int));
        if (ifs.good())
            std::cout << num << ' ';
    }
    ifs.close();
}

int main() {
    //std::cout<<sizeof(Student);
    if (writeStudents("students.bin"))
        std::cout << "successfully written!\n";
    else
        std::cout << "error while writing\n";


    std::cout << "trying to read the information ...\n";

    if (!readStudents("students.bin"))
        std::cout << "error while reading";

    if (writeStudentsInEndOfFile("students.bin"))
        std::cout << "successfully written of the end of file!\n";
    else
        std::cout << "error while writing\n";

    //Numbers example
    writeNumbers("nums.bin");
    readNumbers("nums.bin");
    return 0;
}
