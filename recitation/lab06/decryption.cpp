/*
Author: Nicolas Araya
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Lab 6D

Implement two decryption functions corresponding to the above ciphers. When decrypting ciphertext, ensure that the produced decrypted string is equal to the original plaintext:

decryptCaesar(ciphertext, rshift) == plaintext
decryptVigenere(ciphertext, keyword) == plaintext
Write a program decryption.cpp that uses the above functions to demonstrate encryption and decryption for both ciphers.

It should first ask the user to input plaintext, then ask for a right shift for the Caesar cipher and report the ciphertext and its subsequent decryption. After that, it should do the same for the Vigenere cipher.
*/

#include <iostream>
#include <cctype>
using namespace std;

// This function shifts a single letter by "rshift" places in the alphabet
char shiftChar(char c, int rshift) {
    // If the letter is uppercase (A–Z)
    if (c >= 'A' && c <= 'Z') {
        c += rshift;
        if (c > 'Z') c -= 26;  // wrap around past 'Z'
        if (c < 'A') c += 26;  // wrap around before 'A'
        return c;
    }
    // If the letter is lowercase (a–z)
    else if (c >= 'a' && c <= 'z') {
        c += rshift;
        if (c > 'z') c -= 26;  // wrap around past 'z'
        if (c < 'a') c += 26;  // wrap around before 'a'
        return c;
    }
    // If it’s not a letter, return it as is
    return c;
}

// Caesar cipher encryption
string encryptCaesar(string plaintext, int rshift) {
    for (int i = 0; i < plaintext.length(); i++) {
        plaintext[i] = shiftChar(plaintext[i], rshift);
    }
    return plaintext;
}

// Caesar cipher decryption
string decryptCaesar(string ciphertext, int rshift) {
    for (int i = 0; i < ciphertext.length(); i++) {
        ciphertext[i] = shiftChar(ciphertext[i], -rshift);
    }
    return ciphertext;
}

// Vigenere cipher encryption
string encryptVigenere(string plaintext, string keyword) {
    int n = 0; // keeps track of which letter in the keyword to use
    for (int i = 0; i < plaintext.length(); i++) {
        char c = plaintext[i];

        // Only shift letters, skip spaces/punctuation
        if (isalpha(c)) {
            char keyc = keyword[n % keyword.size()]; // repeat keyword
            int kshift = tolower(keyc) - 'a';        // turn letter into shift number
            plaintext[i] = shiftChar(c, kshift);
            n++; // move to next keyword letter
        }
    }
    return plaintext;
}

// Vigenere cipher decryption
string decryptVigenere(string ciphertext, string keyword) {
    int n = 0; // keeps track of which letter in the keyword to use
    for (int i = 0; i < ciphertext.length(); i++) {
        char c = ciphertext[i];

        // Only shift letters, skip spaces/punctuation
        if (isalpha(c)) {
            char keyc = keyword[n % keyword.size()];
            int kshift = (tolower(keyc) - 'a') * -1; // reverse the shift
            ciphertext[i] = shiftChar(c, kshift);
            n++;
        }
    }
    return ciphertext;
}

int main() {
    string plaintext, keyword;
    int rshift;

    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    cout << "\n= Caesar =\n";
    cout << "Enter shift: ";
    cin >> rshift;

    cout << "Ciphertext: " << encryptCaesar(plaintext, rshift) << endl;
    cout << "Decrypted: " << decryptCaesar(encryptCaesar(plaintext, rshift), rshift) << endl;

    cout << "\n= Vigenere =\n";
    cout << "Enter keyword: ";
    cin >> keyword;

    cout << "Ciphertext: " << encryptVigenere(plaintext, keyword) << endl;
    cout << "Decrypted: " << decryptVigenere(encryptVigenere(plaintext, keyword), keyword) << endl;

    return 0;
}
