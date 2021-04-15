#pragma once

#include "Server.h"

class ServerCluster {
public:
    ServerCluster();
    ServerCluster(const ServerCluster& other);
    ServerCluster& operator=(const ServerCluster& other);
    ~ServerCluster();

    ServerCluster& addServer(const Server &server);
    ServerCluster& addServer();
    ServerCluster& operator-=(const Server& server);
    ServerCluster& operator+=(const Server& server);
    void print() const;

    unsigned countInNetwork(int ip[]) const;
    void findMaxNetwork() const;
    ServerCluster& sort();

private:
    Server *cluster;
    unsigned size;
    unsigned capacity;

    void resize();
};
