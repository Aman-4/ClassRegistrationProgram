// g++ -g -Wall main.cpp classreg.o queue.o pqueue.o list.o -o main

/*main.cpp*/
//
// Author: Aman Anand
//
// An intro to ClassReg class, and project 06.
//

#include<iostream>
#include <string>
#include "classreg.h"

using namespace std;
int main()
{
    ClassReg classreg; // our object for handling class enrollment
    string name, id;
    int cap;
    cout << "Enter class name>" << endl;
    cin >> name;
    classreg.setName(name);
    cout << "Enter class capacity>" << endl;
    cin >> cap;
    classreg.setCapacity(cap);

    string command;
    int position = 1;
    cout << "Enter a student name to enroll (# to stop)>" << endl;
    cin >> command;
    while (command != "#")
    {
        if(classreg.numEnrolled() >= classreg.getCapacity())
        {
            classreg.waitlistStudent(command, position);
            cout << "Student '" << command << "' added to waitlist" << endl;       
        }
        else
        {
            classreg.enrollStudent(command);
            cout << "Student '" << command << "' was enrolled" << endl; 
             
        }
        cout << "Enter a student name to enroll (# to stop)>" << endl;
        cin >> command;
    }
    
    int x = 0;
    cout << classreg.getName() << endl;
    cout << "capacity: " << classreg.getCapacity() << endl;
    cout << "enrolled: ";
    
    while(x!=classreg.numEnrolled())
    {
        cout << classreg.retrieveEnrolledStudent(x) << " ";
        x+=1;
    }
    cout << endl;
    
    cout << "waitlisted: ";
    
    int prev;
    
    for(int i = 0; i < classreg.numWaitlisted(); i++)
    {
        classreg.retrieveWaitlistedStudent(i, id, prev);
        cout << id << " ";
    }
    
    cout << endl;
    
    return 0;
}