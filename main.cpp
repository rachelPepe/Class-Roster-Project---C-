//
//  main.cpp
//  Applications Project
//
//  Created by Rachel Pepe on 2/26/24.
//

#include <iostream>
#include "roster.hpp"
using namespace std;

int main () {
    // Input information for Class Roster, including my information.
    const string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Rachel,Pepe,rpepe3@wgu.edu,31,4,10,16,SOFTWARE"};
    const int numStudents = 5;
    Roster ClassRoster; // F.2 Create instance of Roster called classRoster.
    
    // F.1 - Print to screen; course title, language used, student ID, my name.
    cout << "Class: Scripting and Programming - Applications - C867 / C++ language / Student ID: 011613072 / Name: Rachel Pepe" << endl << endl << endl;
    
    
    // F.3 - Add each student to classRoster.
    for (int i = 0; i < numStudents; i++) {
        ClassRoster.ParseStudentData(studentData[i]);
    }
    
    
    cout << "Class Roster: " << endl;
    ClassRoster.PrintAll(); // F.4 - PrintALL() for classRoster.
    cout << endl << endl;
    
    
    cout << "Invalid emails: " << endl;
    ClassRoster.PrintInvalidEmails(); // F.4 Print invalid emails.
    cout << endl << endl << endl;
        
    
    cout << "Student's average days in course by student id: " << endl;
    ClassRoster.PrintAverageDaysInCourse(); // F.4 - Print average days in course for each student.
    cout << endl;
    
    
    for (int i = 0; i <3; i++) {
        cout << "Class roster by degree type: " << degreeProgramStrings[i] << endl << endl;
        ClassRoster.PrintByDegreeProgram((DegreeProgram)i); // F.4 - Print by degree program.
        cout << endl;
    }
    cout << endl;
        
    
    
    cout << "Removing student with ID# A3: " << endl;
    ClassRoster.RemoveStudentByID("A3"); // F.4 - Remove student A3.
    cout << endl;
        
    cout << "Removing student with ID# A3: " << endl;
    ClassRoster.RemoveStudentByID("A3"); // F.4 - Remove student A3 again to show "Not found.".
    cout << endl;
    
    return 0;
}

