/*
Author: Nicolas Araya
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Lab 11D

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

#include <iostream>
#include <string>
using namespace std;

struct Post {
    string username;
    string message;
};

class Profile {
private:
    string username;
    string displayname;
public:
    Profile(string usrn, string dspn);
    Profile();
    string getUsername();
    string getFullName();
    void setDisplayName(string dspn);
};

class Network {
private:
    static const int MAX_USERS = 20;
    int numUsers;
    Profile profiles[MAX_USERS];

    static const int MAX_POSTS = 100;
    int numPosts;
    Post posts[MAX_POSTS];

    bool following[MAX_USERS][MAX_USERS];
    int findID(string usrn);
public:
    Network();
    bool addUser(string usrn, string dspn);
    bool follow(string usrn1, string usrn2);
    void printDot();
    bool writePost(string usrn, string msg);
    bool printTimeline(string usrn);
};

int main() {
    Network nw;
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");
    
    nw.follow("mario", "luigi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");

    nw.writePost("mario", "It's a-me, Mario!");
    nw.writePost("luigi", "Hey hey!");
    nw.writePost("mario", "Hi Luigi!");
    nw.writePost("yoshi", "Test 1");
    nw.writePost("yoshi", "Test 2");
    nw.writePost("luigi", "I just hope this crazy plan of yours works!");
    nw.writePost("mario", "My crazy plans always work!");
    nw.writePost("yoshi", "Test 3");
    nw.writePost("yoshi", "Test 4");
    nw.writePost("yoshi", "Test 5");

    cout << "\n======= Mario's timeline =======" << endl;
    nw.printTimeline("mario");
    cout << endl;

    cout << "======= Yoshi's timeline =======" << endl;
    nw.printTimeline("yoshi");
    cout << endl;
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
    for (int i = 0; i < numUsers; i++)
        if (profiles[i].getUsername() == usrn)
            return i;
    return -1;
}

Network::Network() {
    numUsers = 0;
    numPosts = 0;

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
    cout << "digraph {\n";
    for (int i = 0; i < numUsers; i++)
        cout << " \"@" << profiles[i].getUsername() << "\"\n";

    for (int i = 0; i < numUsers; i++)
        for (int j = 0; j < numUsers; j++)
            if (following[i][j])
                cout << " \"@" << profiles[i].getUsername()
                     << "\" -> \"@" << profiles[j].getUsername() << "\"\n";

    cout << "}\n";
}

bool Network::writePost(string usrn, string msg) {
    int id = findID(usrn);
    if (id == -1 || numPosts == MAX_POSTS)
        return false;

    posts[numPosts] = {usrn, msg};
    numPosts++;
    return true;
}

bool Network::printTimeline(string usrn) {
    int id = findID(usrn);
    if (id == -1)
        return false;

    for (int i = numPosts - 1; i >= 0; i--) {
        string author = posts[i].username;
        int authID = findID(author);

        if (author == usrn || following[id][authID])
            cout << profiles[authID].getFullName()
                 << ": " << posts[i].message << endl;
    }
    return true;
}
