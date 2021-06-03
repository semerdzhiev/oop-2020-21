#pragma once
#include <fstream>

using std::istream;
using std::ostream;

class Repository
{
    static Repository *instance;
    ostream* out;
    istream* in;

    Repository();
    ~Repository();

public:
    static Repository *getInstance();
    istream *getInput();
    ostream *getOutput();
};