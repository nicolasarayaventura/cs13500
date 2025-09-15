/*
Author: Nicolas Araya Ventura
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Homework e2.1

Write a program that asks the user to input
• The number of gallons of gas in the tank
• The fuel efficiency in miles per gallon
• The price of gas per gallon
Then print the cost per 100 miles and how far the car can go with the gas in the tank.
*/

#include <iostream>
using namespace std;

int main () {

    cout << "Enter gallons: ";
    double gallons;
    cin >> gallons;

    cout << "Fuel efficiency: ";
    double eff;
    cin >> eff;

    cout << "Price of gas: ";
    double price;
    cin >> price;

    // Calculate cost per 100 miles
    double costPer100 = (100 / eff) * price;
    // Calculate how far the car can go
    double distance = gallons * eff;

    cout << "Cost per 100 miles: " << costPer100 << endl;
    cout << "Distance with current gas: " << distance << " miles" << endl;


return 0;
}