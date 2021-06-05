// Specification file for the LinkedList class
// Written By: A. Student
// Changed By: Shun Furuya
// IDE: Xcode

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "College.h"

class LinkedList
{
private:
    struct Node
    {
        College college;
        Node *next;
    };

    Node *head;
    int length;

public:
    LinkedList();   // constructor
    ~LinkedList();  // destructor

    // Linked list operations
    int getLength() const {return length;}
    void insertNode(College);
    bool deleteNode(string);
    void displayList() const;
    bool searchList(string, College &) const;
};

#endif
