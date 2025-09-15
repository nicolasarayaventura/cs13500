/*
Author: Nicolas Araya
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: title, e.g., Lab1A

Write a program fibonacci.cpp, which uses an array of ints to compute and print all Fibonacci numbers from F(0) to F(59).
*/#include <iostream>
using namespace std;

int main() {
    int fib[60];
    fib[0] = 0;
    fib[1] = 1;

    cout << fib[0] << endl;
    cout << fib[1] << endl;
    
    // starts at index of 2
    for(int i = 2; i < 60; i++) {

        // formula upto 59
        fib[i] = fib[i-1] + fib[i-2];
        cout << fib[i] << endl;
    }

    return 0;
}