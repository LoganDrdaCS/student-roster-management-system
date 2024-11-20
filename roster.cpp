#include "roster.h"
#include <iostream>
#include <string>
#include <array>
using namespace std;

// Default constructor
Roster::Roster() {
    this->studentsCurrentlyOnRoster = 0; // Initialize the roster to have 0 students
}

// Destructor to clean up dynamically-allocated student objects
Roster::~Roster() {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr) {  // Ensure the pointer is valid before deleting
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;  // Avoid dangling pointers
        }
    }
}

// Function to add a new student to the roster
void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, string degreeProgram) {
    this->classRosterArray[this->studentsCurrentlyOnRoster] = new Student(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    this->studentsCurrentlyOnRoster += 1;
}

// Function to parse a single row of student data and add it to the roster
void Roster::parse(string row) {
    // Variables to later use as input parameters for add()
    string studentID, firstName, lastName, email, degreeProgram;
    int age, daysInCourse1, daysInCourse2, daysInCourse3;
    size_t startPosition = 0;
    size_t commaPosition = 0;
    int switchValue = 0;
    string dataValue = "";

    while (switchValue < 9) {
        commaPosition = row.find(",", startPosition);
        switchValue += 1;
        dataValue = row.substr(startPosition, commaPosition - startPosition);

        switch (switchValue) {
        case 1:
            studentID = dataValue;
            break;
        case 2:
            firstName = dataValue;
            break;
        case 3:
            lastName = dataValue;
            break;
        case 4:
            email = dataValue;
            break;
        case 5:
            age = stoi(dataValue);
            break;
        case 6:
            daysInCourse1 = stoi(dataValue);
            break;
        case 7:
            daysInCourse2 = stoi(dataValue);
            break;
        case 8:
            daysInCourse3 = stoi(dataValue);
            break;
        case 9:
            if (dataValue == "SECURITY") {
                degreeProgram = "SECURITY";
            }
            else if (dataValue == "NETWORK") {
                degreeProgram = "NETWORK";
            }
            else if (dataValue == "SOFTWARE") {
                degreeProgram = "SOFTWARE";
            }
            else {
                cout << "Degree not found." << endl;
            }
            break;
        default:
            break;
        }

        startPosition = commaPosition + 1;

    }

    // Adding student information to the roster
    Roster::add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);

}

void Roster::printAll() {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
        }
    }
}

void Roster::printInvalidEmails() {
    for (int i = 0; i < 5; ++i) {
        string emailToCheck = classRosterArray[i]->getEmail();
        if ((emailToCheck.find(' ') != string::npos) || (emailToCheck.find('@') == string::npos) || (emailToCheck.find('.') == string::npos)) {
            cout << "Invalid email address: " << emailToCheck << endl;
        }
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            double averageDays = (classRosterArray[i]->getDaysPerCourse(0) + classRosterArray[i]->getDaysPerCourse(1) + classRosterArray[i]->getDaysPerCourse(2)) / 3.0;
            cout << "Student with ID " << studentID << " has average number of days: " << averageDays << endl;
        }
        else {
            continue;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {

    string degreeName;
    if (degreeProgram == SECURITY) {
        degreeName = "SECURITY";
    }
    else if (degreeProgram == NETWORK) {
        degreeName = "NETWORK";
    }
    else if (degreeProgram == SOFTWARE) {
        degreeName = "SOFTWARE";
    }
    else {
        degreeName = "UNSPECIFIED";
    }
    cout << "Students with degree program " << degreeName << ":" << endl;
    int numberStudents = 0;
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
            numberStudents += 1;
        }
    }
    if (numberStudents == 0) {
        cout << "ERROR" << endl;
    }
    return;

}

void Roster::remove(string studentID) {
    bool studentFound = false;
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] == nullptr) {
            continue;
        }
        else {
            if (classRosterArray[i]->getStudentID() == studentID) {
                studentFound = true;
                classRosterArray[i] = nullptr;
                break;
            }
        }
    }
    if (studentFound) {
        cout << "Student with ID " << studentID << " removed from roster." << endl;
    }
    else {
        cout << "ERROR: Student with ID " << studentID << " not found.";
    }
}