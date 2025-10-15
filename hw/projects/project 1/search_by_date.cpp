/*
Author: Nicolas Araya Ventura
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Project 1 - C

file, processes date formats, and calculates the total spending within a specified date range.
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

// date conversion
string convert(string date) {
    stringstream ss(date);
    string month, day, year;
    getline(ss, month, '/');
    getline(ss, day, '/');
    getline(ss, year);

    // leading 0 0-9
    if (month.length() == 1) month = "0" + month;
    if (day.length() == 1) day = "0" + day;
    if (year.length() == 2) year = "20" + year;  

    return month + "/" + day + "/" + year;
}

int main() {
    string filename;
    cout << "Enter a csv file name: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Cannot open file " << filename << endl;
        return 1;
    }

    string startDate, endDate;
    cout << "Enter start date (m/d/yy): ";
    cin >> startDate;
    cout << "Enter end date (m/d/yy): ";
    cin >> endDate;

    startDate = convert(startDate);
    endDate = convert(endDate);

    string line;
    getline(file, line); 

    double total = 0.0;

    // transactions
    while (getline(file, line)) {
        stringstream ss(line);
        string date, description, category, amountStr;

        getline(ss, date, ',');
        getline(ss, description, ',');
        getline(ss, category, ',');
        getline(ss, amountStr, ',');

        string dateStd = convert(date);

        if (dateStd >= startDate && dateStd <= endDate) {
            cout << date << "," << description << "," << category << "," << amountStr << endl;
            total += stod(amountStr);
        }
    }

    cout << fixed << setprecision(2);
    cout << "Total amount: " << total << endl;

    file.close();
    return 0;
}
