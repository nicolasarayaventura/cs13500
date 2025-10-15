/*
Author: Nicolas Araya Ventura
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Homework e3.1

Write a program that reads an integer and prints whether it is negative, zero, or positive.
*/
#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter an integer: ";
    cin >> num;

    if (num > 0)
        cout << "The number is positive." << endl;
    else if (num < 0)
        cout << "The number is negative." << endl;
    else
        cout << "The number is zero." << endl;

    return 0;
}
