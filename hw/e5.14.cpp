/*
Author: Nicolas Araya Ventura
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Homework e5.4

Write a function void sort2(int& a, int& b) that swaps the values of a and b if a is
greater than b and otherwise leaves a and b unchanged.
*/
#include <iostream>
using namespace std;

void sort2(int& a, int& b) {
    if(a > b) {
        int swap = b;
        b = a;
        a = swap;
    } 
}

int main() {
    int a, b;

    cout << "Enter number for a: ";
    cin >> a;
    cout << "Enter number for b: ";
    cin >> b;
    
    sort2(a, b);

    cout << "a is now: " << a << endl;
    cout << "b is now: " << b << endl;

    return 0;
}