/*
Author: Nicolas Araya
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Lab 7A
Start by writing a function

string removeLeadingSpaces(string line);
that takes one line of code as input and returns its copy without leading spaces and tabs:

removeLeadingSpaces("       int x = 1;  ") == "int x = 1;  "
Make use of the function isspace defined in <cctype> to check if a character is a whitespace. Your function should probably iterate over the input string, skip all spaces, and after it finds the first non-space character, start accumulating the characters into a new string, which will be returned.

Write a program unindent.cpp that reads input from cin and prints out each input line with leading spaces removed.
*/
#include <iostream>
using namespace std;

string removeLeadingSpaces(string line) {
    int count = 0;

    while(isspace(line[count])) {
        count++;
    }
        
    return line.substr(count);
}

int main() {
    string line;

    while(getline(cin, line)) {
        cout << removeLeadingSpaces(line) << endl;
    }

    return 0;
}