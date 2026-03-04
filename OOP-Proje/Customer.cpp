//Done on 2025-12-10 by Ahmet Yusuf Dursun

#include "Customer.h"

// Constructor: initializes customer information and sets default values
Customer::Customer(long id, string name, string email, string username, string password, int zipCode) {
    this->customerID = id;
    this->name = name;
    this->email = email;
    this->username = username;
    this->password = password;
    this->zipCode = zipCode;

    // Initializes default values
    this->bonus = 0.0;
    this->address = "";
    this->phone = "";
}

// Sends an invoice notification to the customer
void Customer::sendBill() {
    cout << "\n----------------------------------------" << endl;
    cout << "   EMAIL NOTIFICATION: INVOICE READY    " << endl;
    cout << "----------------------------------------" << endl;
    cout << "To       : " << email << endl;
    cout << "Customer : " << name << endl;
    cout << "Message  : Dear " << name << ", the invoice for your recent purchase" << endl;
    cout << "          has been sent to your registered address." << endl;
    cout << "Address  : " << address << endl;
    cout << "----------------------------------------" << endl;
}

// Returns the customer ID
long Customer::getCustomerID() const {
    return this->customerID;
}

// Sets the customer ID
void Customer::setCustomerID(long customerID) {
    this->customerID = customerID;
}

// Returns the zip code
int Customer::getZipCode() const {
    return this->zipCode;
}

// Sets the zip code
void Customer::setZipCode(int zipCode) {
    this->zipCode = zipCode;
}

// Returns the customer name
string Customer::getName() const {
    return this->name;
}

// Sets the customer name
void Customer::setName(string name) {
    this->name = name;
}

// Returns the customer address
string Customer::getAddress() const {
    return this->address;
}

// Sets the customer address
void Customer::setAddress(string address) {
    this->address = address;
}

// Returns the customer phone number
string Customer::getPhone() const {
    return this->phone;
}

// Sets the customer phone number
void Customer::setPhone(string phone) {
    this->phone = phone;
}

// Returns the bonus amount
double Customer::getBonus() const {
    return this->bonus;
}

// Sets the bonus amount
void Customer::setBonus(double bonus) {
    this->bonus = bonus;
}

// Returns the customer email
string Customer::getEmail() const {
    return this->email;
}

// Sets the customer email
void Customer::setEmail(string email) {
    this->email = email;
}

// Returns the username
string Customer::getUsername() const {
    return this->username;
}

// Sets the username
void Customer::setUsername(string username) {
    this->username = username;
}

// Returns the password
string Customer::getPassword() const {
    return this->password;
}

// Sets the password
void Customer::setPassword(string password) {
    this->password = password;
}

// Checks whether the given username and password match the customer's account
bool Customer::checkAccount(string inputUsername, string inputPassword) {
    if (this->username == inputUsername && this->password == inputPassword) {
        return true;
    }
    return false;
}

// Adds bonus amount to the customer's existing bonus
void Customer::addBonus(double amount) {
    this->bonus += amount;
}

// Uses all bonus points by resetting the bonus amount
void Customer::useBonus() {
    this->bonus = 0.0;
    cout << "All bonus points used." << endl;
}
