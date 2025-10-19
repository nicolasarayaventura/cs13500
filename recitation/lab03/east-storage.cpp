/*
Author: Nicolas Araya
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Lab3

Write a program east-storage.cpp that asks the user to input a string representing the date (in MM/DD/YYYY format), and prints out the East basin storage on that day.
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main() {
    // standard check
    // for files
    ifstream fin("Current_Reservoir_Levels.tsv");

    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); 
    }

    string junk;       
    getline(fin, junk);

    string date, inputDate;
    double eastSt, eastEl, westSt, westEl;

    cout << "Enter date (MM/DD/YYYY): " << endl;
    cin >> inputDate;

    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 

        fin.ignore(INT_MAX, '\n'); 
        if(date == inputDate) {
            getline(fin, date);
            cout << "East basin storage: " << eastSt << " billion gallons";
        }
    }  

    fin.close();
}