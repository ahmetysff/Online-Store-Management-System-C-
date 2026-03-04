// Done on 2025-12-06 by Metin Talha Çite

// The Check class represents a check payment method in the online store.
// It inherits from the Payment class and stores check-specific information.
#pragma once
#include "Payment.h" // Including the base Payment class to inherit from it
#include <string>    // Including string library for name and bankID

class Check : public Payment {
private:
    string name;    // Name of the check owner
    string bankID;  // Bank ID associated with the check

public:
    Check(string name, string bankID);
    // Constructor to initialize the check owner name and bank ID

    void performPayment() override;
    // Performs the check payment
    // The override keyword indicates that this method overrides a virtual method in the Payment base class

    // Getter and Setter methods
    string getName() const;
    // Getter for name, returns the check owner's name
    void setName(string name);
    // Setter for name, sets the check owner's name

    string getBankID() const;
    // Getter for bankID, returns the bank ID
    void setBankID(string bankID);
    // Setter for bankID, sets the bank ID
};
