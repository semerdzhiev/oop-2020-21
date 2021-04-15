#include <iostream>
#include "Headers/Server.h"
#include "Headers/ServerCluster.h"

int main() {
    Server s1, s2, s3, s4;
    s1.read();
    s2.read();
    s3.read();
    s4.read();

    ServerCluster cluster;

    cluster.addServer(s1).print();
    cluster.addServer(s2).addServer(s3).addServer(s4);

    cluster.findMaxNetwork();

    std::cout << std::endl << "Sorting" << std::endl;
    cluster.sort().print();

    ((cluster -= s3) -= s2).print();

    cluster.addServer();

    return 0;
}
