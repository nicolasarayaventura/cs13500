/*
Author: Nicolas Araya
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Lab 6C

In a Caesar cipher, each letter is always shifted by the same number of positions. What if we shifted each letter by a different value? Such a code would be much harder to break. This encryption strategy is known as the Vigenere cipher.

Since each letter of plaintext must be shifted differently, a single right-shift parameter is not sufficient, we need to have a sequence of such shifts. This sequence is determined by a keyword, in which each letter corresponds to specific shift: a shifts by 0, b shifts by 1, c shifts by 2, and so on. The n-th letter of the alphabet will shift by n − 1 to the right.

For example, suppose that the plaintext to be encrypted is:

Hello, World!
and the keyword is

cake
The first letter of the keyword is c, which is the third letter of the alphabet. That means we shift the first letter of the plaintext H to the right by 3-1 = 2, which gives J.

[Vigenere cipher illustration]

Then repeat the procedure for the remaining letters. If you reach the end of the keyword, go back and use the first letter of the keyword. If a letter in the plaintext is not alphabetic, skip it without using a shift from the keyword.
*/
#include <iostream>
#include <cctype>
using namespace std;

char shiftChar(char c, int kshift) {
    if(int(c) >= 65 && int(c) <= 90) { // 65 to 90, uppercase letters
        c += kshift; // whatever shift is based on keyword, increases c ascii code

        if(c > 90) { // last letter of alphabet, make it wrap around 
            c -= 26; // 26 letters in alphabet, wraps around. 
            return c;
        }

        return c;
    } else if(int(c) >= 97 && int(c) <= 122) { // 97 to 122, lowercase letters
        int a = int(c) + kshift; // shift c by keyword and store into a

        if(a > 122) {
            a -= 26; // wrap the alphabet around
            c = a; // store value of a into c

            return c;
        }

        c = a; 

        return c;
    }

    return c;
}

string encryptVigenere(string plaintext, string keyword) {
    char c, keyc;
    int n;

    for(int i = 0; i < plaintext.length(); i++) { // all plaint text
        if(n > keyword.size() - 1) { // no last letter
            n = 0;
        }

        c = plaintext[i]; 
        keyc = keyword[n];

        int kshift = (int(keyc) - 97); // start at lowercase

        if(isalpha(c) == 0) {  // check for c
            plaintext[i] = shiftChar(c, 0);
        } else {
            plaintext[i] = shiftChar(c, kshift);
            n++; // preventative overflow
        }
    }

    return plaintext;
}

int main() {
    string plaintext, kshift;

    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    cout << "Enter keyword: ";
    cin >> kshift;

    cout << "Ciphertext: " << encryptVigenere(plaintext, kshift);

    return 0;
}