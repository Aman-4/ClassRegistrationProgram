/*list.cpp*/

// 
// Author: Aman Anand, UIC, Spring 2021
// Assignment: Project 6
//
// Author: Prof. Hummel, U. of I. Chicago, Spring 2021
// 
// Implements a one-way linked-list with optimized insertion at
// head and tail of list. The nodes contain 2 data values, a string
// and an integer.
//

// 

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

#include "list.h"

using namespace std;



//
// private member functions:
//

//
// inits this list then makes deep copy of other
//
// Time complexity: O(N)
//
void List::initAndDeepCopy(const List& other)
{
   //
   // TODO: init this list, then make copy of other
   //
    
    this->Head = nullptr;
    this->Count = 0;
    this->Tail = nullptr;
    Node* cur = other.Head;
    
    string value1;
    int value2;
 
    while (cur != nullptr)
    {
        value1 = cur->Data.Value1;
        value2 = cur->Data.Value2;
        //push_back values
        this->push_back(value1, value2);
        //traverse
        cur = cur->Next;
    }
}

// 
// free the nodes in the list and resets to empty
//
// Time complexity: O(N)
//
void List::freeAndReset()
{
   //
   // TODO: free this list, then reset to empty
   //
   Node* cur = this->Head;
   Node* count;
    
    while (cur!=nullptr) // traversing through end 
    {
        count = cur->Next;
        delete cur;
        cur = count;
    }
    
    this->Count = 0;
    this->Head = nullptr;
}



//
// public member functions:
//

//
// default constructor
//
// Initializes the list to empty.
// 
// Time complexity: O(1)
//
List::List()
{
   this->Head = nullptr;
   this->Tail = nullptr;
   this->Count = 0;
}

//
// copy constructor
//
// Makes a deep copy of the other list into this list.
// 
// Time complexity: O(N)
//
List::List(const List& other)
{
   this->initAndDeepCopy(other);
}

//
// destructor
//
// Frees all memory related to this list, and then resets to empty.
// 
// Time complexity: O(N)
//
List::~List()
{
   this->freeAndReset();
}

//
// assignment operator (e.g. L2 = L;)
//
// Makes a deep copy of the other list into this list; since this
// list already exists, the existing elements of this list are freed
// before the copy is made.
// 
// Time complexity: O(N)
//
List& List::operator=(const List& other)
{
   if (this == &other)  // special case: check for L = L;
      return *this;     // do nothing and just return THIS object back

   //
   // This is different from a copy constructor, because "this" list
   // exists and contains nodes.  So we have to free "this" list before
   // we copy the "other" list:
   //
   this->freeAndReset();
   this->initAndDeepCopy(other);

   return *this;  // done, return THIS object back
}

//
// size
//
// Returns the # of elements in the list.
//
// Time complexity: O(1)
//
int List::size()
{
   //
   // TODO:
   //
    
   return Count;
   return -123;
}

//
// empty
//
// Returns true if empty, false if not.
//
// Time complexity: O(1)
//
bool List::empty()
{
   //
   // TODO:
   //
    
   if (this->Head == nullptr)
   {
       return true;
   }
   else
   {
       return false;
   }

}

//
// search
//
// Search the list for the first occurence of the string value.
// If found, its position in the list is returned. Positions are 
// 0-based, meaning the first node is position 0. If the value is
// not found, -1 is returned.
//
// Time complexity: on average O(N)
//
int List::search(string value)
{
   //
   // TODO:
   //
   Node* cur = this->Head;
   int position = 0;
   while(cur!=nullptr)
   {  
      if(cur->Data.Value1 == value)
      {
         return position;
      }
      position+=1;
      cur = cur -> Next;  
   }
   
   return -1;
}

//
// retrieve
//
// Retrieve's the data from node at the given position; the list 
// remains unchanged. Positions are 0-based, meaning the first node
// is position 0. Throws an "invalid_argument" exception if the 
// position is invalid, i.e. 
// throw invalid_argument("List::retrieve: invalid position");
//
// Time complexity: on average O(N)
//
void List::retrieve(int pos, string& value1, int& value2)
{
   //
   // TODO:
   //
   Node* cur = this->Head;
   
   int x = 0; 
   
   if (pos >= this->Count || pos < 0) // if position is invalid
   {
      throw invalid_argument("List::retrieve: invalid position");
   }
   else // otherwise while poisition is valid traverse and increase index variable
   {
      while(pos > x)
      {
         cur = cur->Next;
         x = x + 1;
      }
      value1 = cur->Data.Value1;
      value2 = cur->Data.Value2;
      
      return;
   }
   throw invalid_argument("List::retrieve: invalid position");
}

