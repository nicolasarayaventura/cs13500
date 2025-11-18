/*
    * Fall24 Program Exercise 1
    *
Write code in main to enter a full name in the format “FirstName LastName” (without quotes), extract
the first name and last name and get the initial. No need to include libraries.
Here is a sample input/output, input is highlighted:
✞ ☎
1 Enter full name in the format of firstName lastName: George Washington
2 Initial for George Washington is GW
✝ ✆
Hints:
• Find out the index of the character separating first name and last name.
size_t find (char c, size_t pos = 0) const;
Searches the string for the first occurrence of character c. If you do not specify parameter pos,
then the search starts from the beginning of the string. size_t is non-negative integer.
• Extract first name and last name.
string substr (size_t pos = 0, size_t len = npos) const;
Generate substring that is the portion of the object that starts at character position pos and spans
len characters (or until the end of the string, whichever comes first). If the second parameter
len is not provided, return a substring starting from pos all the way to last character.
• Initialize the result to be an empty string.
• Use concatenate operator + to add the first letter of first name to the result.
• Use concatenate operator + to add the first letter of last name to the result.
*/
#include <iostream>
#include <string>
using namespace std;

int main () {
    cout << "enter first last";
    string fullName;
    getline(cin fullName);

    int findSpace = fullName.find(' ');
    firstName = fullName.substr(0, findSpace - 1);
    lastName = fullName.substr(findSpace + 1);

    string initial = " ";

    intial += firstName[0];
    intial += lastName[0];

    cout << "intials are " << first + last << endl;

    return 0;
}

  