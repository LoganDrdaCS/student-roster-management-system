#include "roster.h"
#include <iostream>
#include <string>
#include <array>
using namespace std;

const string studentData[] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Logan,Drda ,ldrda@wgu.edu,28,10,20,30,SOFTWARE"
};

int main() {

    Roster* classRoster = new Roster();

    for (int i = 0; i < 5; ++i) {
        classRoster->parse(studentData[i]);
    }

    classRoster->printAll();
    cout << endl;
    classRoster->printInvalidEmails();
    cout << endl;

    // Looping through all students to print their average days in courses
    for (int i = 0; i < 5; ++i) {
        classRoster->printAverageDaysInCourse(classRoster->classRosterArray[i]->getStudentID());
    }
    cout << endl;

    classRoster->printByDegreeProgram(SOFTWARE);
    cout << endl;
    classRoster->remove("A3");
    cout << endl;
    classRoster->printAll();
    cout << endl;
    classRoster->remove("A3");
    cout << endl;

    // Destructors
    classRoster->~Roster();
    delete classRoster;
    classRoster = nullptr;

    cout << "\n";

}