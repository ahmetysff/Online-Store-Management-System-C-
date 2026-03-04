// Done on 2025-12-06 by Metin Talha Çite

#include "Check.h"

// Constructor: initializes check owner name and bank ID
Check::Check(string name, string bankID)
    : Payment(amount), name(name), bankID(bankID) {
}

// Performs the check payment
void Check::performPayment() {
    cout << "Performing check payment (Bank: " << bankID << ", Owner: " << name
        << ") of amount: " << amount << " TL." << endl;
}

// Returns the name of the check owner
string Check::getName() const {
    return name;
}

// Sets the name of the check owner
void Check::setName(string name) {
    this->name = name;
}

// Returns the bank ID of the check
string Check::getBankID() const {
    return bankID;
}

// Sets the bank ID of the check
void Check::setBankID(string bankID) {
    this->bankID = bankID;
}
