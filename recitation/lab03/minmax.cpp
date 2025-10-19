/*
Author: Nicolas Araya
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Lab3

Write a program minmax.cpp that finds the minimum and maximum storage in East basin in 2018.
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
        exit(1); // standard file loop check
    }

    string junk;        
    getline(fin, junk); 

    string date;
    // dont know min infinte
    double eastSt, eastEl, westSt, westEl, min = 100000000, max = 0;
    
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 

        fin.ignore(INT_MAX, '\n');
        if(eastSt < min) {
		    min = eastSt;
        } 
        
        if(eastSt > max) {
		    max = eastSt;
        }
    }  

    cout << "minimum storage in East basin: " << min << " billion gallons" << endl;
    cout << "MAXimum storage in East basin: " << max << " billion gallons" << endl;

    fin.close();
}