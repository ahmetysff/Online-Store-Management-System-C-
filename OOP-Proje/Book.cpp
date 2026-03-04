// Done on 2025-11-27 by Anass Basri

#include "Book.h"

// Constructor: initializes book attributes and base Product attributes
Book::Book(int id, string name, double price, string author, string publisher, int page)
    : Product(id, name, price) {
    this->author = author;
    this->publisher = publisher;
    this->page = page;
}

// Returns the author of the book
string Book::getAuthor() const {
    return author;
}

// Sets the author of the book
void Book::setAuthor(string author) {
    this->author = author;
}

// Returns the publisher of the book
string Book::getPublisher() const {
    return publisher;
}

// Sets the publisher of the book
void Book::setPublisher(string publisher) {
    this->publisher = publisher;
}

// Returns the page number of the book
int Book::getPage() const {
    return page;
}

// Sets the page number of the book
void Book::setPage(int page) {
    this->page = page;
}

// Prints all book properties
void Book::printProperties() {
    cout << "--- Book Properties ---" << endl;
    cout << "ID: " << id << " | Name: " << name << " | Price: " << price << " TL" << endl;
    cout << "Author: " << author << endl;
    cout << "Publisher: " << publisher << endl;
    cout << "Pages: " << page << endl;
    cout << "-----------------------" << endl;
}
