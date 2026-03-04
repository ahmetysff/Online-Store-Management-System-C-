// Done on 2025-12-30 by Metin Talha Çite
// Done on 2025-12-29 by Ahmet Yusuf Dursun
// Done on 2025-12-31 by Anass Basri

#include <iostream>
#include <string>
#include <vector>
#include <limits> 
#include <iomanip> 

// Header files (project classes)
#include "Customer.h"
#include "Product.h"
#include "Book.h" 
#include "Magazine.h"
#include "MusicCD.h"
#include "ShoppingCart.h"
#include "Payment.h"
#include "CreditCard.h"
#include "Check.h"
#include "ProductToPurchase.h"
#include "Cash.h"

using namespace std;

// Stores all customers created & loaded in the system.
vector<Customer*> allCustomers;

// Stores all products available in the store.
vector<Product*> allProducts;

// Tracks the current logged-in customer, nullptr in case nobody logged in.
Customer* currentLoggedInCustomer = nullptr;

// Current active cart for the logged-in customer
ShoppingCart* currentCart = nullptr;


// Control of new customer's name, needs to be free of special characters
bool isValidName(const std::string& s) {
    if (s.empty())
        return false;

    for (char c : s) {
        if (!isalpha(static_cast<unsigned char>(c)) && c != ' ')
            return false;
    }
    return true;
}

