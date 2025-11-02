/*
Author: Nicolas Araya
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Lab 7B
To count open blocks, we need to count how many curly braces get opened and closed on each line, so we need to count { and }

Write a function

int countChar(string line, char c);
that scans the line and returns the number of occurrences of the character c.

Write a new program indent.cpp that enhances the program from the previous task. 
As it reads the input line by line, it should also count the number of open and closed { } in it, 
and keep track of how many blocks is currently open at the beginning of each line.
*/
#include <iostream>
using namespace std;

string removeLeadingSpaces(string line) {
    int i = 0;

    while(isspace(line[i])) {
        i++;
    }
        
    return line.substr(i);
}

int countChar(string line, char c) {
    int count = 0;

    for(int i = 0; i < line.length(); i++) {
        if(line[i] == c) {
            count++;
        }
    }

    return count;
}

int main() {
    string line;
    char c;
    int count = 0;

    while(getline(cin, line, '\n')) {

        if(removeLeadingSpaces(line)[0] == '}') {
            for(int i = 0; i < count - 1; i++) {
                cout << "\t"; 
            }
        } else {
            for(int i = 0; i < count; i++) {
                cout << "\t";
            }
        }

        count -= countChar(line, '}');
        count += countChar(line, '{');
        cout << removeLeadingSpaces(line) << endl;
    }

    return 0;
}