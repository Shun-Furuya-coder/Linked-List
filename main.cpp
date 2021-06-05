/*
 CIS 22C: Homework 3

 Build and procees a sorted linked list of College objects.
 The list is sorted in ascending order by the college code.
 Assume that the college code is unique.
*/

// Written By: A. Student
// Changed By: Shun Furuya
// IDE: Xcode


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "LinkedList.h"

using namespace std;

void buildList(const string &filename, LinkedList &list);
void deleteManager(LinkedList &list);
void searchManager(const LinkedList &list);
void displayManager(const LinkedList &list);

int main()
{

    string inputFileName = "colleges.txt";
    LinkedList list;

    buildList(inputFileName, list);
    displayManager(list);
    searchManager(list);
    deleteManager(list);
    displayManager(list);
    return 0;
}

/*
 This function reads data about colleges from a file and inserts them
 into a sorted linked list. The list is sorted in ascending order by code
*/
void buildList(const string &filename, LinkedList &list)
{
    ifstream fin(filename);
    cout << "Reading data from \"" << filename << "\"";

    if(!fin)
    {
        cout << "Error opening the input file: \""<< filename << "\"" << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    while (getline(fin, line))
    {
       int rank, cost;
       string code, name;
    
       stringstream temp(line);   // create temp with data from line
       temp >> rank;              // read from temp
       temp >> code;
       temp.ignore();             // to ignore space in front of name
       getline(temp, name, ';');  // stop reading name at ';'
       temp >> cost;
       // create a College object and initialize it with data from file
       College aCollege(rank, code, name, cost);
       list.insertNode(aCollege);
    }

    fin.close();
}

/*
 Delete manager: delete items from the list until the user enters Q to quit
 deleting
 Input Parameter: list
 */
void deleteManager(LinkedList &list)
{
    string targetCode = "";

    cout << "\n Delete\n";
    cout << "=======\n";

    while(targetCode != "Q")
    {
        cout << endl << "Enter a college code (or Q to stop deleting) : \n";
        cin >> targetCode;
        cout << endl;

        if(targetCode != "Q")
        {
            if(list.deleteNode(targetCode)/* Write your code here: call deleteNode */)
                cout << targetCode << " has been deleted!\n";
            else
                cout << "College \"" << targetCode << "\" was not found in this list." << endl;
        }
    }
    cout << "___________________END DELETE SECTION_____\n";
}

/*
 Search manager: search the list until the user enters Q to quit searching
 Input Parameter: list
 */
void searchManager(const LinkedList &list)
{
    string targetCode = "";
    College aCollege;

    cout << "\n Search\n";
    cout <<   "=======\n";

    while(targetCode != "Q")
    {
        cout << "\nEnter a college code (or Q to stop searching) : \n";
        cin >> targetCode;

        if(targetCode != "Q")
        {
            if(list.searchList(targetCode, aCollege)/* Write your code here: call searchList */)
                aCollege.vDisplay();
            else
                cout << "College \"" << targetCode << "\" was not found in this list." << endl;
        }
    }
    cout << "___________________END SEARCH SECTION _____\n";
}

/*
Display manager: diplay a header, formatted list content, and footer,
 depending on the user's choice;
 displays the number of nodes (always)
Input Parameter: list
 */
void displayManager(const LinkedList &list)
{
    string action;
    
    cout << "\nDisplay list [Y/N]? ";
    cin >> action;

    if(action == "Y" || action == "y")
    {
        cout << "\n====== ==== ============================= =========\n"
             << " Code  Rank         Name                     Cost  \n"
             << "====== ==== ============================= =========\n";
        
        /* Write your code here: call displayList */
        list.displayList();
        
        cout << "====== ==== ============================= =========\n";
    }
    cout << "Number of colleges in this list: " << list.getLength()/* Write your code here: call getLength */<< endl;
}

/* OUTPUT
 
 Reading data from "colleges.txt"
 Display list [Y/N]? Y

 ====== ==== ============================= =========
  Code  Rank         Name                     Cost
 ====== ==== ============================= =========
  ABC    98   AB College                       9998
  CC     10   Cuesta College                  19135
  CPC    99   Cupertino College                9999
  CS     12   College of the Siskiyous        21936
  DAC    1    De Anza College                 19302
  DVC    4    Diablo Valley College           20579
  FC     6    Foothill College                19302
  IVC    9    Irvine Valley College           20577
  NVC    7    Napa Valley College             18920
  OC     8    Ohlone College                  15878
  PCC    5    Pasadena City College           17666
  PVC    15   Palo Verde College              18266
  SBCC   3    Santa Barbara City College      18524
  ZZC    97   ZZ College                       9997

 ====== ==== ============================= =========
 Number of colleges in this list: 14

  Search
 =======

 Enter a college code (or Q to stop searching) :
 DAC
               Rank: 1
        School Name: De Anza College
 Cost of Attendance: $19302

 Enter a college code (or Q to stop searching) :
 Q
 ___________________END SEARCH SECTION _____

  Delete
 =======

 Enter a college code (or Q to stop deleting) :
 SBCC

 SBCC has been deleted!

 Enter a college code (or Q to stop deleting) :
 ZZZ

 College "ZZZ" was not found in this list.

 Enter a college code (or Q to stop deleting) :
 NVC

 NVC has been deleted!

 Enter a college code (or Q to stop deleting) :
 Q

 ___________________END DELETE SECTION_____

 Display list [Y/N]? Y

 ====== ==== ============================= =========
  Code  Rank         Name                     Cost
 ====== ==== ============================= =========
  ABC    98   AB College                       9998
  CC     10   Cuesta College                  19135
  CPC    99   Cupertino College                9999
  CS     12   College of the Siskiyous        21936
  DAC    1    De Anza College                 19302
  DVC    4    Diablo Valley College           20579
  FC     6    Foothill College                19302
  IVC    9    Irvine Valley College           20577
  OC     8    Ohlone College                  15878
  PCC    5    Pasadena City College           17666
  PVC    15   Palo Verde College              18266
  ZZC    97   ZZ College                       9997

 ====== ==== ============================= =========
 Number of colleges in this list: 12
 Program ended with exit code: 0
 
*/
