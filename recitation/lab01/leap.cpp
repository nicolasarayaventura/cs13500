/*
Author: Nicolas Araya Ventura
Course: CSCI-136
Instructor: 
Assignment: Lab1C

Write a program leap.cpp that asks the user to input an integer representing a year number 
(1999, 2016, etc.). If the input year is a leap year according to the modern Gregorian calendar, 
it should print Leap year, otherwise, print Common year.
*/
#include <iostream>
using namespace std;

int main() {
    cout << "Enter Year: ";
    int year;
    cin >> year;

    if (year % 400 == 0) {
        cout << "Leap year" << endl;
    }
    else if (year % 100 == 0) {
        cout << "Common year" << endl;
    }
    else if (year % 4 == 0) {
        cout << "Leap year" << endl;
    }
    else {
        cout << "Common year" << endl;
    }
return 0;
}