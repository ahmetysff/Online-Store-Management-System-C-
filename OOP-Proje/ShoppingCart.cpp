// Done on 2025-11-27 by Metin Talha Çite

#include "ShoppingCart.h"
#include "Product.h"

// Constructor: initializes shopping cart with a customer and default values
ShoppingCart::ShoppingCart(Customer* customer)
    : customer(customer), paymentMethod(nullptr), isBonusUsed(false) {
}

// Destructor: clears all dynamically allocated products in the cart
ShoppingCart::~ShoppingCart() {
    for (auto item : productsToPurchase) {
        delete item;
    }
    productsToPurchase.clear();
}

// Sets the payment method for the shopping cart
void ShoppingCart::setPaymentMethod(Payment* paymentMethod) {
    this->paymentMethod = paymentMethod;
}

// Returns the current payment method
Payment* ShoppingCart::getPaymentMethod() const {
    return paymentMethod;
}

// Sets whether bonus will be used during payment
void ShoppingCart::setBonusUsed(bool used) {
    this->isBonusUsed = used;
}

// Returns whether bonus is used
bool ShoppingCart::getBonusUsed() const {
    return isBonusUsed;
}

// Returns the customer associated with the cart
Customer* ShoppingCart::getCustomer() const {
    return customer;
}

// Sets the customer associated with the cart
void ShoppingCart::setCustomer(Customer* customer) {
    this->customer = customer;
}

// Adds a product to the cart or increases quantity if it already exists
void ShoppingCart::addProduct(Product* product, int quantity) {
    if (product == nullptr || quantity <= 0) return;

    bool found = false;
    for (auto item : productsToPurchase) {
        if (item->getProduct()->getID() == product->getID()) {
            item->setQuantity(item->getQuantity() + quantity);
            cout << "Product quantity updated: " << product->getName()
                << " (Total: " << item->getQuantity() << ")" << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        ProductToPurchase* newItem = new ProductToPurchase(product, quantity);
        productsToPurchase.push_back(newItem);
        cout << "Product added to cart: " << product->getName() << endl;
    }
}

// Removes a product from the shopping cart
void ShoppingCart::removeProduct(Product* product) {
    bool found = false;
    for (auto it = productsToPurchase.begin(); it != productsToPurchase.end(); ) {
        if ((*it)->getProduct()->getID() == product->getID()) {
            delete* it;
            it = productsToPurchase.erase(it);
            found = true;
            cout << "Product removed from cart." << endl;
        }
        else {
            ++it;
        }
    }
    if (!found) cout << "Product not found in cart." << endl;
}

// Prints all products currently in the shopping cart
void ShoppingCart::printProducts() {
    cout << "--- Cart Contents ---" << endl;
    if (productsToPurchase.empty()) {
        cout << "Empty." << endl;
        return;
    }
    for (auto item : productsToPurchase) {
        cout << "Product: " << item->getProduct()->getName()
            << " | Qty: " << item->getQuantity()
            << " | Price: " << item->getProduct()->getPrice() << " USD" << endl;
    }
}

// Displays the invoice with total and bonus information
void ShoppingCart::showInvoice() {
    if (productsToPurchase.empty()) {
        cout << "Cart is empty." << endl;
        return;
    }

    double total = 0;
    cout << "\n=== INVOICE ===" << endl;
    cout << "Customer: " << customer->getName() << endl;

    for (auto item : productsToPurchase) {
        double lineTotal = item->getProduct()->getPrice() * item->getQuantity();
        total += lineTotal;
        cout << item->getProduct()->getName() << " (" << item->getQuantity()
            << ") : " << lineTotal << " USD" << endl;
    }

    cout << "Subtotal: " << total << " USD" << endl;

    if (isBonusUsed && customer->getBonus() > 0) {
        double bonus = customer->getBonus();
        double discount = (bonus > total) ? total : bonus;
        cout << "Bonus Discount: -" << discount << " USD" << endl;
        cout << "Total to Pay: " << (total - discount) << " USD" << endl;
    }
    else {
        cout << "Total to Pay: " << total << " USD" << endl;
    }
    cout << "=================" << endl;
}

// Finalizes the order, processes payment, and clears the cart
void ShoppingCart::placeOrder() {
    if (productsToPurchase.empty()) {
        cout << "Cart is empty." << endl;
        return;
    }
    cout << "\n\n" << "==================INVOICE==================" << endl;
    double totalAmount = 0;
    for (auto item : productsToPurchase) {
        double itemTotal = item->getProduct()->getPrice() * item->getQuantity();
        cout << item->getProduct()->getName() << " x"
            << item->getQuantity() << " = "
            << itemTotal << " USD" << endl;

        totalAmount += itemTotal;
    }
    cout << "-------------------------------------------" << endl;

    double earnedBonus = totalAmount * 0.01;
    customer->setBonus(customer->getBonus() + earnedBonus);

    if (isBonusUsed) {
        customer->setBonus(0.0);
    }

    cout << "Total Amount: " << totalAmount << " USD" << endl;
    cout << "Bonus Earned: " << earnedBonus << " USD" << endl;

    productsToPurchase.clear();
}

void ShoppingCart::cancelOrder() {
    for (auto item : productsToPurchase) {
        delete item;
    }
    productsToPurchase.clear();
    cout << "Order cancelled." << endl;
}

// Checks whether the shopping cart is empty or not
bool ShoppingCart::isEmpty() const {
    return productsToPurchase.empty();
}