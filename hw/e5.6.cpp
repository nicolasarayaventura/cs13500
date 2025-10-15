/*
Author: Nicolas Araya Ventura
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Homework e5.6

Write a function string middle(string str) that returns a string containing the middle character in str if the length of str is odd, or the two middle characters if the length is even. For example, middle("middle") returns "dd".
*/
#include <iostream>
#include <string>
using namespace std;

string middle(string str) {
    int len = str.length();
    if (len % 2 == 0)
        return str.substr(len / 2 - 1, 2);  // two middle characters
    else
        return str.substr(len / 2, 1);      // one middle character
}

int main() {
    cout << middle("middle") << endl;  // Output: dd
    cout << middle("abc") << endl;     // Output: b
    return 0;
}
