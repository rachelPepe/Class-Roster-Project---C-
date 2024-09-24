//
//  student.hpp
//  Applications Project
//
//  Created by Rachel Pepe on 2/26/24.
//

#ifndef student_hpp
#define student_hpp

#include <stdio.h>
#include <iostream>
#include "degree.hpp"

using namespace std;

class Student {
// Declarations for Student class mutator and accessor functions.
public: const static int daysArraySize = 3;
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int studentAge;
    DegreeProgram degreeProgram;
    int ArrayDaysPerClass[daysArraySize];
    
public:
    Student();
    Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int ArrayDaysPerClass[daysArraySize], DegreeProgram degreeProgram);
    ~Student();
    
    void SetStudentID(string StudentID);
    string GetStudentID ();
    
    void SetFirstName(string firstName);
    string GetFirstName ();
    
    void SetLastName(string lastNname);
    string GetLastName();
    
    void SetEmailAddress(string emailAddress);
    string GetEmailAddress();
    
    void SetAge(int studentAge);
    int GetAge();
    
    void SetArrayDaysPerClass(int ArrayDaysPerClass[]);
    int* GetArrayDaysPerClass();
    
    void SetDegreeProgram(DegreeProgram degree);
    DegreeProgram GetDegreeProgram();
    
    void Print();
    
};
#endif /* student_hpp */
