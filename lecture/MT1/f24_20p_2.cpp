/*
 Define function numBigLetters, for a string, return the number of characters that are capital letters,
that is, letter from ‘A’ to ‘Z’. No need to include libraries.
Hint: you may use int isupper(int ch) to test whether a character is uppercase letter or not
*/

#include <iostream>
#include <string>
using namespace std;

int numBigLetters (string word){
    int target = 0;
    for (i = 0; i <= word.length(); i++){
        if (isupper(word[i])){
            target++;
        }
    }
    return target
}