// Done on 2025-12-06 by Metin Talha Çite

#include "Cash.h"

// Constructor: initializes the cash payment with the given amount
Cash::Cash(double amount) : Payment(amount) {}

// Performs the cash payment
void Cash::performPayment() {
    cout << "Performing cash payment of amount: " << amount << " TL." << endl;
}
