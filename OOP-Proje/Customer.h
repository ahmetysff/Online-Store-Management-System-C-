// Done on 2025-12-10 by Ahmet Yusuf Dursun

// The Customer class represents a customer in the online store.
// It stores personal information, account credentials, and bonus-related data.
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>    // For using string type
#include <iostream> // For input/output operations if needed

using namespace std;

class Customer {
private:
    long customerID; // Unique ID of the customer
    string name;     // Name of the customer
    string address;  // Address of the customer
    string phone;    // Phone number of the customer
    double bonus;    // Bonus amount earned by the customer
    string email;    // Email address of the customer
    string username; // Username used for login
    string password; // Password used for login
    int zipCode;     // Zip code of the customer's address

public:
    // Constructor (required to be compatible with Main.cpp)
    Customer(long id, string name, string email, string username, string password, int zipCode);
    // Parameterized constructor to initialize customer information

    // Methods defined in the UML diagram
    void sendBill();
    // Sends the bill or invoice to the customer

    long getCustomerID() const;
    // Getter for customerID, returns the customer's ID
    void setCustomerID(long customerID);
    // Setter for customerID, sets the customer's ID

    int getZipCode() const;
    // Getter for zipCode, returns the zip code
    void setZipCode(int zipCode);
    // Setter for zipCode, sets the zip code

    string getName() const;
    // Getter for name, returns the customer's name
    void setName(string name);
    // Setter for name, sets the customer's name

    string getAddress() const;
    // Getter for address, returns the customer's address
    void setAddress(string address);
    // Setter for address, sets the customer's address

    string getPhone() const;
    // Getter for phone, returns the customer's phone number
    void setPhone(string phone);
    // Setter for phone, sets the customer's phone number

    double getBonus() const;
    // Getter for bonus, returns the customer's bonus amount
    void setBonus(double bonus);
    // Setter for bonus, sets the customer's bonus amount

    string getEmail() const;
    // Getter for email, returns the customer's email address
    void setEmail(string email);
    // Setter for email, sets the customer's email address

    string getUsername() const;
    // Getter for username, returns the customer's username
    void setUsername(string username);
    // Setter for username, sets the customer's username

    string getPassword() const;
    // Getter for password, returns the customer's password
    void setPassword(string password);
    // Setter for password, sets the customer's password

    bool checkAccount(string username, string password);
    // Checks if the given username and password match the customer's account

    void addBonus(double bonus);
    // Adds bonus amount to the customer's existing bonus

    void useBonus();
    // Uses the customer's bonus during payment
};

#endif
