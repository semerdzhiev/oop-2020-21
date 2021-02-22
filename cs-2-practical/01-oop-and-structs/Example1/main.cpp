#include <iostream>
#include<cmath>

double distance3d(double x1, double y1, double x2, double y2, double z1, double z2) {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
}



struct Point3d {
    double x;
    double y;
    double z;
};

double distance3dWithStruct(Point3d p,Point3d q) {
    return sqrt((p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y)+(p.z-q.z)*(p.z-q.z));
}

int main() {
    Point3d p,q;
    Point3d z = {1,2,3};
    std::cin>>p.x>>p.y>>p.z>>q.x>>q.y>>q.z;
    std::cout<<distance3dWithStruct(p,q)<<std::endl;

    size_t size;
    std::cin>>size;
    Point3d *points = new Point3d[size];

    for(size_t i=0;i<size;++i) {
        std::cin>>points[i].x>>points[i].y>>points[i].z;
    }

    delete[] points;
    return 0;
}
