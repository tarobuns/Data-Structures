#include <iostream>
#include "List.h"

using namespace std;

int main() {

    cout << "Hello" << endl;
    
    List* cl1 = new List();//new List() dynamically allocates memory on the heap to create an object of list class, List() is the constructor
    
    string name;

    // Implement a menu of options to choose from?

    while (true) {
        cout << "Enter the name of the contact or q to quit." << endl;
        cin >> name;
        if (name == "q" || name == "Q") {
            break;
        } else {
            cl1->insertInOrder(name);//cl1 accesses the addToHead function in list
        }
    }

    cl1->printList();
    cl1->deleteName("Arry");
    cl1->recursivelyPrint(); // Recursively calls the list in order
    cl1->printSize();
    
    return 0;
}