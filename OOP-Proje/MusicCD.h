//Done on 2025-11-27 by Anass Basri

// The MusicCD class represents a music CD product in the online store.
// It inherits from the Product class and includes music-specific attributes.
#pragma once
#include "Product.h" // Including the base Product class to inherit from it

class MusicCD : public Product {
private:
    string singer; // Name of the singer
    string type;   // Genre of the music CD

public:
    MusicCD(int id, string name, double price, string singer, string type);
    // Parameterized constructor to initialize all music CD attributes

    string getSinger() const;
    // Getter for singer, returns the singer's name
    void setSinger(string singer);
    // Setter for singer, sets the singer's name

    string getType() const;
    // Getter for type, returns the music type
    void setType(string type);
    // Setter for type, sets the music type

    void printProperties() override;
    // Prints all properties of the MusicCD
    // The override keyword indicates that this method overrides a virtual method in the base Product class
};
