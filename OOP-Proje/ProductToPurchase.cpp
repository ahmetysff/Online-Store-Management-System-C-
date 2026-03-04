// Done on 2025-11-27 by Anass Basri

#include "ProductToPurchase.h"

// Default constructor: initializes product pointer to nullptr and quantity to zero
ProductToPurchase::ProductToPurchase() : product(nullptr), quantity(0) {}

// Constructor: initializes product pointer and quantity
ProductToPurchase::ProductToPurchase(Product* product, int quantity) :
	product(product), quantity(quantity) {
}

// Returns the product pointer
Product* ProductToPurchase::getProduct() {
	return product;
}

// Sets the product pointer
void ProductToPurchase::setProduct(Product* product) {
	this->product = product;
}

// Returns the quantity
int ProductToPurchase::getQuantity() {
	return quantity;
}

// Sets the quantity
void ProductToPurchase::setQuantity(int quantity) {
	this->quantity = quantity;
}
