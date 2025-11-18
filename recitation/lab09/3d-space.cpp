/*
Author: Nicolas Araya
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Lab 9A-E

*/
/// comment grade
#include <iostream>
#include <cmath>
using namespace std;

class Coord3D {
public:
    double x;
    double y;
    double z;
};

// TASK A
double length(Coord3D *p) {
    return sqrt(p->x*p->x + p->y*p->y + p->z*p->z);
}

// TASK B
Coord3D* fartherFromOrigin(Coord3D *p1, Coord3D *p2) {
    if (length(p1) > length(p2)) {
        return p1;
    } else {
        return p2;
    }
}

// TASK C
void move(Coord3D *ppos, Coord3D *pvel, double dt) {
    ppos->x += pvel->x * dt;
    ppos->y += pvel->y * dt;
    ppos->z += pvel->z * dt;
}

// allocate memory and initialize
Coord3D* createCoord3D(double x, double y, double z) {
    Coord3D *p = new Coord3D;
    p->x = x;
    p->y = y;
    p->z = z;
    return p;
}

// free memory
void deleteCoord3D(Coord3D *p) {
    delete p;
}

int main() {
    double x, y, z;

    cout << "Enter position: ";
    cin >> x >> y >> z;
    Coord3D *ppos = createCoord3D(x, y, z);

    cout << "Enter velocity: ";
    cin >> x >> y >> z;
    Coord3D *pvel = createCoord3D(x, y, z);

    move(ppos, pvel, 10.0);

    cout << "Coordinates after 10 seconds: "
         << ppos->x << " " << ppos->y << " " << ppos->z << endl;

    deleteCoord3D(ppos);
    deleteCoord3D(pvel);

    return 0;
}
