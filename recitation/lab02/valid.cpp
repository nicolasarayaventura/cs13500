/*
Author: Nicolas Araya
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: title, e.g., Lab1A

Write a program valid.cpp, which asks the user to input an integer in the range 0 < n < 100. If the number is out of range, the program should keep asking to re-enter until a valid number is input.

After a valid value is obtained, print this number n squared.
*/
#include <iostream>
 using namespace std;

int main () {
    cout << "Please enter an integer: ";
    int num;
    cin >> num;
    // isnt in range of 0-100
    while(num <= 0 || num >= 100) {
        cout << "Please re-enter: " << endl; 
        cin >> num;
    }
    // is in range of 0-100
    if(num > 0 || num < 100) {
        cout << "Number squared is " << num * num << endl;
    }

return 0;
}