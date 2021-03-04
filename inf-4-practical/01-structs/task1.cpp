#include <iostream>
#include <cmath>

using namespace std;

struct vector {
    double x;
    double y;
    double z;
};

struct struct1 {
    double x;
    char y1;
    double y;
    char z2;
    double z;
};

struct __attribute__((__packed__)) struct2 {
    double x;
    char y1;
    double y;
    char z2;
    double z;
};

void create(vector& v) {
    cin >> v.x;
    cin >> v.y;
    cin >> v.z;
}

void print(const vector& v) {
    cout << "vector: " << v.x << " " << v.y << " " << v.z << endl; 
}

double len(const vector& v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

void sub(vector& v, const vector& v1, const vector& v2) {
    v.x = v1.x + v2.x;
    v.y = v1.y + v2.y;
    v.z = v1.z + v2.z;
}

void norm(vector& v) {
    double size = len(v);

    v.x /= size;
    v.y /= size;
    v.z /= size;
}

void scalar(vector& v, double n) {
    v.x *= n;
    v.y *= n;
    v.z *= n;
}

int main() {
    cout << sizeof(vector) << endl;
    cout << sizeof(struct1) << endl;
    cout << sizeof(struct2) << endl;
    
    vector v;
    create(v);
    print(v);
    
    norm(v);
    print(v);

    vector v1 = {2, 4, 5};
    vector v2;
    v2.x = 1;
    v2.y = 1;
    v2.z = 1;

    sub(v2, v, v1);
    print(v2);

    vector *v3 = &v1;
    
    cout << v3->x << endl;
    cout << (*v3).x << endl;
    
    v3 = new vector;

    cout << v3->x << endl;

    delete v3;

    return 0;
}
