// Done on 2025-11-27 by Anass Basri

#include "MusicCD.h"

// Constructor: initializes music CD attributes and base Product attributes
MusicCD::MusicCD(int id, string name, double price, string singer, string type)
    : Product(id, name, price), singer(singer), type(type) {
}

// Returns the singer name
string MusicCD::getSinger() const {
    return singer;
}

// Sets the singer name
void MusicCD::setSinger(string singer) {
    this->singer = singer;
}

// Returns the music type/genre
string MusicCD::getType() const {
    return type;
}

// Sets the music type/genre
void MusicCD::setType(string type) {
    this->type = type;
}

// Prints all music CD properties
void MusicCD::printProperties() {
    cout << "MusicCD: " << name
        << " by " << singer
        << " (Genre: " << type
        << ") Price: " << price << " TL" << endl;
}
