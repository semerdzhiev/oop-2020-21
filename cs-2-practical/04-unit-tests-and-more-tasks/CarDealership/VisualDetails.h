#pragma once

#define MAX_SIZE 50

class VisualDetails {
private:
    unsigned int doorCount;
    bool hasWing;
    char color[MAX_SIZE+1];
public:
    VisualDetails();
    VisualDetails(const char* _color,unsigned int _doorCount=3,bool _hasWing=false);

    void print() const;
    void readFromConsole();

    void setColor(const char* _color);
    void setWing(bool _wing);
};