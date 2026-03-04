// Done on 2025-12-06 by Metin Talha Çite

// The ShoppingCart class manages the products selected by a customer for purchase.
// It handles adding/removing products, payment processing, and order operations.
#pragma once
#include <vector>              // For using vector to store products
#include <iostream>            // For input/output operations if needed
#include "ProductToPurchase.h" // For storing products with their quantities
#include "Payment.h"           // For handling different payment methods
#include "Customer.h"          // For associating the cart with a customer

using namespace std;

class ShoppingCart {
private:
    vector<ProductToPurchase*> productsToPurchase;
    // List of products to purchase, stored as pointers to support polymorphism

    Payment* paymentMethod;
    // Pointer to the selected payment method

    Customer* customer;
    // Pointer to the customer who owns this shopping cart

    bool isBonusUsed;
    // Indicates whether the customer's bonus will be used in payment

public:
    ShoppingCart(Customer* customer);
    // Constructor to initialize the shopping cart with a customer

    ~ShoppingCart();
    // Destructor to clean up dynamically allocated resources if needed

    void setPaymentMethod(Payment* paymentMethod);
    // Setter for paymentMethod, sets the payment method for the cart
    Payment* getPaymentMethod() const;
    // Getter for paymentMethod, returns the current payment method

    void setBonusUsed(bool used);
    // Setter for isBonusUsed, specifies whether bonus will be used
    bool getBonusUsed() const;
    // Getter for isBonusUsed, returns bonus usage status

    Customer* getCustomer() const;
    // Getter for customer, returns the associated customer
    void setCustomer(Customer* customer);
    // Setter for customer, sets the associated customer

    void addProduct(Product* product, int quantity);
    // Adds a product and its quantity to the shopping cart

    void removeProduct(Product* product);
    // Removes a product from the shopping cart

    void printProducts();
    // Prints all products currently in the shopping cart

    void showInvoice();
    // Displays the invoice for the current order

    void placeOrder();
    // Places the order and performs the payment process

    void cancelOrder();
    // Cancels the current order and clears the shopping cart

    bool isEmpty() const;
    // Checks whether the shopping cart is empty
};
