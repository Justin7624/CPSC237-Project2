// File: testLL.cpp
// Test the template ordered linked list object type

#include <iostream>
#include <stdlib.h>
#include "CLinkedList.h"

//function prototypes
void test();
void printMenu();
void MenuFunctionality();

/**************************************************************************
* Function name: main
* Description: Calls printMenu() and actualMenuFunctionality() to allow 
* the user to manually create a linked list, print it forwards, print 
* it backwards, as well as add and remove from the list
**************************************************************************/
int main()
{
  printMenu();
  MenuFunctionality();
  //ends program after menu funct is left
  return (0);
}

/**************************************************************************
* Function name: MenuFunctionality
* Loops the menu until the user decides to quit
* and calls the functions for each menu option
**************************************************************************/
void MenuFunctionality()
{
  //create empty list
  CLinkedList<int>	l1;
  int		x;

  //char to hold menu choice
  char choice;
    while (cin >> choice)
    {
        switch(choice)
        {
            case 'I': case 'i':
        //read in x to add
        cout << "What number would you like to insert?" << endl;
        cin>>x;
                //insert x
        cout<< "Inserted " << x << endl;
        l1.orderedInsert(x);
        //cout << endl;
        printMenu(); 
        break;
      case 'R': case 'r':
        //read in x to remove
        cout << "What number would you like to remove?" << endl;
        //remove x
        cin >> x;
        l1.remove(x);
        printMenu();
        break;
      case 'F': case 'f':
        cout << l1 << endl;
        cout << endl;
        printMenu();
        break;
      case 'B': case 'b':
        l1.startBackwardsPrint();
        cout << endl;
        printMenu();
        break;
      case 'E': case 'e':
        //exit the function
        return;
            default:
                cout << "You entered an invalid number selection" << endl;
        cout << endl;
        printMenu();
                break;

        }
  }
}

//Displays the menu options
void printMenu()
{
  cout << "choose from the following:" << endl;
  cout << "----------------" << endl;
  cout << "I)nsert Integer" << endl;
  cout << "R)emove Integer" << endl;
  cout << "F)orward Print" << endl;
  cout << "B)ackward Print" << endl;
  cout << "E)xit" << endl;
}