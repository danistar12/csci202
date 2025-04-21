#ifndef PATRON_H
#define PATRON_H

#include <string>
#include <iostream>

class Patron {
public:
    Patron(const std::string& name, const std::string& libraryCardNumber);

    std::string getName() const;
    std::string getLibraryCardNumber() const;

    // Comparison operators for BinaryTree
    bool operator<(const Patron& other) const;
    bool operator>(const Patron& other) const;

    // Friend function for operator<<
    friend std::ostream& operator<<(std::ostream& os, const Patron& patron);

private:
    std::string name;
    std::string libraryCardNumber;
};

#endif // PATRON_H