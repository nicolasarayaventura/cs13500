/*
Author: Nicolas Araya
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Lab 5B

Task B. Is a prime?
A prime number is an integer greater or equal to 2 that is only divisible by 1 and by itself. The first few primes are: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 …

N is a prime if and only if it is not divisible evenly by any of the numbers from 2 to N−1. Let’s implement this decision as a function.

In the same program numbers.cpp, add a function

bool isPrime(int n);
The function should return true if n is a prime, otherwise return false. Change the main function to test your new code.
*/
/*
Author: Nicolas Araya
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Lab 5B

Task B. Is a prime?
Checks if a number is prime.
*/

#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) {
        return false; // 0 and 1 are not prime
    }

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false; // divisible by something other than 1 and itself
        }
    }

    return true;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isPrime(n)) {
        cout << n << " is prime.\n";
    } else {
        cout << n << " is not prime.\n";
    }

    return 0;
}
