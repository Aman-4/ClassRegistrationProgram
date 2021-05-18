#include "list.h"

//make test
// ./testing
int main()
{
    List myList;
    myList.push_front("Aman",1);
    myList.insert(0,"aaa",4);
    myList.push_back("abc",4);
    myList.insert(1,"bbb",4);
    myList.insert(5,"ccc",4);
    
    
    int x;
    string aman;
    for (int i = 0; i < myList.size(); i++)
    {
        myList.retrieve(i, aman, x);
        cout << aman << " " << x << endl;
    }
    
    
}