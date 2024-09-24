//
//  roster.hpp
//  Applications Project
//
//  Created by Rachel Pepe on 2/28/24.
//

#ifndef roster_hpp
#define roster_hpp

#include "student.hpp"
#include <stdio.h>
#include <iostream>
using namespace std;

class Roster {
// Roster class function declarations.
private:
    int lastIndex = -1;
    const static int numStudents = 5;
    Student* classRosterArray[numStudents]; // Array of pointers to hold data from studentData Table.

public:
    ~Roster(); //Destructor
    void ParseStudentData(string studentData);
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void RemoveStudentByID(string studentid);
    void PrintAll();
    void PrintByDegreeProgram(DegreeProgram programDegree);
    void PrintInvalidEmails();
    void PrintAverageDaysInCourse();
};

#endif /* roster_hpp */
