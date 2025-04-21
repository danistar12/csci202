#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Patron.h"
#include "data_structures/LinkedList.h"
#include "data_structures/BinaryTree.h"
#include <string>

class Library {
private:
    LinkedList<Book> bookList; // Linked list to store books
    BinaryTree<Patron> patronTree; // Binary tree to store patrons

public:
    Library();
    ~Library();

    void addBook(const Book& book);
    void removeBook(const std::string& isbn);
    void addPatron(const Patron& patron);
    void removePatron(const std::string& libraryCardNumber);

    void displayBooks() const; // Added
    void displayPatrons() const; // Added

    void loadBooksFromFile(const std::string& filename);
};

#endif // LIBRARY_H