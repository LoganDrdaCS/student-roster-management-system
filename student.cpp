#include "student.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor
Student::Student() {
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = 0;
    this->daysPerCourse[0] = 0;
    this->daysPerCourse[1] = 0;
    this->daysPerCourse[2] = 0;
    this->degreeProgram;
}

// Constructor with parameters
Student::Student(string id, string fName, string lName, string email, int age, int days1, int days2, int days3, string program) {
    this->studentID = id;
    this->firstName = fName;
    this->lastName = lName;
    this->email = email;
    this->age = age;
    this->daysPerCourse[0] = days1;
    this->daysPerCourse[1] = days2;
    this->daysPerCourse[2] = days3;
    if (program == "SECURITY") {
        this->degreeProgram = SECURITY;
    }
    else if (program == "NETWORK") {
        this->degreeProgram = NETWORK;
    }
    else if (program == "SOFTWARE") {
        this->degreeProgram = SOFTWARE;
    }
    else {
        cout << "Degree not found." << endl;
    }
}

void Student::print() {
    string programString;
    if (this->getDegreeProgram() == SECURITY) {
        programString = "SECURITY";
    }
    else if (this->getDegreeProgram() == NETWORK) {
        programString = "NETWORK";
    }
    else if (this->getDegreeProgram() == SOFTWARE) {
        programString = "SOFTWARE";
    }
    cout << this->getStudentID() << "\t" << "First Name: " << this->getFirstName() << "\t" << "Last Name: " << this->getLastName() << "\t";
    cout << "Age: " << this->getAge() << "\t\t" << "daysInCourse: {" << this->getDaysPerCourse(0) << ", " << this->getDaysPerCourse(1) << ", " << this->getDaysPerCourse(2) << "}";
    cout << "\t" << "Degree Program: " << programString << endl;
}

// Getters
string Student::getStudentID() {
    return studentID;
}
string Student::getFirstName() {
    return firstName;
}
string Student::getLastName() {
    return lastName;
}
string Student::getEmail() {
    return email;
}
int Student::getAge() {
    return age;
}
int Student::getDaysPerCourse(int position) {
    return daysPerCourse[position];
}
DegreeProgram Student::getDegreeProgram() {
    return degreeProgram;
}

// Setters
void Student::setStudentID(string newID) {
    studentID = newID;
}
void Student::setFirstName(string newFirst) {
    firstName = newFirst;
}
void Student::setLastName(string newLast) {
    lastName = newLast;
}
void Student::setEmail(string newEmail) {
    email = newEmail;
}
void Student::setAge(int newAge) {
    age = newAge;
}
void Student::setDaysPerCourse(int position, int newDays) {
    daysPerCourse[position] = newDays;
}
void Student::setDegreeProgram(DegreeProgram newProgram) {
    degreeProgram = newProgram;
}