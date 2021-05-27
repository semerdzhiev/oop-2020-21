
#ifndef BINARY_SONG_H
#define BINARY_SONG_H


#include <fstream>

class Song {
public:
    Song(const char *, const char *, uint32_t, uint32_t);
    ~Song();

    void save(std::fstream& fd);
private:
    char *author;
    char *title;
    uint32_t size;
    uint32_t time;
};


#endif //BINARY_SONG_H
