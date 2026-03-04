// Done on 2025-12-06 by Metin Talha Çite

// The Cash class represents a cash payment method in the online store.
// It inherits from the Payment class and handles cash-based payments.
#pragma once
#include "Payment.h" // Including the base Payment class to inherit from it

class Cash : public Payment {
public:
    Cash(double amount = 0.0);
    // Constructor to initialize the payment amount (default is 0.0)

    void performPayment() override;
    // Performs the cash payment
    // The override keyword indicates that this method overrides a virtual method in the Payment base class
};
