/*
Author: Nicolas Araya
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Lab 5A

Write a program numbers.cpp that defines a function

bool isDivisibleBy(int n, int d);
If n is divisible by d, the function should return true, otherwise return false.
*/
#include <iostream>
using namespace std;

// Function that checks if n is divisible by d
bool isDivisibleBy(int n, int d) {
    if (d == 0) { 
        return false;  // cannot divide by zero
    }
    return n % d == 0; // concise version
}

int main() {
    int n, d;

    cout << "Enter number to divide: ";
    cin >> n;
    cout << "Enter number to divide by: ";
    cin >> d;
    
    if (isDivisibleBy(n, d)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
