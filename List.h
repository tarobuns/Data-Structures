#ifndef LIST_H
#define LIST_H
#include "Node.h"

#pragma once

class List
{
public:
    List(); //Constructor Prototype
    void addToHead(const std::string&);
    void printList();
    void printSize();
    void insertInOrder(const std::string&);
    void deleteName(const std::string&);
    void recursivelyPrint();
    void recursivelyPrintBack();

private:
    Node* head; //Head pointer
    int size;
    void recursivelyPrint(Node*); // Private member function
    void recursivelyPrintBack(Node*);
};

#endif