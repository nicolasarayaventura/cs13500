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

int main() {
    cout << "Enter year: ";
    int year;
    cin >> year;
   
    cout << "Enter month:";
    int month;
    cin >> month;

    string out1 = "31 days";
    string out2 = "30 days:";

    //month case
    if (month <= 7) {
        if (month = month % 2) {
             cout << out1 << endl;

        }
    }


    // leap year case
     if (year % 400 == 0) {
        cout << "Leap year" << endl;
    }  else if (year % 4 == 0) {
        cout << "Leap year" << endl;
    }
    
    
    return 0;
}


// 31 --> []
// [1] 2 [3] 4 [5] 6 [7] 
// [8] 9 [10] 11 [12] 