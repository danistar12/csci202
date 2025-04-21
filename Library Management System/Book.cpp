#include "Book.h"

Book::Book(int id, const std::string& title, const std::string& author)
    : id(id), title(title), author(author), isbn("") {}

Book::Book(const std::string& title, const std::string& author, const std::string& isbn)
    : id(0), title(title), author(author), isbn(isbn) {}

int Book::getId() const { return id; }
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
std::string Book::getIsbn() const { return isbn; }

bool Book::operator==(const Book& other) const {
    return isbn == other.isbn;
}

bool Book::operator!=(const Book& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.isbn;
    return os;
}