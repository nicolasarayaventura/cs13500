/*
Author: Nicolas Araya Ventura
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Homework e4.8

Write a program that reads a word and prints each character of the word on a sepa-
rate line. For example, if the user provides the input "Harry", the program prints
*/
#include <iostream>
using namespace std;

int main() {
    string word;

    cout << "Please enter one word: " << endl;
    cin >> word;

    for(int i = 0; i <= word[i]; i++) {
        cout << word[i] << endl;
    }

    return 0;
}
