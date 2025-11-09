/*
Author: Nicolas Araya Ventura
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Project 2 - C

Task C
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
    cout << "Enter a csv file name with date, category, cost: ";
    cin >> fileName;

    ifstream fin(fileName);
    if (!fin) {
        cerr << fileName << " cannot be opened" << endl;
        return 1;
    }

    string categories[MAX_NUM_CATEGORIES];
    int numCategories = 0;
    string line;

    double categoryTotal[NUM_MONTHS][MAX_NUM_CATEGORIES] = {0};

    // skip header
    string header;
    getline(fin, header);

    // read data
    while (getline(fin, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string date, description, category, amountStr;
        getline(ss, date, ',');
        getline(ss, description, ',');
        getline(ss, category, ',');
        getline(ss, amountStr);

        double amount = stod(amountStr);

        // find or add category
        int catIdx = -1;
        for (int i = 0; i < numCategories; i++) {
            if (categories[i] == category) { catIdx = i; break; }
        }
        if (catIdx == -1 && numCategories < MAX_NUM_CATEGORIES) {
            categories[numCategories] = category;
            catIdx = numCategories;
            numCategories++;
        }

        // find month (first two characters of date)
        int month = stoi(date.substr(0,2));
        if (month >= 1 && month <= 12)
            categoryTotal[month-1][catIdx] += amount;
    }
    fin.close();

    // SORT CATEGORIES ALPHABETICALLY + MOVE COLUMN DATA
    for (int i = 0; i < numCategories; i++) {
        for (int j = i + 1; j < numCategories; j++) {
            if (categories[j] < categories[i]) {
                // swap category names
                string temp = categories[i];
                categories[i] = categories[j];
                categories[j] = temp;
                // swap categoryTotal column data
                for (int m = 0; m < NUM_MONTHS; m++) {
                    double t = categoryTotal[m][i];
                    categoryTotal[m][i] = categoryTotal[m][j];
                    categoryTotal[m][j] = t;
                }
            }
        }
    }

    double annualCategoryTotal[MAX_NUM_CATEGORIES] = {0};
    double annualTotal = 0;

    string monthNames[NUM_MONTHS] = {"Jan","Feb","Mar","Apr","May","Jun",
                                     "Jul","Aug","Sep","Oct","Nov","Dec"};

    string outFile;
    cout << "enter the name of generated csv file: ";
    cin >> outFile;

    ofstream fout(outFile);
    if (!fout) {
        cerr << outFile << " cannot be opened" << endl;
        return 2;
    }

    // write header
    fout << "MON";
    for (int j = 0; j < numCategories; j++)
        fout << "," << categories[j];
    fout << ",TOTAL\n";

    // write monthly rows
    fout << fixed << setprecision(2);
    for (int i = 0; i < NUM_MONTHS; i++) {
        fout << monthNames[i];
        double monthlyTotal = 0;
        for (int j = 0; j < numCategories; j++) {
            fout << "," << categoryTotal[i][j];
            monthlyTotal += categoryTotal[i][j];
            annualCategoryTotal[j] += categoryTotal[i][j];
        }
        annualTotal += monthlyTotal;
        fout << "," << monthlyTotal << "\n";
    }

    // annual totals row
    fout << ",";
    for (int j = 0; j < numCategories; j++)
        fout << annualCategoryTotal[j] << ",";
    fout << annualTotal << "\n";

    // percentages row
    fout << ",";
    for (int j = 0; j < numCategories; j++) {
        double percent = (annualTotal > 0) ? (annualCategoryTotal[j] / annualTotal) * 100 : 0;
        fout << fixed << setprecision(2) << percent << "%,";
    }
    fout << "\n";

    fout.close();
    return 0;
}
