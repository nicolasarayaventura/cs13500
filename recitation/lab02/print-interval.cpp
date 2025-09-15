/*
Author: Nicolas Araya
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: title, e.g., Lab1A

Write a program print-interval.cpp that asks the user to input two integers L and U (representing the lower and upper limits of the interval), and print out all integers in the range L ≤ i < U separated by spaces. Notice that we include the lower limit, but exclude the upper limit.
*/
#include <iostream>
using namespace std; 

int main () {
    cout << "Please enter L: ";
    int lower;
    cin >> lower;

    cout << "Please enter U: ";
    int upper;
    cin >> upper;

    for(int i= lower; i < upper; i++) {
        cout << i << " ";
    }

return 0;
}