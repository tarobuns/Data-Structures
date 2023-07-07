#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
#pragma once

class Node
{
    friend std::ostream& operator<<(std::ostream& os, const Node& c);
    friend class List; //Specifies that class List is a friend
public:
    Node(std::string name = "None");
    ~Node();

private://elements of the node
    std::string name;
    Node* next;//next pointer, points to a type Node
};

#endif
