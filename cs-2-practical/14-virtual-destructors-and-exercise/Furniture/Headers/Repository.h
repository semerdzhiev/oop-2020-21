#pragma once

#include "Furniture.h"
#include "Bed.h"
#include "Chair.h"
#include "Table.h"
#include<fstream>
#include "MyVector.h"

class Repository {
private:
    std::fstream fs;

    Repository() = default;

public:
    Repository(const Repository &) = delete;

    Repository &operator=(const Repository &) = delete;

    static void write(const Furniture &f) {
        get().iWrite(f);
    }

    static Furniture *read(unsigned long position = 0) {
        return get().iRead(position);
    }

    static void open(const std::string &path) {
        get().iOpen(path);
    }

    static void close() {
        get().iClose();
    }

    static void writeVector(MyVector<Furniture *> &vec) {
        get().iWriteVector(vec);
    }

private:
    static Repository &get() {
        static Repository instance;
        return instance;
    }

    void iOpen(const std::string &path) {
        fs.open(path, std::ios::binary | std::ios::out);
        if (!fs.is_open())
            throw std::runtime_error("Open:File not open!");
    }

    void iClose() {
        fs.close();
    }

    void iWrite(const Furniture &f) {
        if (!fs)
            throw std::runtime_error("File is not open!");
        f.toFileBinary(fs);
        if (!fs.good())
            throw std::runtime_error("Error with file");
    }

    void iWriteVector(MyVector<Furniture *> &vec) {
        for (size_t i = 0; i < vec.getSize(); ++i)
            iWrite(*(vec[i]));
    }

    Furniture *iRead(unsigned long position) {
        if (!fs)
            throw std::runtime_error("File is not open!");
        fs.seekg(std::ios::beg);
        for (unsigned long i = 0; i < position; ++i) {
            FurnitureType type;
            fs.read((char *) &type, sizeof(FurnitureType));
            switch (type) {
                case FurnitureType::Bed :
                    fs.seekg(sizeof(Bed), std::ios::cur);
                    break;
                case FurnitureType::Chair :
                    fs.seekg(sizeof(Chair), std::ios::cur);
                    break;
                case FurnitureType::Table :
                    fs.seekg(sizeof(Table), std::ios::cur);
                    break;
            }
        }
        FurnitureType type;
        fs.read((char *) &type, sizeof(FurnitureType));
        switch (type) {
            case FurnitureType::Bed : {
                Furniture *furniture = new Bed();
                fs.read((char *) furniture, sizeof(Bed));
                return furniture;
            }
            case FurnitureType::Chair : {
                Furniture *furniture = new Chair();
                fs.read((char *) furniture, sizeof(Chair));
                return furniture;
            }
            case FurnitureType::Table : {
                Furniture *furniture = new Table();
                fs.read((char *) furniture, sizeof(Table));
                return furniture;
            }
        }
    }
};