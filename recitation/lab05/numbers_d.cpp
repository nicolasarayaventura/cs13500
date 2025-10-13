/*
Author: Nicolas Araya
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Lab 5D

Task D. Count primes in range
Counts how many prime numbers exist between a and b (inclusive).
*/

#include <iostream>
using namespace std;

// Reuse from Task D
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

// Counts primes in [a, b]
int countPrimes(int a, int b) {
    int count = 0;

    for (int i = a; i <= b; i++) {
        if (isPrime(i)) {
            count++;
        }
    }

    return count;
}

int main() {
    int a, b;
    cout << "Enter the range [a b]: ";
    cin >> a >> b;

    cout << "There are " << countPrimes(a, b)
         << " prime numbers between " << a << " and " << b << ".\n";

    return 0;
}
