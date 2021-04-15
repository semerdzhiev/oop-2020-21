#include <iostream>

#include "../Headers/ServerCluster.h"

ServerCluster::ServerCluster() {
    capacity = 2;
    size = 0;
    cluster = new Server[capacity];
}

ServerCluster::ServerCluster(const ServerCluster &other) {
    capacity = other.capacity;
    size = other.size;

    cluster = new Server[capacity];
    for (int i = 0; i < size; ++i) {
        cluster[i] = other.cluster[i];
    }
}

ServerCluster &ServerCluster::operator=(const ServerCluster &other) {
    if (this != &other) {
        ServerCluster temp(other);
        std::swap(capacity, temp.capacity);
        std::swap(size, temp.size);
        std::swap(cluster, temp.cluster);
    }

    return *this;
}

ServerCluster::~ServerCluster() {
    delete [] cluster;
}

ServerCluster& ServerCluster::addServer(const Server& server) {
    if (size == capacity) {
        capacity *= 2;
        resize();
    }

    cluster[size] = server;
    size += 1;

    return *this;
}

ServerCluster &ServerCluster::operator-=(const Server &server) {
    int index = -1;

    for (int i = 0; i < size; ++i) {
        if (cluster[i] == server) {
            index = i;
            break;
        }
    }

    for (int i = index; i < size -1; ++i) {
        cluster[i] = cluster[i + 1];
    }

    size -= 1;

    if (capacity * 0.3 >= size) {
        capacity /= 2;
        resize();
    }

    return *this;
}

void ServerCluster::print() const {
    std::cout << "Cluster" << std::endl;

    for (int i = 0; i < size; ++i) {
        cluster[i].print();
    }
}

unsigned ServerCluster::countInNetwork(int ip[]) const {
    unsigned  count = 0;

    for (int i = 0; i < size; ++i) {
        if (cluster[i].sameNetwork(ip)) {
            ++count;
        }
    }

    return count;
}

void ServerCluster::findMaxNetwork() const {
    if (size == 0) {
        std::cout << "No networks" << std::endl;
        return;
    }

    unsigned maxCount = 0;
    int ip[4] = {0, 0, 0, 0};

    for (int i = 0; i < size; ++i) {
        unsigned count = countInNetwork(cluster[i].IP4Address);
        if (maxCount < count) {
            maxCount = count;
            ip[0] = cluster[i].IP4Address[0];
            ip[1] = cluster[i].IP4Address[1];
            ip[2] = cluster[i].IP4Address[2];
        }
    }

    std::cout << "Max servers in network: " << maxCount << std::endl;
    std::cout << "Network:" << ip[0] << "." << ip[1] << "." << ip[2] << ".0" << std::endl;
}

ServerCluster &ServerCluster::sort() {
    unsigned minIdx = 0;
    for (int i = 0; i < size - 1; ++i) {
        minIdx = i;
        for (int j = i + 1; j < size; ++j) {
            if (cluster[j] < cluster[minIdx]) {
                minIdx = j;
            }
        }
        std::swap(cluster[minIdx], cluster[i]);
    }

    return *this;
}

void ServerCluster::resize() {
    Server *temp = new Server[capacity];

    for (int i = 0; i < size; ++i) {
        temp[i] = cluster[i];
    }

    delete [] cluster;

    cluster = temp;
}

ServerCluster &ServerCluster::operator+=(const Server &server) {
    addServer(server);

    return *this;
}

ServerCluster &ServerCluster::addServer() {
    Server server;
    server.read();

    return addServer(server);
}