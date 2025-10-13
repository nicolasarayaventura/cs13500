/*
Author: Nicolas Araya
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Lab 5G

Task G. Largest twin prime in range
Returns the largest twin prime in the range [a, b], or -1 if none exist.
*/

#include <iostream>
using namespace std;

// Checks if n is prime
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Checks if n is a twin prime
bool isTwinPrime(int n) {
    if (!isPrime(n)) return false;
    return (isPrime(n - 2) || isPrime(n + 2));
}

// Returns the largest twin prime in [a, b], or -1 if none
int largestTwinPrime(int a, int b) {
    for (int i = b; i >= a; i--) { // start from b and go down
        if (isTwinPrime(i)) {
            return i;
        }
    }
    return -1; // no twin prime found
}

int main() {
    int a, b;
    cout << "Enter the range [a b]: ";
    cin >> a >> b;

    int largest = largestTwinPrime(a, b);

    if (largest != -1) {
        cout << "The largest twin prime in the range [" << a << ", " << b << "] is "
             << largest << ".\n";
    } else {
        cout << "There are no twin primes in the range [" << a << ", " << b << "].\n";
    }

    return 0;
}
