// Done on 2025-11-27 by Anass Basri

#include "Magazine.h"

// Constructor: initializes magazine attributes and base Product attributes
Magazine::Magazine(int id, string name, double price, int issue, string type)
    : Product(id, name, price), issue(issue), type(type) {
}

// Returns the magazine issue number
int Magazine::getIssue() const {
    return issue;
}

// Sets the magazine issue number
void Magazine::setIssue(int issue) {
    this->issue = issue;
}

// Returns the magazine type
string Magazine::getType() const {
    return type;
}

// Sets the magazine type
void Magazine::setType(string type) {
    this->type = type;
}

// Prints all magazine properties
void Magazine::printProperties() {
    cout << "Magazine: " << name
        << " (Issue: " << issue
        << ", Type: " << type
        << ") Price: " << price << " TL" << endl;
}
