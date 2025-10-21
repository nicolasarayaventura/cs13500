/*
    * s25 Program Exercise 1
    *
    Write code in main to enter a series of integers until -1 is entered. Find out the number of integers that can
be divided by both 3 and 5 at the same time, the number of integers that can be divided by 3 only, and the
number of integers that can be divided by 5 only.
Integer num is divided by 3 means the remainder of num divided by 3 is 0
 
*/

#include <iostream>
using namespace std;

int main() {
    int num;
    int countBoth = 0;
    int count3Only = 0;
    int count5Only = 0;

    while (true) {
        cout << "Enter an int (-1 to stop): ";
        cin >> num;

        if (num == -1) break;  // stop input

        if (num % 3 == 0 && num % 5 == 0) {
            countBoth++;
        } else if (num % 3 == 0) {
            count3Only++;
        } else if (num % 5 == 0) {
            count5Only++;
        }
    }

    cout << "Divisible by 3 and 5: " << countBoth << endl;
    cout << "Divisible by 3 only: " << count3Only << endl;
    cout << "Divisible by 5 only: " << count5Only << endl;

    return 0;
}
