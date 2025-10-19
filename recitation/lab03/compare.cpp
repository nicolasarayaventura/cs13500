/*
Author: Nicolas Araya
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Lab3

Write a program compare.cpp that asks the user to input two dates (the beginning and the end of the interval). The program should check each day in the interval and report which basin had higher elevation on that day by printing “East” or “West”, or print “Equal” if both basins are at the same level.

*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main() {
    ifstream fin("Current_Reservoir_Levels.tsv");

    if(fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // same loop used in others
        // nothing changed for this loop
    }

    string junk;        
    getline(fin, junk); 

    int line = 0;
    string date, startDate, endDate;
    double eastSt, eastEl, westSt, westEl;

    cout << "Enter starting date: " << endl;
    cin >> startDate;
    cout << "Enter ending date: " << endl;
    cin >> endDate;

    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 

        fin.ignore(INT_MAX, '\n'); \
        if(date == startDate) {
            line++;
        } else if(date > endDate) {
            break;
        }

        for(int i = 0; i < line; i++) {
            if(eastEl > westEl) {
                cout << date << " East" << endl;
            } else if(eastEl < westEl) {
                cout << date << " West" << endl;
            } else {
                cout << date << " Equal" << endl;
            }
        } 
    }

    fin.close();
}