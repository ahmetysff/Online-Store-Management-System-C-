//Done on 2025-12-06 by Metin Talha Çite

// The ProductToPurchase class represents a product and its quantity in the shopping cart.
// It holds a pointer to a Product to support polymorphism (Book, Magazine, or MusicCD).
#pragma once
#include "Product.h" // Including the Product base class to store a product pointer

class ProductToPurchase {
private:
    Product* product; // Pointer to Product to allow polymorphism (Book, Magazine, or MusicCD)
    int quantity;     // Quantity of the product to be purchased

public:
    // Constructors
    ProductToPurchase();
    // Default constructor

    ProductToPurchase(Product* product, int quantity);
    // Parameterized constructor to initialize the product pointer and quantity

    // Getter and Setter methods
    // Since Product is an abstract class, a pointer (*) is returned
    Product* getProduct();
    // Getter for product, returns the Product pointer
    void setProduct(Product* product);
    // Setter for product, sets the Product pointer

    int getQuantity();
    // Getter for quantity, returns the quantity
    void setQuantity(int quantity);
    // Setter for quantity, sets the quantity
};

