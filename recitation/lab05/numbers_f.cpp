/*
Author: Nicolas Araya
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Lab 5F

Task F. Next twin prime
Returns the smallest twin prime greater than n.
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

// Checks if n is a twin prime
bool isTwinPrime(int n) {
    if (!isPrime(n)) {
        return false;
    }
    return (isPrime(n - 2) || isPrime(n + 2));
}

// Finds the next twin prime greater than n
int nextTwinPrime(int n) {
    int i = n + 1;
    while (!isTwinPrime(i)) {
        i++;
    }
    return i;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "The next twin prime after " << n << " is " 
         << nextTwinPrime(n) << ".\n";

    return 0;
}
