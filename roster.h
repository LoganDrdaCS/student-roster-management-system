#pragma once
#include "student.h"
#include <iostream>
#include <string>
#include <array>
using namespace std;

class Roster {
public:
    // Default constructor
    Roster();
    // Destructor
    ~Roster();
    Student* classRosterArray[5];
    int studentsCurrentlyOnRoster;
    void add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, string degreeProgram);
    void remove(string studentID);
    void printAll();
    void parse(string row);
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
};
