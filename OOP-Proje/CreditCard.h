// Done on 2025-12-06 by Metin Talha Çite

// The CreditCard class represents a credit card payment method in the online store.
// It inherits from the Payment class and stores credit card-specific information.
#pragma once
#include "Payment.h" // Including the base Payment class to inherit from it
#include <string>    // Including string library for type and expiration date

class CreditCard : public Payment {
private:
    long number;     // Credit card number
    string type;     // Type of the credit card (e.g., Visa, MasterCard)
    string expDate;  // Expiration date of the credit card

public:
    CreditCard(long number, string type, string expDate, double amount = 0.0);
    // Parameterized constructor to initialize credit card information and payment amount

    void performPayment() override;
    // Performs the credit card payment
    // The override keyword indicates that this method overrides a virtual method in the Payment base class

    // Getter and Setter methods
    long getNumber() const;
    // Getter for number, returns the credit card number
    void setNumber(long number);
    // Setter for number, sets the credit card number

    string getType() const;
    // Getter for type, returns the credit card type
    void setType(string type);
    // Setter for type, sets the credit card type

    string getExpDate() const;
    // Getter for expDate, returns the expiration date
    void setExpDate(string expDate);
    // Setter for expDate, sets the expiration date
};
