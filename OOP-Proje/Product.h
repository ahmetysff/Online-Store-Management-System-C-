//Done on 2025-11-27 by Anass Basri

// The Product class represents an abstract base product in the online store.
// It defines common attributes and behaviors for all product types.
#pragma once
#include <iostream>
#include <string>
using namespace std;

// Abstract base class
class Product {
protected:
    // Protected to allow access from derived product classes
    int id;        // Unique ID of the product
    string name;   // Name of the product
    double price;  // Price of the product

public:
    Product(int id, string name, double price);
    // Parameterized constructor to initialize product attributes

    virtual ~Product() {}
    // Virtual destructor for polymorphism and proper cleanup of derived classes

    // Getter and Setter methods
    int getID();
    // Getter for id, returns the product ID
    void setID(int id);
    // Setter for id, sets the product ID

    string getName() const;
    // Getter for name, returns the product name
    void setName(string name);
    // Setter for name, sets the product name

    double getPrice() const;
    // Getter for price, returns the product price
    void setPrice(double price);
    // Setter for price, sets the product price

    virtual void printProperties() = 0;
    // Pure virtual function to print product properties
    // Makes this class abstract and forces derived classes to implement it
};

