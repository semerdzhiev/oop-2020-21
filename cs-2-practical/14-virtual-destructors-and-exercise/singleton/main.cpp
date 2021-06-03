#include <iostream>
#include<fstream>

class Repository {
public:
    Repository(const Repository &) = delete;

    Repository &operator=(const Repository &) = delete;

    static Repository &get() {
        static Repository instance;
        return instance;
    }

    static void open(const std::string &s) {
        get().iOpen(s);
    }

    static void close() {
        get().iClose();
    }

    static void write(uint8_t c) {
        get().iWrite(c);
    }

    static uint8_t read() {
        return get().iRead();
    }

private:
    explicit Repository() = default;

    std::fstream file;
    std::string path;

    void iOpen(const std::string &_path) {
        path = _path;
        file.open(path, std::ios::out | std::ios::in | std::ios::ate | std::ios::binary);
        if (!file)
            throw std::runtime_error("File not opened successfully");
    }

    void iClose() {
        file.close();
    }

    void iWrite(uint8_t c) {
        if (!file.good())
            throw std::runtime_error("Error before write!");
        file.write((const char *) &c, sizeof(uint8_t));
        if (!file.good())
            throw std::runtime_error("Error at write!");
    }

    uint8_t iRead() {
        if (!file.good())
            throw std::runtime_error("Error before read!");
        uint8_t c;
        file.seekg(0,std::ios::beg);
        file.read((char *) &c, sizeof(uint8_t));
        if (!file.good())
            throw std::runtime_error("Error at read!");
        return c;
    }

    ~Repository() {
        file.close();
    }
};

int main() {
//    std::fstream file;
//    file.open("file.bin", std::ios::out | std::ios::in | std::ios::ate);
//    if (!file)
//        throw std::runtime_error("Error with file opening!");
//    uint8_t a[3] = {'a', 'b', 'c'};
//    file.write((const char *) &a, sizeof(char) * 3);
//    if (!file.good())
//        throw std::runtime_error("Error after writing!");
//    file.seekg(0, std::ios::beg);
//    uint8_t c[3];
//    file.read((char *) c, sizeof(uint8_t) * 3);
//    if (!file.good())
//        throw std::runtime_error("Error after reading!");
//    file.close();
//    for (unsigned char i : c)
//        std::cout << i << ' ';
//    std::cout << '\n';

    Repository::open("file.bin");
    uint8_t c = 'A',b;
    Repository::write(c);
    b = Repository::read();
    std::cout<<b;
    return 0;
}
