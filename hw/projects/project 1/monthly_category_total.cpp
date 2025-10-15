/*
Author: Nicolas Araya Ventura
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Project 1 -E

Task E: Calculate and print the monthly totals for that category — i.e., the total amount spent in that
category for each month.
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
    string filename;
    cout << "Enter a csv file name: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }

    string line;
    getline(file, line); //  header not needed

    vector<string> categories;
    struct Record { int month; string category; double cost; };
    vector<Record> records;

    while (getline(file, line)) {
        stringstream ss(line);
        string day, store, category, costStr;
        getline(ss, day, ',');
        getline(ss, store, ',');
        getline(ss, category, ',');
        getline(ss, costStr, ',');

        category.erase(0, category.find_first_not_of(" \t"));
        category.erase(category.find_last_not_of(" \t") + 1);

        // get month from date in x/x/xx format
        int month = stoi(day.substr(0, day.find('/')));

        double cost = stod(costStr);
        records.push_back({month, category, cost});

        if (find(categories.begin(), categories.end(), category) == categories.end())
            categories.push_back(category);
    }

    // sort categories alphabetically
    sort(categories.begin(), categories.end());

    // available categories
    cout << "select one of the following categories" << endl;
    for (int i = 0; i < (int)categories.size(); i++) {
        cout << i << "." << categories[i] << endl;
    }

    // choose category
    int choice;
    cout << "choose a number in [0, " << categories.size() - 1 << "]: ";
    cin >> choice;

    // validate
    while (choice < 0 || choice >= (int)categories.size()) {
        cout << "Enter a choice from 0 to " << categories.size() - 1 << ": ";
        cin >> choice;
    }

    // monthly totals
    vector<double> monthTotals(12, 0.0);
    string selectedCategory = categories[choice];

    for (auto &r : records) {
        if (r.category == selectedCategory)
            monthTotals[r.month - 1] += r.cost;
    }

    // output
    cout << "Month " << selectedCategory << " TOTAL" << endl;
    const string months[12] = {
        "Jan","Feb","Mar","Apr","May","Jun",
        "Jul","Aug","Sep","Oct","Nov","Dec"
    };

    cout << fixed << setprecision(2);
    for (int i = 0; i < 12; i++)
        cout << months[i] << " " << monthTotals[i] << endl;

    return 0;
}
