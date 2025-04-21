#include "Patron.h"

Patron::Patron(const std::string& name, const std::string& libraryCardNumber)
    : name(name), libraryCardNumber(libraryCardNumber) {}

std::string Patron::getName() const {
    return name;
}

std::string Patron::getLibraryCardNumber() const {
    return libraryCardNumber;
}

// Define operator< for Patron
bool Patron::operator<(const Patron& other) const {
    return libraryCardNumber < other.libraryCardNumber;
}

// Define operator> for Patron
bool Patron::operator>(const Patron& other) const {
    return libraryCardNumber > other.libraryCardNumber;
}

// Define operator<< for Patron
std::ostream& operator<<(std::ostream& os, const Patron& patron) {
    os << "Name: " << patron.name << ", Library Card Number: " << patron.libraryCardNumber;
    return os;
}