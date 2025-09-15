/*
Author: Nicolas Araya
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: title, e.g., Lab1A

Here, briefly, at least in one or a few sentences
describe what the program does.
*/
#include <iostream>
using namespace std;
int main () {
    int myData[10] = {};
    for (int i=0; i < 10; i++){
        myData[i] = 1;
        cout << myData[i] << " ";
    }
    int index, value;
    while(index >= 0 && index < 10) {
        cout << "\n\nInput index: " << endl;
        cin >> index;
        cout << "Input value: " << endl;
        cin >> value;

        for(int i = 0; i < 10; i++) {
            if(index >= 0 && index < 10) { 
                myData[index] = value;
                cout << myData[i] << " ";
            } 
        }
    }
        // grading commeng
    if(index < 0 || index > 9) {
        cout << "Index out of range. Exit" << endl;
    }

    return 0;    
}