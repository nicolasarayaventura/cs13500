/*
Author: Nicolas Araya Ventura
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Project 1 -A

Task A: Add the data in a Text File with Only One column
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename;
    cout << "Enter a file name: ";
    cin >> filename; 

    ifstream file(filename);
    if (!file.is_open()) { 
        cerr << "Error: Could not open file " << filename << endl;
        return 1;
    }

    double num, sum = 0.0;
    while (file >> num) {  // Read all numbers
        sum += num;
    }

    file.close();
    cout << "sum = " << sum << endl;
    return 0;
}
