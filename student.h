#pragma once
#include "degree.h"
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int daysPerCourse[3];
    DegreeProgram degreeProgram;
public:
    Student();
    // Constructor with parameters
    Student(string id, string fName, string lName, string email, int age, int days1, int days2, int days3, string program);
    // Getters
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int getDaysPerCourse(int position);
    DegreeProgram getDegreeProgram();
    // Setters
    void setStudentID(string newID);
    void setFirstName(string newFirst);
    void setLastName(string newLast);
    void setEmail(string newEmail);
    void setAge(int newAge);
    void setDaysPerCourse(int position, int newDays);
    void setDegreeProgram(DegreeProgram newProgram);
    // Functions, Other
    void print();
};