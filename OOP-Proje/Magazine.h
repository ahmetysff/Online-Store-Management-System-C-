//Done on 2025-11-27 by Anass Basri

// The Magazine class represents a magazine product in the online store.
// It inherits from the Product class and includes magazine-specific attributes.
#pragma once
#include "Product.h" // Including the base Product class to inherit from it

class Magazine : public Product {
private:
    int issue;    // Issue number of the magazine
    string type;  // Type of the magazine

public:
    Magazine(int id, string name, double price, int issue, string type);
    // Parameterized constructor to initialize all magazine attributes

    int getIssue() const;
    // Getter for issue, returns the magazine issue number
    void setIssue(int issue);
    // Setter for issue, sets the magazine issue number

    string getType() const;
    // Getter for type, returns the magazine type
    void setType(string type);
    // Setter for type, sets the magazine type

    void printProperties() override;
    // Prints all properties of the Magazine
    // The override keyword indicates that this method overrides a virtual method in the base Product class
};
