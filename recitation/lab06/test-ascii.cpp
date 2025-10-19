/*
Author: Nicolas Araya
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Lab 6A

Write a program numbers.cpp that defines a function

Write a program test-ascii.cpp that asks the user to input a line of text (which may possibly include spaces). The program should report all characters from the input line together with their ASCII codes.

Make sure to print exactly one space between the character and it’s code.
*/
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string str;
    cout << "Input: ";
    getline(cin, str);

    for(int i = 0; i < str.length(); i++) {
        char c = str[i];
        cout << c << " " << int(c) << endl; // chr to ascii
    }

    return 0;
}