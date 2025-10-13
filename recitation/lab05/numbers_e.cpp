/*
Author: Nicolas Araya
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Lab 5E

Task E. Is a twin prime?
Determines whether a number is a twin prime.
*/

#include <iostream>
using namespace std;

// Checks if n is prime
bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// twin prime
bool isTwinPrime(int n) {
    if (!isPrime(n)) {
        return false; // must be prime first
    }
    // twin prime if n-2 or n+2 
    return (isPrime(n - 2) || isPrime(n + 2));
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isTwinPrime(n)) {
        cout << n << " is a twin prime.\n";
    } else {
        cout << n << " is not a twin prime.\n";
    }

    return 0;
}
