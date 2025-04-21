#include <iostream>
#include "Library.h"

void displayMenu() {
    std::cout << "\nLibrary Management System\n";
    std::cout << "1. Load Books from File\n";
    std::cout << "2. Add a Book\n";
    std::cout << "3. Add a Patron\n";
    std::cout << "4. Display All Books\n";
    std::cout << "5. Display All Patrons\n";
    std::cout << "6. Exit\n";
}

int main() {
    Library library;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string filename;
            std::cout << "Enter the filename to load books from: ";
            std::cin >> filename;
            library.loadBooksFromFile(filename);
            break;
        }
        case 2: {
            std::string title, author, isbn;
            std::cin.ignore(); // Clear input buffer
            std::cout << "Enter book title: ";
            std::getline(std::cin, title);
            std::cout << "Enter book author: ";
            std::getline(std::cin, author);
            std::cout << "Enter book ISBN: ";
            std::getline(std::cin, isbn);
            library.addBook(Book(title, author, isbn)); // Assuming Book has a constructor for title, author, and ISBN
            std::cout << "Book added successfully.\n";
            break;
        }
        case 3: {
            std::string name, libraryCardNumber;
            std::cin.ignore(); // Clear input buffer
            std::cout << "Enter patron name: ";
            std::getline(std::cin, name);
            std::cout << "Enter library card number: ";
            std::getline(std::cin, libraryCardNumber);
            library.addPatron(Patron(name, libraryCardNumber)); // Assuming Patron has a constructor for name and card number
            std::cout << "Patron added successfully.\n";
            break;
        }
        case 4:
            std::cout << "\nBooks in the library:\n";
            library.displayBooks();
            break;
        case 5:
            std::cout << "\nPatrons of the library:\n";
            library.displayPatrons();
            break;
        case 6:
            std::cout << "Exiting the program. Goodbye!\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}