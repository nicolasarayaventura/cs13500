/*
Author: Nicolas Araya
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Lab 11C

*/
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
    static const int MAX_USERS = 20;      // max users
    int numUsers;                         // current count
    Profile profiles[MAX_USERS];          // user list
    bool following[MAX_USERS][MAX_USERS]; // adjacency matrix

    // Return user index or -1
    int findID(string usrn);
public:
    // Initialize empty network
    Network();
    // Add user if valid and unique
    bool addUser(string usrn, string dspn);
    // Make one user follow another
    bool follow(string usrn1, string usrn2);
    // Print network in DOT format
    void printDot();
};

int main() {
    Network nw;

    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    nw.addUser("wario", "Wario");

    for (int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }

    nw.follow("mario2", "luigi");

    nw.printDot();
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
    for (int i = 0; i < MAX_USERS; i++)
        for (int j = 0; j < MAX_USERS; j++)
            following[i][j] = false;
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

bool Network::follow(string usrn1, string usrn2) {
    int id1 = findID(usrn1);
    int id2 = findID(usrn2);
    if (id1 == -1 || id2 == -1)
        return false;

    following[id1][id2] = true;
    return true;
}

void Network::printDot() {
    cout << "digraph {" << endl;

    for (int i = 0; i < numUsers; i++)
        cout << " \"@" << profiles[i].getUsername() << "\"" << endl;

    for (int i = 0; i < numUsers; i++)
        for (int j = 0; j < numUsers; j++)
            if (following[i][j])
                cout << " \"@" << profiles[i].getUsername()
                     << "\" -> \"@" << profiles[j].getUsername() << "\"" << endl;

    cout << "}" << endl;
}
