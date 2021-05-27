
#include <cstring>
#include "Song.h"

Song::Song(const char *author, const char *title, uint32_t size, uint32_t time)
        : size(size), time(time) {

    this->author = new char[strlen(author)];
    strcpy(this->author, author);
    this->title = new char[strlen(title)];
    strcpy(this->title, title);
}

Song::~Song() {
    delete [] author;
    delete [] title;
}

void Song::save(std::fstream &fd) {
    fd.seekp(0, std::ios::end);

    uint32_t len = strlen(title);
    fd.write((const char*)&len, sizeof(len));
    fd.write(title, len);

    len = strlen(author);
    fd.write((const char*)&len, sizeof(len));
    fd.write(author, len);

    fd.write((const char *)&size, sizeof(size));
    fd.write((const char *)&time, sizeof(time));
}

