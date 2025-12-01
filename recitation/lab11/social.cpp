/*
Author: Nicolas Araya
Course: CSCI-136
Instructor: Sarah Khaldi
Assignment: Lab 11A

*/
/// comment grade
/// comment grade
/// comment grade
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
#include <iostream>
using namespace std;

class Profile {
private:
    string username;
    string displayname;
public:
    // Initialize with username and display name
    Profile(string usrn, string dspn);
    // Initialize as empty profile
    Profile();
    // Return username
    string getUsername();
    // Return "displayname (@username)"
    string getFullName();
    // Update display name
    void setDisplayName(string dspn);
};

int main() {
    Profile p1("marco", "Marco");

    cout << p1.getUsername() << endl;
    cout << p1.getFullName() << endl;

    p1.setDisplayName("Marco Rossi"); 
    cout << p1.getUsername() << endl;
    cout << p1.getFullName() << endl;

    Profile p2("tarma1", "Tarma Roving");
    cout << p2.getUsername() << endl;
    cout << p2.getFullName() << endl;
}

Profile::Profile(string usrn, string dspn){
    username = usrn;
    displayname = dspn;
}

Profile::Profile(){
    username = "";
    displayname = "";
}

string Profile::getUsername(){
    return username;
}

string Profile::getFullName(){
    return displayname + " (@" + username + ")";
}

void Profile::setDisplayName(string dspn){
    displayname = dspn;
}
