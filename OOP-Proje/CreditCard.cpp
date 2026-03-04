// Done on 2025-12-06 by Metin Talha Çite

#include "CreditCard.h"

// Constructor: initializes credit card details and payment amount
CreditCard::CreditCard(long number, string type, string expDate, double amount)
    : Payment(amount), number(number), type(type), expDate(expDate) {
}

// Performs the credit card payment
void CreditCard::performPayment() {
    cout << "Performing credit card payment (" << type << " - " << number
        << ") of amount: " << amount << " TL." << endl;
}

// Returns the credit card number
long CreditCard::getNumber() const {
    return number;
}

// Sets the credit card number
void CreditCard::setNumber(long number) {
    this->number = number;
}

// Returns the credit card type
string CreditCard::getType() const {
    return type;
}

// Sets the credit card type
void CreditCard::setType(string type) {
    this->type = type;
}

// Returns the expiration date of the credit card
string CreditCard::getExpDate() const {
    return expDate;
}

// Sets the expiration date of the credit card
void CreditCard::setExpDate(string expDate) {
    this->expDate = expDate;
}
