/*
Author: Nicolas Araya
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Lab 9F
bonus 
*/
/// comment grade
// 
//
//
//
#include <iostream>
#include <cmath>
using namespace std;

class Coord3D {
public:
    double x;
    double y;
    double z;
};

class Particle {
public:
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
};

Particle* createParticle(double x, double y, double z, double vx, double vy, double vz) {
    Particle *p = new Particle();
    p->x = x;
    p->y = y;
    p->z = z;
    p->vx = vx;
    p->vy = vy;
    p->vz = vz;
    return p;
}

void setVelocity(Particle *p, double vx, double vy, double vz) {
    p->vx = vx;
    p->vy = vy;
    p->vz = vz;
}

Coord3D getPosition(Particle *p) {
    Coord3D cord = {p->x, p->y, p->z};
    return cord;
}

void move(Particle *p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

void deleteParticle(Particle *p) {
    delete p;
}

int main() {
    Particle *p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
    double time = 0.0;
    double dt = 0.1;

    while (time < 3.0) {
        setVelocity(p, 10.0 * time, 0.3, 0.1);

        move(p, dt);
        time += dt;

        cout << "Time: " << time << " \t";
        cout << "Position: " 
             << getPosition(p).x << ", "
             << getPosition(p).y << ", "
             << getPosition(p).z 
             << endl;
    }

    deleteParticle(p);
}
