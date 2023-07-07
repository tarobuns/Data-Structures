#include "List.h"

using namespace std;

List::List():head(nullptr), size(0) {}

void List::addToHead(const string& name)
{
    Node* newOne = new Node(name);//create a newOne pointer that is allocated on the heap, and it is a Node initialized to the name that is passed in

    if (head == nullptr) {
        head = newOne;
    } else {
        newOne->next = head; // setting newOne's next pointer in node to where ever head is pointing
        head = newOne;
    }

    size++;
}

void List::printList() {
    Node* curr = head;

    while (curr != nullptr) {
        cout << *curr << endl;
        curr = curr->next;
    }
}


void List::printSize() {
    cout << size << endl;
}


void List::insertInOrder(const string& name) {
    Node* newNode = new Node(name);
    
    if (head == nullptr) { // Case 1 - Empty list
        head = newNode;
    } else {
    
        Node* curr = head;
        Node* prev = nullptr;
        while (curr != nullptr) { // Traverse list to find insertion location
            if (curr->name >= newNode->name) {
                break;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        if (curr == head) { // Insert at appropriate location
            newNode->next = head;
            head = newNode;
        } else {
            newNode->next = curr;
            prev->next = newNode;
        }
    }
    size++;
}

void List::deleteName(const string& name) {
    Node* curr = head;
    Node* prev = nullptr;

    if (head == nullptr) {
        cout << "No node to delete, empty list" << endl;
        return;
    }

    while (curr != nullptr) {//To find the node to delete
        if (curr->name == name) {
            break;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    if (curr == nullptr) {
        cout << "Name not found in list" << endl;
    }

    if (curr != nullptr) { // if curr == nullptr, there is no node to delete
        if (curr == head) { // If curr points to where head is pointing
            head = head->next; // Have head point to the next object, and it works because curr isn't null and the next could be pointing to nullptr
        } else {
            prev->next = curr->next;
        }
        delete curr; // Deletes what the pointer is pointing to
        size--;
    }
}

void List::recursivelyPrint() {
    recursivelyPrint(head); // Passes it in into the private member function to recursively call
}

void List::recursivelyPrint(Node* curr) {
    if (curr != nullptr) {
        //recursivelyPrint(curr->next); // Calls it backwards if placed first, because it reaches the end of the list and goes backwards
        cout << *curr << endl;
        recursivelyPrint(curr->next); // Recursively call until curr == nullptr
    }
}

void List:: recursivelyPrintBack() {
    recursivelyPrintBack(head);
}

void List::recursivelyPrintBack(Node* curr) {
    if (curr != nullptr) {
        recursivelyPrintBack(curr->next);
        cout << *curr << endl;
    }
}
