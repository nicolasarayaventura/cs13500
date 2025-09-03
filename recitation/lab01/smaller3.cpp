/*
Author: Nicolas Araya Ventura
Course: CSCI-136
Instructor: 
Assignment: Lab1A

Write a program smaller3.cpp that asks the user to input three integer numbers, and prints out the smallest of the three.
*/
#include <iostream>
using namespace std;

int main() {
    cout << "Enter the first number: ";
    int num1;
    cin >> num1;

    cout << "Enter the second number: ";
    int num2;
    cin >> num2;

    cout << "Enter the third  number: ";
    int num3;
    cin >> num3;

    int smallest = (num1 < num2) ? num1 : num2;
    smallest = (smallest < num3) ? smallest : num3;
    cout << "The smaller number of the three is " << smallest << endl;
    return 0;
}

