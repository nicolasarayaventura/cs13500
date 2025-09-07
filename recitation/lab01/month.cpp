/*
Author: Nicolas Araya Ventura
Course: CSCI-136
Instructor: 
Assignment: Lab1D

Write a program month.cpp that asks the user to input the year and the month (1-12) 
and prints the number of days in that month (taking into account leap years). 
You may not use switch case or arrays even if you know these language constructs.
*/
#include <iostream>
using namespace std;

// Check if a year is a leap year
bool LeapYear(int year) {
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int main() {
    cout << "Enter year: ";
    int year;
    cin >> year;

    cout << "Enter month: ";
    int month;
    cin >> month;

    // February case
    if (month == 2) {
        if (LeapYear(year)) {
            cout << "29 days" << endl;
        } else {
            cout << "28 days" << endl;
        }
    }
    // First 7 months
    else if (month <= 7) {
        if (month % 2 == 0) {
            cout << "30 days" << endl;
        } else {
            cout << "31 days" << endl;
        }
    }
    // Months 8-12
    else {
        if (month % 2 == 0) {
            cout << "31 days" << endl;
        } else {
            cout << "30 days" << endl;
        }
    }

    return 0;
}


// 31 --> []
// [1] 2 [3] 4 [5] 6 [7] 
// [8] 9 [10] 11 [12] 