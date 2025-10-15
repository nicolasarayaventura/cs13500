/*
Author: Nicolas Araya Ventura
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Homework e3.5

Write a program that reads three numbers and prints “increasing” if they are in
increasing order, “decreasing” if they are in decreasing order, and “neither” otherwise. Here, “increasing” means “strictly increasing”, with each value larg
*/
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "Enter three numbers: ";
    cin >> a >> b >> c;

    if (a < b && b < c)
        cout << "increasing" << endl;
    else if (a > b && b > c)
        cout << "decreasing" << endl;
    else
        cout << "neither" << endl;

    return 0;
}
