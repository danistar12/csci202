#include "Library.h"
#include <fstream>
#include <iostream>
#include <sstream>

Library::Library() {
    // Load books from file when the library is initialized
    loadBooksFromFile("books.txt");
}

Library::~Library() {
    // Save books to file when the library is destroyed
    saveBooksToFile("books.txt");
}

void Library::addBook(const Book& book) {
    bookList.addNode(book);
}

void Library::removeBook(const std::string& isbn) {
    bookList.removeNode(Book("", "", isbn)); // Match by ISBN
}

void Library::addPatron(const Patron& patron) {
    patronTree.insert(patron);
}

void Library::removePatron(const std::string& libraryCardNumber) {
    patronTree.remove(Patron("", libraryCardNumber));
}

void Library::displayBooks() const {
    bookList.traverse();
}

void Library::displayPatrons() const {
    // Implement traversal for BinaryTree
    // patronTree.traverse(); // Uncomment if traverse is implemented
}

void Library::loadBooksFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << "\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int id;
        std::string title, author, isbn;

        std::getline(iss, title, ',');
        std::getline(iss, author, ',');
        std::getline(iss, isbn, ',');

        if (!title.empty() && !author.empty() && !isbn.empty()) {
            addBook(Book(id, title, author, isbn));
        }
    }

    file.close();
    std::cout << "Books loaded successfully from " << filename << "\n";
}

void Library::saveBooksToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << "\n";
        return;
    }

    bookList.forEach([&file](const Book& book) {
        file << book.getId() << "," << book.getTitle() << "," << book.getAuthor() << "," << book.getIsbn() << "\n";
    });

    file.close();
    std::cout << "Books saved successfully to " << filename << "\n";
}