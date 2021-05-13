#include <iostream>
#include <fstream>
#include <cstring>
#include "Song.h"

/*
 * TODO implement playlist interface and put all file operations there
 * Check if file operation succeeded
*/

int32_t findSong(std::fstream &fd, const char* name) {
    fd.seekp(0, std::ios::beg);
    uint32_t len = strlen(name);

    int32_t  idx = -1;
    char *songTitle;
    uint32_t size;

    while (fd) {
        idx = fd.tellg();

        fd.read((char*)&size, sizeof(size));

        if (fd.eof()) {
            return -1;
        }

        if (size != len) {
            fd.seekp(size, std::ios::cur);
            fd.read((char*)&size, sizeof(size));
            fd.seekp(size + 2 * sizeof(uint32_t), std::ios::cur);

            continue;
        }

        songTitle = new char [size];
        fd.read(songTitle, size);

        if (strcmp(songTitle, name) == 0) {
            delete [] songTitle;
            return idx;
        }
        delete [] songTitle;

        fd.read((char*)&size, sizeof(size));

        fd.seekp(size + 2 * sizeof(uint32_t), std::ios::cur);
    }

    return -1;
}

void deleteSong(std::fstream& fd, const char *songName) {
    int32_t pos = findSong(fd, songName);

    if (pos == -1) {
        return;
    }

    std::fstream temp("temp", std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);

    fd.seekp(0, std::ios::beg);

    uint32_t len;
    char *buff;
    uint32_t size, time;

    while (pos != fd.tellg()) {
        fd.read((char*)&len, sizeof(len));
        temp.write((const char*)&len, sizeof(len));

        buff = new char[len];
        fd.read(buff, len);
        temp.write(buff, len);

        delete [] buff;

        fd.read((char*)&len, sizeof(len));
        temp.write((const char*)&len, sizeof(len));

        buff = new char[len];
        fd.read(buff, len);
        temp.write(buff, len);
        delete [] buff;

        fd.read((char*)&size, sizeof(size));
        temp.write((const char*)&size, sizeof(size));

        fd.read((char*)&time, sizeof(time));
        temp.write((const char*)&time, sizeof(time));
    }

    fd.read((char*)&len, sizeof(len));
    fd.seekp(len, std::ios::cur);

    fd.read((char*)&len, sizeof(len));
    fd.seekp(len + 2 * sizeof(uint32_t), std::ios::cur);

    temp << fd.rdbuf();

    fd.close();

    fd.open("song", std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);

    temp.seekp(0, std::ios::beg);

    fd << temp.rdbuf();

    temp.close();
    std::remove("temp");
}

void output(std::fstream& fd) {
    fd.seekp(0, std::ios::beg);

    uint32_t len;
    char *buff;
    uint32_t size, time;

    while (fd) {
        fd.read((char*)&len, sizeof(len));

        if (fd.eof()) break;

        buff = new char[len];
        fd.read(buff, len);

        std::cout << buff << std::endl;

        delete [] buff;

        fd.read((char*)&len, sizeof(len));
        buff = new char[len];
        fd.read(buff, len);

        std::cout << buff << std::endl;

        delete [] buff;

        fd.read((char*)&size, sizeof(size));
        fd.read((char*)&time, sizeof(time));

        std::cout << size << " " << time << std::endl;
    }
    fd.clear();
}

int main() {
    std::fstream fd("song", std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);

    Song song("The Beatles", "yesterday", 300, 120);
    Song song1("The Beatles", "yesterday1", 300, 120);
    Song song2("The Beatles", "yesterday3", 300, 120);

    song.save(fd);
    song1.save(fd);
    song2.save(fd);

    std::cout << "\nBefore delete\n" <<  std::endl;

    output(fd);

    deleteSong(fd, "yesterday1");

    std::cout << "\nAfter delete\n" <<  std::endl;

    output(fd);

    fd.close();

    return 0;
}
