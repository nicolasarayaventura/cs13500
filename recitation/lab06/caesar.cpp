/*
Author: Nicolas Araya
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Lab 6A

The Caesar cipher is a simple and widely known encryption technique. The action of a Caesar cipher is to replace each letter in the plaintext with a letter some fixed number of positions down the alphabet.

For example, when the shift is +5, every A becomes an F, every B becomes a G, and so on:

Plaintext : A Light-Year Apart
Ciphertext: F Qnlmy-Djfw Fufwy
This is a Caesar cipher with the right shift of 5. Note that we assume that the alphabet wraps around, so, for example, each W becomes a B, and each Y becomes a D.
*/
#include <iostream>
#include <cctype>
using namespace std;

char shiftChar(char c, int rshift) {
    if(int(c) >= 65 && int(c) <= 90) { // 65 to 90 for upper only
        c += rshift; // 

        if(c > 90) { // last letter of interest
            c -= 26; //
            return c;
        }

        return c;
    } else if(int(c) >= 97 && int(c) <= 122) { // lower case letters
        int a = int(c) + rshift;

        if(a > 122) {
            a -= 26; // wrapping
            c = a; // storage

            return c;
        }

        c = a; 

        return c;
    }

    return c;
}

string encryptCaesar(string plaintext, int rshift) {
    char c;

    for(int i = 0; i < plaintext.length(); i++) {
        c = plaintext[i];
        plaintext[i] = shiftChar(c, rshift); 
    }

    return plaintext;
}

int main() {
    string plaintext;
    int rshift;

    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    cout << "Enter shift: ";
    cin >> rshift;

    cout << "Ciphertext: " << encryptCaesar(plaintext, rshift);

    return 0;
}