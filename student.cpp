//
//  student.cpp
//  Applications Project
//
//  Created by Rachel Pepe on 2/26/24.
//

#include "student.hpp"
#include <stdio.h>
#include <iostream>
using namespace std;

// Default Constructor
Student::Student() : studentID("NotAssigned"), firstName("NoName"), lastName("NoName"), emailAddress("None"), studentAge(0), degreeProgram(NETWORK) {
    for (int i = 0; i < daysArraySize; ++i) {
        ArrayDaysPerClass[i] = 0;
    }
}

// Constructor
Student::Student(string id, string first, string last, string email, int age, int daysList[], DegreeProgram degree) {
    studentID = id;
    firstName = first;
    lastName = last;
    emailAddress = email;
    studentAge = age;
    degreeProgram = degree;
    for (int i = 0; i < daysArraySize; ++i) {
        ArrayDaysPerClass[i] = daysList[i];
    }
}

// Destructor
Student::~Student() {
}

// Definitions for mutators(setters) and accessors(getters) for each instance variable from D1.
void Student::SetStudentID(string id) { studentID = id; }
string Student::GetStudentID () { return studentID; }

void Student::SetFirstName(string first) { firstName = first; }
string Student::GetFirstName() { return firstName; }

void Student::SetLastName(string last) { lastName = last; }
string Student::GetLastName() { return lastName; }

void Student::SetEmailAddress(string email) { emailAddress = email; }
string Student::GetEmailAddress() { return emailAddress; }

void Student::SetAge(int age) { studentAge = age; }
int Student::GetAge() { return studentAge; }

void Student::SetDegreeProgram(DegreeProgram degree) { degreeProgram = degree; }
DegreeProgram Student::GetDegreeProgram() { return degreeProgram; }

void Student::SetArrayDaysPerClass(int daysList[]) {
    for (int i = 0; i < daysArraySize; ++i) {
        ArrayDaysPerClass[i] = daysList[i];
    }
}
int* Student::GetArrayDaysPerClass() { return ArrayDaysPerClass; }

// Print() definition for specific student data.
void Student::Print() {
    cout << GetStudentID() << '\t';
    cout << GetFirstName() << '\t';
    cout << GetLastName() << '\t';
    cout << GetEmailAddress() << '\t';
    cout << GetAge() << '\t';
    cout << GetArrayDaysPerClass()[0] << '\t';
    cout << GetArrayDaysPerClass()[1] << '\t';
    cout << GetArrayDaysPerClass()[2] << '\t';
    cout << degreeProgramStrings[GetDegreeProgram()] << endl;
    
}
