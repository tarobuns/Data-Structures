#include "Node.h"

using namespace std;

Node::Node(string n):name(n), next(nullptr) {}

ostream& operator<<(ostream& os, const Node& c) {
    return os << "Name: " << c.name;
}

Node::~Node() {}
