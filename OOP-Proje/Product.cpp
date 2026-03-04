// Done on 2025-11-27 by Anass Basri

#include "Product.h"

// Constructor: initializes product attributes
Product::Product(int id, string name, double price) :
	id(id), name(name), price(price) {
}

// Returns the product ID
int Product::getID() {
	return id;
}

// Sets the product ID
void Product::setID(int id) {
	this->id = id;
}

// Returns the product name
string Product::getName() const {
	return name;
}

// Sets the product name
void Product::setName(string name) {
	this->name = name;
}

// Returns the product price
double Product::getPrice() const {
	return price;
}

// Sets the product price
void Product::setPrice(double price) {
	this->price = price;
}
