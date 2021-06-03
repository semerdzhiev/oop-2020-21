#include "repository.h"
#include <fstream>

using std::ofstream;
using std::ifstream;

Repository *Repository::instance = 0;

Repository::Repository()
{
    out = new ofstream("data.txt", std::ios::out);
    in = new ifstream("data.txt", std::ios::in);
}

Repository::~Repository()
{
    ((ofstream*) out)->close();
    ((ifstream *) in)->close();
}

Repository *Repository::getInstance()
{
    if (!instance) {
        instance = new Repository();
    }
    return instance;
}

istream *Repository::getInput()
{
    return in;
}

ostream *Repository::getOutput() 
{
    return out;
}