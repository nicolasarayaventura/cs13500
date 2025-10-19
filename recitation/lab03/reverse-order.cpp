/*
Author: Nicolas Araya
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Lab3


Write a program reverse-order.cpp which asks the user to input two dates (earlier date then later date). The program should report the West basin elevation for all days in the interval in the reverse chronological order (from the later date to the earlier).
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
        exit(1); // standard check
        // of file loop
    }

    string junk;        
    getline(fin, junk); 

    int line = 0;
    string date, earlierDate, laterDate, arrDate[365];
    double eastSt, eastEl, westSt, westEl, arrWestEl[365];

    cout << "Enter earlier date: " << endl;
    cin >> earlierDate;
    cout << "Enter later date: " << endl;
    cin >> laterDate;

    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 

        fin.ignore(INT_MAX, '\n'); 


        if(date >= earlierDate && date <= laterDate) {
            line++;
            arrDate[line] = date;
            arrWestEl[line] = westEl;
        } 
    }

    for(int i = line; i > 0; i--) {
        cout << arrDate[i] << "  " << arrWestEl[i] << " ft" << endl;
    }

    fin.close();
}