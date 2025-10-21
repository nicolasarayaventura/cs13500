/*
    * s25 Program Exercise 1
    *
    * Define function called percentage, for an array of ints, its size, and a target, return the percentage of integers
that is larger than the target to the size of the array.
For example, if the array has elements 3, 2, -1, and target is 1, then there are 2 integers out of 3 elements that
is larger than the target, so the percentage is 66.6667%. The return is 66.6667, a floating point number.
 
*/
#include <iostream>
#include <string>
using namespace std;

double percentage (int nums[], int size, int target) {
// count num < target    
    int count = 0;
    
    for ( int i = 0; i < size; i++) {
        if (nums[i] > target) {
            count++;
        }
    }

    //find percentage
double percent= (double)count / size * 100;

return percent;
}

int main() {
    cout << "Enter size: ";
    int size;
    cin >> size;

    int nums[size];
    cout << "Enter " << size << " numbers: ";
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }

    cout << "Enter target: ";
    int target;
    cin >> target;

    cout << "Percentage of numbers greater than " << target << " is "
         << percentage(nums, size, target) << "%" << endl;

    return 0;
}