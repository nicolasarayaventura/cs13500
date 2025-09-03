/*
Author: Nicolas Araya Ventura
Course: CSCI-136
Instructor: 
Assignment: Lab1A

Task A. Find the smaller of two integers.
*/
#include <iostream>
using namespace std;

int main() {
    cout << "Enter first number: " ;
    int num1;
    cin >> num1;
    cout << "Enter second number: ";
    int num2;
    cin >> num2;
    int smallest = (num1 < num2) ? num1 : num2;
    cout << "The smaller number of the two is " << smallest << endl;
    return 0;
}