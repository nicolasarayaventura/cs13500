/*
Author: Nicolas Araya Ventura
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Project 2 -B

Task B
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

const int MAX_NUM_CATEGORIES = 20;
const int NUM_MONTHS = 12;

int main() {
    string fileName;
    cout << "Enter a file name: ";
    cin >> fileName;

    ifstream fin(fileName);
    if (!fin) {
        cerr << fileName << " cannot be opened" << endl;
        return 1;
    }

    string categories[MAX_NUM_CATEGORIES];
    int numCategories = 0;
    // skiip the header
    string header;
    getline(fin, header); 

    string line;
    double categoryTotal[NUM_MONTHS][MAX_NUM_CATEGORIES] = {0};

    // read csv and get categories 
    while (getline(fin, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string date, description, category, amountStr;
        getline(ss, date, ',');
        getline(ss, description, ',');
        getline(ss, category, ',');
        getline(ss, amountStr);

        double amount = stod(amountStr);

        // category finding/ adding
        int catIdx = -1;
        for (int i = 0; i < numCategories; i++) {
            if (categories[i] == category) { catIdx = i; break; }
        }
        if (catIdx == -1 && numCategories < MAX_NUM_CATEGORIES) {
            categories[numCategories] = category;
            catIdx = numCategories;
            numCategories++;
        }

        // finding month
        int month = stoi(date.substr(0,2));
        if (month >=1 && month <= 12)
            categoryTotal[month-1][catIdx] += amount;
    }
    fin.close();

    double annualCategoryTotal[MAX_NUM_CATEGORIES] = {0};
    double annualTotal = 0;
    string monthNames[NUM_MONTHS] = {"Jan","Feb","Mar","Apr","May","Jun",
                                     "Jul","Aug","Sep","Oct","Nov","Dec"};

    // printing

    //header
    cout << left << setw(3) << "MON";
    for (int j = 0; j < numCategories; j++)
        cout << right << setw(15) << categories[j];
    cout << right << setw(15) << "TOTAL" << "\n";
    cout << "--------------------------------------------------------------------\n";

    // monthlly total
    for (int i = 0; i < NUM_MONTHS; i++) {
        cout << left << setw(3) << monthNames[i];
        double monthlyTotal = 0;
        for (int j = 0; j < numCategories; j++) {
            cout << right << setw(15) << fixed << setprecision(2) << categoryTotal[i][j];
            monthlyTotal += categoryTotal[i][j];
            annualCategoryTotal[j] += categoryTotal[i][j];
        }
        annualTotal += monthlyTotal;
        cout << right << setw(15) << fixed << setprecision(2) << monthlyTotal << "\n";
    }

    cout << "====================================================================\n";

    // annnual total
    for (int j = 0; j < numCategories; j++)
        cout << right << setw(15) << fixed << setprecision(2) << annualCategoryTotal[j];
    cout << right << setw(15) << fixed << setprecision(2) << annualTotal << "\n";

    // percentages
    for (int j = 0; j < numCategories; j++) {
        double percent = (annualCategoryTotal[j] / annualTotal) * 100;
        cout << right << setw(15) << fixed << setprecision(2) << percent << "%";
    }
    cout << "\n";

    return 0;
}
