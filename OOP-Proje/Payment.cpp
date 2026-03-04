// Done on 2025-12-06 by Metin Talha Çite

#include "Payment.h"

// Constructor: initializes the payment amount
Payment::Payment(double amount) : amount(amount) {}

// Destructor
Payment::~Payment() {}

// Returns the payment amount
double Payment::getAmount() const {
    return amount;
}

// Sets the payment amount
void Payment::setAmount(double amount) {
    this->amount = amount;
}
