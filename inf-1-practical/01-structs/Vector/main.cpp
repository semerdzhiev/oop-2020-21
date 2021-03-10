#include <iostream>
#include <cmath>

#include "Vector.h"

using namespace std;

double len(const Vector& v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

void norm(Vector& v) {
    double size = len(v);
    v.x /= size;
    v.y /= size;
    v.z /= size;
}

void sum(Vector& v1, const Vector& v2) {
    v1.x += v2.x;
    v1.y += v2.y;
    v1.z += v2.z;
}

void sub(Vector& v1, const Vector& v2) {
    v1.x -= v2.x;
    v1.y -= v2.y;
    v1.z -= v2.z;
}

void multiply(Vector& v, int n) {
    v.x *= n;
    v.y *= n;
    v.z *= n;
}

int main() {
    Vector v1 = {1, 2, 3};
    v1.create();
    v1.print();

    norm(v1);
    v1.print();

    Vector v2;
    v2.create();

    sum(v1, v2);
    v1.print();

    Vector *v3 = new Vector;

    cout << v3->x << " " << (*v3).x;

    delete v3;

    return 0;
}
