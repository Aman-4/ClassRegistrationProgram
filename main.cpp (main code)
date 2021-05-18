//
// Author: Aman Anand, UIC, Spring 2021
// Assignment: Project 6
//

//g++ -g -Wall main.cpp list.cpp -o main

#include "classreg.h"

// g++ -g -Wall main.cpp classreg.o queue.o pqueue.o list.o -o main

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <exception>
#include <stdexcept>

using namespace std;

void file_opening(ClassReg* classes)
{
   cout << "**CS Enrollment System**" << endl;
   cout << "Enter enrollments filename>" << endl;
    
   string filename;
   cin >> filename;
   ifstream infile;
   infile.open(filename);
    
   if (!infile.good())
   {
      cout << "**Error: unable to open enrollments file '" << filename << "'" << endl; 
   }   
    
   string netid, className;
   int priority, capacity;
    
   for (int i = 0; i < 5; i++) // traversing through file
   {
       infile >> className;
       infile >> capacity;
       
       classes[i].setName(className);
       classes[i].setCapacity(capacity);
        
       infile >> netid;
                  
       while (netid != "#")
       {
           classes[i].enrollStudent(netid);   
           infile >> netid;
       }
       
       infile >> netid;
       
       while (netid != "#")
       {
           infile >> priority;
           classes[i].waitlistStudent(netid, priority);  
           infile >> netid;
       }
   }    
}

void help()
{
    cout << "stats" << endl;
    cout << "list class" << endl;
    cout << "increase class capacity" << endl;
    cout << "enroll class netid" << endl;
    cout << "waitlist class netid priority" << endl;
    cout << "process filename" << endl;
    cout << "output filename" << endl;
    cout << "quit" << endl;
}

void stats(ClassReg classes[])
{
    cout << "cs111: " << "enrolled=" << classes[0].numEnrolled() << ", waitlisted=" << classes[0].numWaitlisted() << endl;
    cout << "cs141: " << "enrolled=" << classes[1].numEnrolled() << ", waitlisted=" << classes[1].numWaitlisted() << endl;
    cout << "cs151: " << "enrolled=" << classes[2].numEnrolled() << ", waitlisted=" << classes[2].numWaitlisted() << endl;
    cout << "cs211: " << "enrolled=" << classes[3].numEnrolled() << ", waitlisted=" << classes[3].numWaitlisted() << endl;
    cout << "cs251: " << "enrolled=" << classes[4].numEnrolled() << ", waitlisted=" << classes[4].numWaitlisted() << endl;
}

//Sorting Function
void enrolled_selectionSort(string name[], ClassReg classreg)
{
   for (int i = 0; i < classreg.numEnrolled(); i++) // Going through the last index of array
   {
      int minIndex = i;
      for (int j = i+1; j < classreg.numEnrolled(); j++)
      {
         if (name[j] < name[minIndex])  // checking if the name is the minimum index
         {
            minIndex = j;
         }
      }
      
      string temp = name[i];
      name[i] = name[minIndex];  //swapping the variables
      name[minIndex] = temp;
   } 
}

void listClass(ClassReg classreg)
{
    string id;
    int prev;
    
    int capacity;
    capacity = classreg.getCapacity();
    
    cout << "Capacity: " << capacity << endl; // capacity
    
    cout << "Enrolled ";//enrollment
    cout << "(" << classreg.numEnrolled() << "): ";
    
    string* name = new string[classreg.numEnrolled()]; //new array
    
    for(int i = 0; i < classreg.numEnrolled(); i++)
    {
        name[i] = classreg.retrieveEnrolledStudent(i);
    }
    
    enrolled_selectionSort(name, classreg);
    for(int i = 0; i < classreg.numEnrolled(); i++)
    {
        cout << name[i] << " ";
    }
    cout << endl;
    
    cout << "Waitlisted "; //waitlisted
    cout << "(" << classreg.numWaitlisted() << "): ";
    for(int i = 0; i < classreg.numWaitlisted(); i++)
    {
        classreg.retrieveWaitlistedStudent(i, id, prev);
        cout << id << " (" << prev << ") ";
    }
    cout << endl;
    
    delete[] name;
}

