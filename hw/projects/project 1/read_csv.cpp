/*
Author: Nicolas Araya Ventura
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Project 1 -B

Task B: Read a CSV file and Calculate its Total
*/


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string filename;
    cout << "Enter a csv file: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return 1;
    }

    string line;
    double sum = 0.0;

    // Skip header line
    getline(file, line);

    // Read each record line by line
    while (getline(file, line)) {
        stringstream ss(line);
        string date, description, category, amountStr;

        // Extract columns separated by commas
        getline(ss, date, ',');
        getline(ss, description, ',');
        getline(ss, category, ',');
        getline(ss, amountStr, ',');

        // Convert amount to double
        double amount = stod(amountStr);
        sum += amount;
    }

    file.close();
    cout << "sum = " << sum << endl;
    return 0;
}
