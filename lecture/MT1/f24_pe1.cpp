/*
    * Fall24 Program Exercise 1
    *
Define function called sumEvenFactors, for a positive integer, sum up its non − trivial factors that
are even. A non-trivial factor of n is a factor of n other than 1 and itself.
Hint: n/2 may be a non-trivial factor of n.
*/
#include <iostream>
using namespace std;

int sumEvenFactors (int num) {
    int sum = 0;

    // loop through possible non-trivial factors (exclude 1 and num)
    for (int i = 2; i < num / 2 ; i++) {
        if (num % i == 0 && i % 2 == 0) {
            sum += i;
        }
    }

    return sum;
}

int main () {
    int num;
    cout << "Enter num: ";
    cin >> num;

    cout << sumEvenFactors(num) << endl; 


return 0;
}