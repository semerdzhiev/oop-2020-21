#pragma once

struct Server {
    int IP4Address[4];
    unsigned hdd;
    unsigned ram;
    float frequency;
    char os[21];

    bool operator<(const Server& other) const;
    bool operator==(const Server& other) const;

    bool sameNetwork(int ip[]);

    void print() const;
    void read();
};