void list(ClassReg classes[], string name)
{
    if (name != "cs111" && name != "cs141" && name != "cs151" && name != "cs211" && name != "cs251")
    {
        cout << "**Invalid class name, try again..." << endl;
    }
    
    else
    {
        cout << name << endl;
    }
   
    if (name == "cs111")
    {
        listClass(classes[0]);
    }
    else if (name == "cs141")
    {
        listClass(classes[1]);
    }
    else if (name == "cs151")
    {
        listClass(classes[2]);
    }
    else if (name == "cs211")
    {
        listClass(classes[3]);
    }
    else if (name == "cs251")
    {
        listClass(classes[4]);
    }
}

void increase_capacity(ClassReg classes[], int cap, string name)
{   
    if (name != "cs111" && name != "cs141" && name != "cs151" && name != "cs211" && name != "cs251")
    {
        cout << "**Invalid class name, try again..." << endl;
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            string class_name = classes[i].getName(); 
            if(class_name == name)
            {
                int x = classes[i].getCapacity();
                {
                    if (x<=cap)
                    {
                        classes[i].setCapacity(cap);
                        int new_cap = classes[i].getCapacity();
                        cout << class_name << endl;
                        cout << "Capacity: " << new_cap << endl;
                    }
                    else
                    {
                        cout << "**Error, cannot decrease class capacity, ignored..." << endl;
                    }
                }
            }    
        }
     }         
}

void enroll(ClassReg classreg, ClassReg classes[], string class_name, string student)
{   
    if (class_name != "cs111" && class_name != "cs141" && class_name != "cs151" && class_name != "cs211" && class_name != "cs251")
    {
        cout << "**Invalid class name, try again..." << endl;
    }
    else
    {
        int index = -1;
        for(int i = 0; i < 5; i++)
        {
            string course = classes[i].getName(); 
            if(class_name == course)
            {
                index = i;
                break;
            }
        }    

        int x = classes[index].searchEnrolled(student); // return -1
        int y = classes[index].searchWaitlisted(student); // return -1

        if (x != -1) //student is found 
        {
            cout << "Student '" << student << "' enrolled in " << class_name << endl;
        }
        else if (y != -1)
        {
            int capacity = classes[index].getCapacity();
            int enrolled_students = classes[index].numEnrolled();
            if (capacity > enrolled_students)
            {
                classes[index].removeWaitlistedStudent(y);
                classes[index].enrollStudent(student);
                cout << "Student '" << student << "' enrolled in " << class_name << endl;
            }
            else 
            {
                cout << "Class full, '" << student << "' waitlisted for " << class_name << endl;
            }
        }
        else
        {
            int capacity = classes[index].getCapacity();
            int enrolled_students = classes[index].numEnrolled();
            if (capacity > enrolled_students)
            {
                classes[index].enrollStudent(student);
                cout << "Student '" << student << "' enrolled in " << class_name << endl;
            }
            else
            {
                int waitlisted = classes[index].numWaitlisted();
                if(waitlisted == 0)
                {
                    classes[index].waitlistStudent(student, 1);
                    cout << "Class full, '" << student << "' waitlisted for " << class_name << endl;
                }
                else   
                {
                    string id;
                    int priority;
                    classes[index].retrieveWaitlistedStudent(waitlisted-1, id, priority);
                    classes[index].waitlistStudent(student, priority);
                    cout << "Class full, '" << student << "' waitlisted for " << class_name << endl;
                }
            }
        }
    }
}