//
// insert
//
// Inserts the given data in the list such that after
// the insertion, the value is now at the given
// position.
//
// Positions are 0-based, which means a position of 0 
// denotes the data will end up at the head of the list,
// and a position of N (where N = the size of the list)
// denotes the data will end up at the tail of the list.
// If the position is invalid, throws an exception, i.e.
// throw invalid_argument("List::insert: invalid position");
//
// Time complexity: on average O(N)
//
void List::insert(int pos, string value1, int value2)
{
//    //
//    // TODO:
//    //
   
    if(pos == 0)
    {
        push_front(value1, value2);
        return;
    }
    else if(pos == Count)
    {
        push_back(value1, value2);
        return; 
    }
    int x = 0; //counter variable
    
    Node* cur = Head;    
    while(cur != nullptr)
    {
        if(pos-1 == x)
        {
            Node* newNode = new Node(); //create new Node
            newNode->Data.Value1 = value1; //set data value 
            newNode->Data.Value2 = value2;
            newNode->Next = cur->Next; //traverse
            cur->Next = newNode;
            Count++; //increment
            return;
        }
        x++; //increment
        cur = cur->Next;
    }
    throw invalid_argument("List::insert: invalid position");
}

//
// remove
//
// Removes and deletes the node at the given position; no data is
// returned. Positions are 0-based, meaning the first node
// is position 0. Throws an "invalid_argument" exception if the 
// position is invalid, i.e. 
// throw invalid_argument("List::remove: invalid position");
//
// Time complexity: on average O(N)
//

void List::remove(int pos)
{
   //
   // TODO:
   //
   Node* cur = Head;
   Node* prev = cur;
   
   int x = 0; // index variable
   
   if (pos < 0 || pos >= Count || Count == 0)
   {
      throw invalid_argument("List::remove: invalid position");
   }
   
   // when position is 0, the head should be the next node
   else if (pos == 0)
   {
       Head = cur->Next;
       //delete
       delete cur;
       //decerement
       Count--;
       return;
   }
   else
   {
       while(x != pos-1)
       {
           prev = prev->Next;
           x++;
       }
       // traverse
       cur = prev->Next;
       prev->Next = cur->Next;
   }
   //delete
   delete cur;
   //decerement
   Count--;

   //throw invalid_argument("List::remove: invalid position");
}

//
// front
//
// Returns the data from the first node in the list. Throws an 
// exception if the list is empty, i.e.
// throw runtime_error("List::front: empty list");
// 
// Time complexity: O(1)
//
void List::front(string& value1, int& value2)
{
   //
   // TODO:
   //
   if(this->empty())
   {
       throw runtime_error("List::front: empty list");
   }
   
   else
   {
       this->Head->Data.Value1 = value1;
       this->Head->Data.Value2 = value2;
   } 
}

//
// back
//
// Returns the data from the last node in the list. Throws an 
// exception if the list is empty, i.e.
// throw runtime_error("List::back: empty list");
// 
// Time complexity: O(1)
//
void List::back(string& value1, int& value2)
{
   //
   // TODO:
   //
   if(this->empty())
   {
       throw runtime_error("List::back: empty list");
   }
   
   else
   {
       this->Tail->Data.Value1 = value1;
       this->Tail->Data.Value2 = value2;
   } 
}

//
// push_front
//
// Inserts the given data at the front of the list.
// 
// Time complexity: O(1)
//
void List::push_front(string value1, int value2)
{
   //
   // TODO:
   //
    Node* newNode = new Node();
    newNode->Data.Value1 = value1;
    newNode->Data.Value2 = value2;
    // next node's value should be ... head
    newNode->Next = Head;
    Head = newNode;
    
    if(Count == 0)
    {
        Tail = newNode;
    }
    
    
    Count++;
    
}

//
// push_back
//
// Inserts the given data at the back of the list.
// 
// Time complexity: O(1)
//
void List::push_back(string value1, int value2)
{
   //
   // TODO:
   //
    
    Node* newNode = new Node();
    newNode->Data.Value1 = value1;
    newNode->Data.Value2 = value2;
    
    if(Count == 0)
    {
        Head = newNode;
        Tail = newNode;
        // set next node to nullptr
        newNode->Next = nullptr;
    }
    // List is empty so new node is a head and return 
    else
    {
        Tail->Next = newNode;
        newNode->Next = nullptr;
        Tail = newNode;   
    }
  
    this->Count++;
   
}
