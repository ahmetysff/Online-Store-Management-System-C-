//Done on 2025-11-27 by Anass Basri

// The Book class represents a book product in the online store.
// It inherits from the Product class and contains book-specific information.
#pragma once
#include "Product.h" // Including the base Product class to inherit from it

class Book : public Product {
private:
    string author;    // Name of the book's author
    string publisher; // Name of the book's publisher
    int page;         // Page number of the book

public:
    Book(int id, string name, double price, string author, string publisher, int page);
    // Parameterized constructor to initialize all book attributes

    // Getter and Setter methods
    string getAuthor() const;
    // Getter for author, returns the author's name
    void setAuthor(string author);
    // Setter for author, sets the author's name

    string getPublisher() const;
    // Getter for publisher, returns the publisher's name
    void setPublisher(string publisher);
    // Setter for publisher, sets the publisher's name

    int getPage() const;
    // Getter for page, returns the page number
    void setPage(int page);
    // Setter for page, sets the page number

    void printProperties() override;
    // Prints all properties of the Book
    // The override keyword indicates that this method overrides a virtual method in the base Product class
};
