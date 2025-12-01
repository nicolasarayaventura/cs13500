/*
Author: Nicolas Araya
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Lab 11B

*/
/// comment grade/// comment grade
/// comment grade
/// comment grade
/// comment grade
/// comment grade
/// comment grade
/// comment grade
/// comment grade
/// comment grade
/// comment grade
/// comment grade
/// comment grade
/// comment grade
/// comment grade
/// comment grade
/// comment grade
/// comment grade
/// comment grade
/// comment grade
/// comment grade
/// comment grade
/// comment grade

#include <iostream>
#include <string>
using namespace std;

class Profile {
private:
    string username;
    string displayname;
public:
    // Create profile with username + display name
    Profile(string usrn, string dspn);
    // Empty profile
    Profile();
    // Return username
    string getUsername();
    // Return "displayname (@username)"
    string getFullName();
    // Update display name
    void setDisplayName(string dspn);
};

class Network {
private:
    static const int MAX_USERS = 20;      // max profiles
    int numUsers;                         // current count
    Profile profiles[MAX_USERS];          // user list

    // Return index of username, or -1 if not found
    int findID(string usrn);
public:
    // Start empty network
    Network();
    // Add user if valid + unique
    bool addUser(string usrn, string dspn);
};

int main() {
    Network nw;
    cout << nw.addUser("mario", "Mario") << endl;
    cout << nw.addUser("luigi", "Luigi") << endl;

    cout << nw.addUser("mario", "Mario2") << endl;
    cout << nw.addUser("mario 2", "Mario2") << endl;
    cout << nw.addUser("mario-2", "Mario2") << endl;

    for (int i = 2; i < 20; i++)
        cout << nw.addUser("mario" + to_string(i),
                           "Mario" + to_string(i)) << endl;

    cout << nw.addUser("yoshi", "Yoshi") << endl;
}

Profile::Profile(string usrn, string dspn) {
    username = usrn;
    displayname = dspn;
}

Profile::Profile() {
    username = "";
    displayname = "";
}

string Profile::getUsername() {
    return username;
}

string Profile::getFullName() {
    return displayname + " (@" + username + ")";
}

void Profile::setDisplayName(string dspn) {
    displayname = dspn;
}

int Network::findID(string usrn) {
    for (int i = 0; i < numUsers; i++) {
        if (profiles[i].getUsername() == usrn)
            return i;
    }
    return -1;
}

Network::Network() {
    numUsers = 0;
}

bool Network::addUser(string usrn, string dspn) {
    if (numUsers >= MAX_USERS || findID(usrn) != -1)
        return false;

    for (char c : usrn)
        if (!isalnum(c))
            return false;

    profiles[numUsers] = Profile(usrn, dspn);
    numUsers++;
    return true;
}