// Safe integer input, keeps asking until user enters a valid number.
int getIntInput() {
    int value;
    while (true) {
        if (cin >> value) {
            return value;
        }
        else  {
            cout << "\n[ERROR] Invalid input! Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Reads a phone number as a string and validates it, it must be 11 digits.
string getPhoneInput() {
    string input;
    while (true) {
        if (cin.peek() == '\n') cin.ignore();
        getline(cin, input);

        bool isNumeric = true;
        if (input.empty()) isNumeric = false;

        for (char c : input) {
            if (c < '0' || c > '9') {
                isNumeric = false;
                break;
            }
        }

        if (!isNumeric) {
            cout << "[ERROR] Only numbers allowed! Please try again: ";
        }
        else if (input.length() != 11) {
            cout << "[ERROR] Phone number must be exactly 11 digits! Please try again: ";
        }
        else {
            return input;
        }
    }
}

// Reads a numeric string ,like credit card number, and validates it.
string getNumericStringInput() {
    string input;
    while (true) {
        if (cin.peek() == '\n') cin.ignore();
        getline(cin, input);

        bool isNumeric = true;
        if (input.empty()) isNumeric = false;

        for (char c : input) {
            if (c < '0' || c > '9') {
                isNumeric = false;
                break;
            }
        }

        if (isNumeric && !input.empty()) return input;
        else cout << "[ERROR] Only numbers allowed! Please try again: ";
    }
}

// Reads a line string and handles leftover newlines.
string getStringLine() {
    string text;
    if (cin.peek() == '\n') cin.ignore();
    getline(cin, text);
    return text;
}

// Checks if a username/email/phone is unique among all customers
bool isUnique(string type, string value) {
    for (auto c : allCustomers) {
        if (type == "username" && c->getUsername() == value) return false;
        if (type == "email" && c->getEmail() == value) return false;
        if (type == "phone" && c->getPhone() == value) return false;
    }
    return true;
}

// Initializes the system with predefined customers and products so that the program can run immediately.
void initializeSystem() {
    Customer* c1 = new Customer(1, "Metin Cite", "metin@mail.com", "metin", "metobaba123", 26511);
    c1->setAddress("Buyukdere Mah. No:18"); c1->setPhone("05433163345");
    allCustomers.push_back(c1);

    Customer* c2 = new Customer(2, "Anass Basri", "anass@mail.com", "anass", "ense321", 6020);
    c2->setAddress("Buyukdere Mah. No:10"); c2->setPhone("05376690519");
    allCustomers.push_back(c2);

    Customer* c3 = new Customer(3, "Yusuf Dursun", "yusuf@mail.com", "yusuf", "fusuy123", 33213);
    c3->setAddress("Baglar Mah. No:1"); c3->setPhone("05511204993");
    allCustomers.push_back(c3);

    Customer* c4 = new Customer(4, "Ahmet Yilmaz", "ahmet@mail.com", "ahmet", "basicahmet33", 34824);
    c4->setAddress("Ornekkoy Mah. 23 Nisan Cad."); c4->setPhone("05321234567");
    allCustomers.push_back(c4);

    Customer* c5 = new Customer(5, "Zeynep Kaya", "zeynep@mail.com", "zeynep", "urfalizeyno5", 4235);
    c5->setAddress("Elci Sok. No:11"); c5->setPhone("05059876543");
    allCustomers.push_back(c5);

    allProducts.push_back(new Book(1, "Crime and Punishment", 150.0, "Dostoyevsky", "Penguin", 671));
    allProducts.push_back(new Book(2, "Nutuk", 180.0, "Mustafa Kemal ATATURK", "TBMM Yayinevi", 543));
    allProducts.push_back(new Book(3, "1984", 120.0, "George Orwell", "Can Yayinlari", 328));

    allProducts.push_back(new Magazine(4, "Nat Geo July", 30.0, 7, "Science"));
    allProducts.push_back(new Magazine(5, "Vogue August", 45.0, 8, "Fashion"));
    allProducts.push_back(new Magazine(6, "Sabah Gazatesi", 35.0, 9, "News"));

    allProducts.push_back(new MusicCD(7, "Sigara", 80.0, "Muslum Gurses", "Arabesk"));
    allProducts.push_back(new MusicCD(8, "Back to Black", 75.0, "Amy Winehouse", "Soul"));
    allProducts.push_back(new MusicCD(9, "25", 90.0, "Ati242", "Rap"));
}

// Lists all products in a formatted table, using polymorphism to identify types.
void listAllProducts() {
    cout << "\n--- Product Catalog ---" << endl;
    cout << left << setw(5) << "ID" << setw(12) << "TYPE" << setw(30) << "NAME"
        << setw(25) << "DETAILS" << "PRICE" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

    for (auto prod : allProducts) {
        if (!prod) continue;

        string type = "Unknown";
        string details = "";

        if (Book* b = dynamic_cast<Book*>(prod)) {
            type = "Book";
			details = b->getAuthor(); // Author for books
        }
        else if (Magazine* m = dynamic_cast<Magazine*>(prod)) {
            type = "Magazine";
			details = m->getType(); // Type for magazines
        }
        else if (MusicCD* mcd = dynamic_cast<MusicCD*>(prod)) {
            type = "MusicCD";
			details = mcd->getSinger(); // Singer for music CDs
        }

        cout << left << setw(5) << prod->getID()
            << setw(12) << type
            << setw(30) << prod->getName()
			<< setw(25) << details // Details based on type
            << prod->getPrice() << " USD" << endl;
    }
}

// Customer management menu to add & list customers.    
void menuCustomer() {
    int choice;
    do {
        cout << "\nCustomer Menu" << endl;
        cout << "1. Add a new customer" << endl;
        cout << "2. Show customers" << endl;
        cout << "3. Back" << endl;
        cout << "Choose: ";
        choice = getIntInput();

        switch (choice) {
        case 1: {
            cout << "\nAdd Customer" << endl;
            cout << "ID: "; int id = getIntInput();
            cout << "Name: ";
            string name = getStringLine();
            while (!isValidName(name)) {
                cout << "Please enter the name properly: ";
                name = getStringLine();
            }

			// Control the uniqueness of username before creating a new customer
            string username;
            while (true) {
                cout << "Username: "; username = getStringLine();
                if (isUnique("username", username)) break;
                cout << "[ERROR] Username already taken! Please try another." << endl;
            }

            cout << "Password: "; string password = getStringLine();

			// Email uniqueness check 
            string email;
            while (true) {
                cout << "Email: "; email = getStringLine();
                if (isUnique("email", email)) break;
                cout << "[ERROR] Email already registered! Please try another." << endl;
            }

            cout << "Zip: "; int zip = getIntInput();
            cout << "Address: "; string address = getStringLine();

			// Phone number uniqueness check
            string phone;
            while (true) {
                cout << "Phone (11 digits): ";
                phone = getPhoneInput();
                if (isUnique("phone", phone)) break;
                cout << "[ERROR] Phone number already registered! Please try another." << endl;
            }

			// Create and store the new customer
            Customer* newC = new Customer(id, name, email, username, password, zip);
            newC->setAddress(address);
            newC->setPhone(phone);
            allCustomers.push_back(newC);
            cout << "Success!" << endl;
            break;
        }
		case 2: // Show customers
            cout << "\n--- Customer List ---" << endl;
            for (auto c : allCustomers)
                cout << c->getCustomerID() << ". " << c->getName() << " (" << c->getPhone() << ")" << endl;
            break;
        case 3: break;
        default: cout << "Invalid choice." << endl;
        }
    } while (choice != 3);
}

// Product management menu to list products in the store.
void menuItem() {
    int choice;
    do {
        cout << "\nItem Menu" << endl;
        cout << "1. List All Products" << endl;
        cout << "2. Back" << endl;
        cout << "Choose: ";
        choice = getIntInput();

        if (choice == 1) {
            listAllProducts();
        }
    } while (choice != 2);
}

// Shopping menu for login, cart operations management, and order placement processing.
void menuShopping() {
    int choice;
    do {
        string loginMsg = (currentLoggedInCustomer) ? currentLoggedInCustomer->getUsername() : "Guest";

		// Display shopping menu with current user info
        cout << "\nShopping Menu" << endl;
        cout << "   (User: " << loginMsg << ")" << endl;

        cout << "1. Login" << endl;
        cout << "2. Logout" << endl;
        cout << "3. Add Product" << endl;
        cout << "4. Remove Product" << endl;
        cout << "5. List All Products" << endl;
        cout << "6. List Cart" << endl;
        cout << "7. Show Bonus" << endl;
        cout << "8. Use Bonus" << endl;
        cout << "9. Place Order" << endl;
        cout << "10. Cancel Order" << endl;
        cout << "11. Invoice" << endl;
        cout << "12. Quit" << endl;
        cout << "Choose: ";
        choice = getIntInput();

		// Enforce login for certain operations
        if (!currentLoggedInCustomer && choice != 1 && choice != 2 && choice != 5 && choice != 12) {
            cout << "\nPlease login first (Option 1)." << endl;
            continue;
        }

        switch (choice) {
        case 1: { // Login
            if (currentLoggedInCustomer) {
                cout << "Already logged in. Please logout first." << endl;
                break;
            }
            int attempts = 5;
            bool success = false;
            while (attempts > 0) {
                cout << "Username: "; string uname = getStringLine();
                cout << "Password: "; string pass = getStringLine();

                for (auto c : allCustomers) {
                    if (c->getUsername() == uname && c->getPassword() == pass) {
                        currentLoggedInCustomer = c;
                        if (currentCart) delete currentCart;
                        currentCart = new ShoppingCart(currentLoggedInCustomer);
                        cout << "Welcome " << c->getName() << "!" << endl;
                        success = true;
                        break;
                    }
                }

                if (success) break;

                attempts--;
                if (attempts > 0) {
                    cout << "[ERROR] Wrong credentials! Remaining attempts: " << attempts << endl;
                }
                else {
                    cout << "[FATAL] No attempts left. Exiting application..." << endl;
                    exit(0);
                }
            }
            break;
        }
        case 2: // Logout
            if (!currentLoggedInCustomer) cout << "Not logged in." << endl;
            else {
                cout << "Logged out." << endl;
                currentLoggedInCustomer = nullptr;
                if (currentCart) { delete currentCart; currentCart = nullptr; }
            }
            break;
        case 3: { // Add Product
            listAllProducts();
            cout << endl;
            cout << "Enter Product ID: "; int pid = getIntInput();
            bool found = false;
            for (auto p : allProducts) {
                if (p->getID() == pid) {
                    currentCart->addProduct(p, 1);
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Product not found." << endl;
            break;
        }
        case 4: { // Remove
            currentCart->printProducts();
            cout << "Enter ID to remove: "; int pid = getIntInput();
            bool found = false;
            for (auto p : allProducts) {
                if (p->getID() == pid) {
                    currentCart->removeProduct(p);
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Invalid ID." << endl;
            break;
        }
        case 5: // List All Products
            listAllProducts();
            break;
        case 6: if (currentCart) currentCart->printProducts(); break;
        case 7: if (currentLoggedInCustomer) cout << "Bonus: " << currentLoggedInCustomer->getBonus() << " USD" << endl; break;
        case 8:
            if (currentLoggedInCustomer) {
                if (currentLoggedInCustomer->getBonus() == 0) {
                    cout << "You don't have bonus points!" << endl;
                }
                else {
                currentLoggedInCustomer->useBonus();
                currentCart->setBonusUsed(true);
                cout << "Bonus applied (All points used)." << endl;
                }
            } break;
        case 9: { // Place Order
            if (!currentCart || currentCart->isEmpty()) {
                cout << "Please add some products first.\n";
                break;
            }
            bool paymentDone = false;
            while (!paymentDone) {
                cout << "Payment: 1:CreditCard  2:Check: ";
                int type = getIntInput();

                if (type == 1) {
                    cout << "Card No (Numbers only): ";
                    string cnStr = getNumericStringInput();

                    // Cart length check
                    if (cnStr.length() < 1 || cnStr.length() > 16) {
                        cout << "[ERROR] Card number must be 1 to 16 digits!" << endl;
                        break;
                    }

                    long cnLong = 0;
                    try {
                        cnLong = stol(cnStr);
                    }
                    catch (...) {
                        cout << "[ERROR] Card number is too large or invalid!" << endl;
                        break;
                    }

                    string ct;
                    while (true) {
                        cout << "Type: (Mastercard/Visa) ";
                        cin >> ct;

                        if (isValidName(ct)) {
                            break;
                        }
                        else {
                            cout << "Enter Letters Only!" << endl;
                        }
                    }
                    string exp;
                    while (true) {
                        cout << "Expiry (MMYY numbers only): ";
                        exp = getNumericStringInput();

                        if (exp.length() == 4) {
                            break;
                        }
                        else {
                            cout << "Enter 4 digits only (MMYY)!" << endl;
                        }
                    }

                    CreditCard* cc = new CreditCard(cnLong, ct, exp);
                    currentCart->setPaymentMethod(cc);
                    currentCart->placeOrder();
                    paymentDone = true;
                }
                else if (type == 2) {
                    string n1;
                    while (true) {
                        cout << "Name: ";
                        cin >> n1;
                        if (isValidName(n1)) break;
                        cout << "Enter your name with letters only!" << endl;
                    }
                    cout << "Bank ID (Numbers only): "; string bid = getNumericStringInput();
                    Check* chk = new Check(n1, bid);
                    currentCart->setPaymentMethod(chk);
                    currentCart->placeOrder();
                    paymentDone = true;
                }
                else {
                    cout << "Enter either card or check!" << endl;
                    break;
                }
                currentLoggedInCustomer->sendBill();
                break;
            }
            break;
        }
		case 10: if (currentCart) currentCart->cancelOrder(); break; // Cancel Order
        case 11: if (currentLoggedInCustomer) currentLoggedInCustomer->sendBill(); break;
		case 12: cout << "To Main Menu..." << endl; break; // Quit towards main menu
		default: cout << "Invalid choice." << endl; // Invalid choice
        }
    } while (choice != 12);
}

// ==========================================
// MAIN
// ==========================================
int main() {

	// Initialize system with predefined data in the beginning of the code
    initializeSystem();
    int choice;
    do {
		// Main menu display
        cout << "===========================================" << endl;
        cout << "       ONLINE STORE MANAGEMENT SYSTEM       " << endl;
        cout << "          Welcome | Version 1.0            " << endl;
        cout << "===========================================" << endl;
        cout << "\n================ MAIN MENU ================" << endl;
        cout << "1. Customer" << endl;
        cout << "2. Item" << endl;
        cout << "3. Shopping" << endl;
        cout << "4. Quit" << endl;
        cout << "Choose: ";
        choice = getIntInput();

        switch (choice) {
		case 1: menuCustomer(); break; // Customer Menu
		case 2: menuItem(); break; // Item Menu
		case 3: menuShopping(); break; // Shopping Menu
		case 4: cout << "Exiting..." << endl; break; // Exit
		default: cout << "Invalid choice." << endl; // Invalid choice by the customer
        }
    } while (choice != 4);

	if (currentCart) delete currentCart; // Clean up current cart for logged-in user to avoid memory leaks
	for (auto c : allCustomers) delete c; // Clean up all customers created in the system
	for (auto p : allProducts) delete p; // Clean up all products created in the system
    return 0;
}
