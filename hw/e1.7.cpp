/*
Author: Nicolas Araya Ventura
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Homework e1.7

Write a program that prints three items, such as the names of your three best friends
or favorite movies, on three separate lines.
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name1, name2, name3;

    cout << "Enter your friend's name: ";
    cin >> name1;
    cin >> name2;
    cin >> name3;

    cout << name1 << endl;
    cout << name2 << endl;
    cout << name3 << endl;

    return 0;
}

