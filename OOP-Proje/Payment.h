// Done on 2025-12-06 by Metin Talha Çite

// The Payment class represents an abstract base class for all payment methods.
// It defines common payment behavior and enforces implementation in derived classes.
#pragma once
#include <iostream> // For input/output operations if needed in payment methods
using namespace std;

class Payment {
protected:
    double amount;
    // Amount of money to be paid
    // Protected to allow access from derived payment classes

public:
    Payment(double amount = 0.0);
    // Constructor to initialize the payment amount (default is 0.0)

    virtual ~Payment();
    // Virtual destructor to ensure proper cleanup of derived payment objects

    double getAmount() const;
    // Getter for amount, returns the payment amount
    void setAmount(double amount);
    // Setter for amount, sets the payment amount

    virtual void performPayment() = 0;
    // Pure virtual function to perform the payment
    // Makes this class abstract and must be implemented by derived classes
};
