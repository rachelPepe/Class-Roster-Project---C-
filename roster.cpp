//
//  roster.cpp
//  Applications Project
//
//  Created by Rachel Pepe on 2/28/24.
//

#include "roster.hpp"
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// Parse out each students information, one row at a time.
void Roster::ParseStudentData(string studentData) {
    string studentid;
    string f;
    string l;
    string address;
    int ageStudent;
    int days1;
    int days2;
    int days3;
    string programType;
    DegreeProgram degree = NETWORK;
    int beforeComma; // Variable used to find the commas and substrings.
    int afterComma; // Variable used to find the commas and substrings.
    
    beforeComma = studentData.find(",");
    studentid = studentData.substr(0, beforeComma);
    
    afterComma = beforeComma + 1;
    beforeComma = studentData.find(",", afterComma);
    f = studentData.substr(afterComma, beforeComma - afterComma);
    
    afterComma = beforeComma + 1;
    beforeComma = studentData.find(",", afterComma);
    l = studentData.substr(afterComma, beforeComma - afterComma);
    
    afterComma = beforeComma + 1;
    beforeComma = studentData.find(",", afterComma);
    address = studentData.substr(afterComma, beforeComma - afterComma);
    
    afterComma = beforeComma + 1;
    beforeComma = studentData.find(",", afterComma);
    ageStudent = stoi(studentData.substr(afterComma, beforeComma - afterComma));
    
    afterComma = beforeComma + 1;
    beforeComma = studentData.find(",", afterComma);
    days1 = stoi(studentData.substr(afterComma, beforeComma - afterComma));
    
    afterComma = beforeComma + 1;
    beforeComma = studentData.find(",", afterComma);
    days2 = stoi(studentData.substr(afterComma, beforeComma - afterComma));
    
    afterComma = beforeComma + 1;
    beforeComma = studentData.find(",", afterComma);
    days3 = stoi(studentData.substr(afterComma, beforeComma - afterComma));
    
    afterComma = beforeComma + 1;
    beforeComma = studentData.find(",", afterComma);
    programType = studentData.substr(afterComma, beforeComma - afterComma);
    
    // Branch to assign degree program type to a string.
    if (programType == "SECURITY") {
        degree = SECURITY;
    }
    else if (programType == "NETWORK") {
        degree = NETWORK;
    }
    else {
        degree = SOFTWARE;
    }
    
    add(studentid, f, l, address, ageStudent, days1, days2, days3, degree);
}

// Adds each student object to classRosterArray.
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int types[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, types, degreeProgram);
}

// Prints a complete list of student data.
void Roster::PrintAll() {
    for (int i = 0; i <= Roster::lastIndex; i++){
        classRosterArray[i]->Print();
    }
}

void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i <= Roster::lastIndex; ++i) {
        if (Roster::classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
            classRosterArray[i]->Print();
        }
    }
}

void Roster::PrintInvalidEmails() {
    bool invalid = false;
    string addressEmail;
    
    // Valid emails must include '@' and '.', and cannot include a space.
    for (int i = 0; i <= Roster::lastIndex; ++i) {
        addressEmail = (classRosterArray[i]->GetEmailAddress());
        if (addressEmail.find(' ') != string::npos || (addressEmail.find('@') == string::npos || addressEmail.find('.') == string::npos)) {
            invalid = true;
            cout << "Invalid email: " << addressEmail << ", ";
        }
    }
    if (!invalid) {
        cout << "NONE" << endl;
    }
}

void Roster::PrintAverageDaysInCourse() {
    for (int i = 0; i <= Roster::lastIndex; i++){
        cout << classRosterArray[i]->GetStudentID() << ": ";
        cout << (classRosterArray[i]->GetArrayDaysPerClass()[0] + classRosterArray[i]->GetArrayDaysPerClass()[1] + classRosterArray[i]->GetArrayDaysPerClass()[2]) / 3 << endl;
    }
    cout << endl;
}

void Roster::RemoveStudentByID(string studentid) {
    bool valid = false;
    
    
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (classRosterArray[i]->GetStudentID() == studentid) {
            valid = true;
            // Move the removed student to the last index of the array.
            if (i < numStudents - 1){
                Student* swap = classRosterArray[i];
                classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = swap;
            }
            // Decrement last index to remove the last student.
            Roster::lastIndex--;
        
        }
        
    }
    if (valid){
        cout << studentid << " student removed from roster." << endl;
    }
    else {
        cout << "Not found." << endl;
    }
}

// Destructor to release the memory that was allocated dynamically Roster.
Roster::~Roster() {
    cout << "Destructor initializing" << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << "Destroying Student #" << classRosterArray[i]->GetStudentID() << endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}

