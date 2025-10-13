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

/*
Author: Nicolas Araya
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Lab 5C

Task C. Next prime
Returns the smallest prime greater than n.
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

// Returns the next prime greater than n
int nextPrime(int n) {
    int i = n + 1;
    while (!isPrime(i)) { // keep searching until a prime is found
        i++;
    }
    return i;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "The next prime after " << n << " is " << nextPrime(n) << ".\n";

    return 0;
}
