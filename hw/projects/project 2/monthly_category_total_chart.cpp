/*
Author: Nicolas Araya Ventura
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Project 2 -A

Task A
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// values that cannot change!
const int MAX_NUM_CATEGORIES = 20;
const int NUM_MONTHS = 12;
const int MAX_NUM_ASTS = 40;

int main() {
    string fileName;
    cout << "Enter a file name: ";
    cin >> fileName;

    ifstream fin(fileName);
    if (fin.fail()) {
        cerr << fileName << " cannot be opened" << endl;
        return 1;
    }

    string categories[MAX_NUM_CATEGORIES];
    int numCategories = 0;

    // finding uniq categories
    string header;
    getline(fin, header);
    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string date, description, category, amountStr;
        getline(ss, date, ',');
        getline(ss, description, ',');
        getline(ss, category, ',');
        getline(ss, amountStr);

        // check if new or not
        bool found = false;
        for (int i = 0; i < numCategories; i++) {
            if (categories[i] == category) {
                found = true;
                break;
            }
        }
        if (!found && numCategories < MAX_NUM_CATEGORIES) {
            categories[numCategories] = category;
            numCategories++;
        }
    }

    // sort categories alphabetically 
    for (int i = 0; i < numCategories - 1; i++) {
        for (int j = i + 1; j < numCategories; j++) {
            if (categories[i] > categories[j]) {
                string temp = categories[i];
                categories[i] = categories[j];
                categories[j] = temp;
            }
        }
    }

    // 2d arrary for monthly totalts
    double categoryTotal[NUM_MONTHS][MAX_NUM_CATEGORIES] = {0};

    // start from beginning of file
    fin.clear();
    fin.seekg(0);
    getline(fin, header); // skip header

    while (getline(fin, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string date, description, category, amountStr;
        getline(ss, date, ',');
        getline(ss, description, ',');
        getline(ss, category, ',');
        getline(ss, amountStr);

        // convert amount
        double amount;
        stringstream convert(amountStr);
        convert >> amount;

        // extract month
        int month = (date[0]-'0')*10 + (date[1]-'0');

        // category index
        int categoryIdx = -1;
        for (int i = 0; i < numCategories; i++) {
            if (categories[i] == category) {
                categoryIdx = i;
                break;
            }
        }
        if (month >= 1 && month <= 12 && categoryIdx != -1)
            categoryTotal[month-1][categoryIdx] += amount;
    }

    fin.close();

    // max monthly total
    double maxTotal = 0;
    for (int m = 0; m < NUM_MONTHS; m++)
        for (int c = 0; c < numCategories; c++)
            if (categoryTotal[m][c] > maxTotal)
                maxTotal = categoryTotal[m][c];

    // category display
    cout << "Select one of the following categories:\n";
    for (int i = 0; i < numCategories; i++)
        cout << i << ". " << categories[i] << endl;

    int choice;
    cout << "Choose a number in [0, " << numCategories-1 << "]: ";
    cin >> choice;

    if (choice < 0 || choice >= numCategories) return 0;

    cout << "Max monthly total across all categories = " << maxTotal << endl;
    cout << "MONTH " << categories[choice] << " TOTAL\n";

    string monthNames[NUM_MONTHS] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    for (int m = 0; m < NUM_MONTHS; m++) {
        cout << monthNames[m] << " " << categoryTotal[m][choice] << " ";
        int stars = (int)((categoryTotal[m][choice] / maxTotal) * MAX_NUM_ASTS);
        for (int s = 0; s < stars; s++) cout << "*";
        cout << endl;
    }

    return 0;
}