void waitlist_class(ClassReg classreg, ClassReg classes[], string class_name, string student, int priority)
{
    if (class_name != "cs111" && class_name != "cs141" && class_name != "cs151" && class_name != "cs211" && class_name != "cs251")
    {
        cout << "**Invalid class name, try again..." << endl;
    }
    
    else
    {
        int index = -1;
        for(int i = 0; i < 5; i++)
        {
            string course = classes[i].getName(); 
            if(class_name == course)
            {
                index = i;
                break;
            }
        }    

        int x = classes[index].searchEnrolled(student); // return -1

        if (x != -1) //student is found 
        {
            cout << "Student '" << student << "' enrolled in " << class_name << endl;
        }
        else //student is found 
        {
            classes[index].waitlistStudent(student, priority);
            cout << "Student '" << student << "' waitlisted for " << class_name << endl;
        }
    }
 
}

void outfile_helper(ClassReg& course, ofstream& outfile)
{
    string course_name = course.getName();
    int capacity = course.getCapacity();
    outfile << course_name << endl;
    outfile << capacity << endl;
    string id;
    int prev; 
    
//     string* name = new string[course.numEnrolled()]; //new array
    
    for(int i = 0; i < course.numEnrolled(); i++)
    {
        outfile << course.retrieveEnrolledStudent(i) << " ";
    }
    
//     enrolled_selectionSort(name, course);
//     for(int i = 0; i < course.numEnrolled(); i++)
//     {
//         outfile << name[i] << " ";
//     }
    outfile << "#" << endl;
    
    for(int i = 0; i < course.numWaitlisted(); i++)
    {
        course.retrieveWaitlistedStudent(i, id, prev);
        outfile << id << " " << prev << " ";
    }
    outfile << "#" << endl; 
}

void output(ClassReg classes[], string filename)
{
   ofstream outfile;
   outfile.open(filename);

   if (!outfile.good())
   {
       cout << "**Error: unable to open enrollments file '" << filename << "'" << endl; 
   }   
           
   for(int i = 0; i < 5; i++)
   {
       outfile_helper(classes[i], outfile);
   }
    
   outfile.close();
}

void process(istream& input, bool promptUser, ClassReg& classreg, ClassReg classes[])
{
   string command;
   if (promptUser == true)
   { 
       cout << "Enter a command (help for more info, quit to stop)>" << endl;
   }
   input >> command;
    
   while (command != "quit" && command != "q") 
   { 
       if (command == "h" || command == "help")
       {
           help();
       }
       else if (command == "s" || command == "stats")
       {
           stats(classes);
       }
       else if (command == "l" || command == "list")
       {
           string name;
           input >> name;
           list(classes,name);
       }
       else if (command == "i" || command == "increase")
       {
           string name;
           int cap;
           input >> name >> cap;
           increase_capacity(classes,cap,name);
       }
       else if (command == "e" || command == "enroll")
       {
           string class_name,student;
           input >> class_name >> student;
           enroll(classreg,classes,class_name,student);
       }
       else if (command == "w" || command == "waitlist")
       {
           string class_name,student;
           int priority;
           input >> class_name >> student >> priority;
    
           waitlist_class(classreg,classes,class_name,student,priority);
       }
       else if (command == "q" || command == "quit")
       {
           break;
       }
       else if (command == "p" || command == "process")
       {
           string filename;
           input >> filename;
           ifstream infile;
           infile.open(filename);

           if (!infile.good())
           {
              cout << "**Error: unable to open enrollments file '" << filename << "'" << endl; 
           } 
           else
           {
               cout << "**Processing commands from '" << filename << "'" << endl; 
               process(infile, false, classreg, classes); //recursive step
               infile.close();
               cout << "**Done processing '" << filename << "'" << endl;             
           }
       }
       else if (command == "o" || command == "output")
       {
           string filename;
           input >> filename;
           output(classes,filename);
           cout << "Enrollment data output to '" << filename << "'" << endl;
       }
       
       else 
       {
           cout << "**Invalid command, please try again..." << endl;
       }
       if (promptUser == true)
       { 
           cout << "Enter a command (help for more info, quit to stop)>" << endl;
       }
       
       input >> command;
    }

    if (promptUser == true)
    {
         cout << "**Done**" << endl;
    }
}


int main()
{
   ClassReg classes[5];
   ClassReg classreg;
   file_opening(classes);
    
   process(cin, true, classreg, classes);
    
   return 0;
}
