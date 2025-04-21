#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

class Book {
public:
    Book(int id, const std::string& title, const std::string& author);
    Book(const std::string& title, const std::string& author, const std::string& isbn);

    int getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getIsbn() const;

    bool operator==(const Book& other) const;
    bool operator!=(const Book& other) const;

    // Friend function for operator<<
    friend std::ostream& operator<<(std::ostream& os, const Book& book);

private:
    int id;
    std::string title;
    std::string author;
    std::string isbn;
};

#endif // BOOK_H