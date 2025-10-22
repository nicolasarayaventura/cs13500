/*
Author: Nicolas Araya Ventura
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Homework e5.15

Write a function sort3(int& a, int& b, int& c) that swaps its three arguments to
arrange them in sorted order. For example,
int v = 3;
int w = 4;
int x = 1;
sort3(v, w, x); // v is now 1, w is now 3, x is now 4
Hint: Use multiple calls to the sort2 function of Exercise E5.14.
*/
#include <iostream>
using namespace std;

void sort2(int& x, int& y) {
    if (x > y) {
        int tmp = x;
        x = y;
        y = tmp;
    }
}

void sort3(int& a, int& b, int& c) {
    sort2(a, b);
    sort2(b, c);
    sort2(a, b);
}

int notmain() {
    int v = 3, w = 4, x = 1;
    sort3(v, w, x);
    cout << v << " " << w << " " << x << "\n"; 
    return 0; 
}