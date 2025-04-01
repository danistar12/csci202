#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <limits>
#include "url.h"
#include "stack.h"

// Function declarations
void resetStream();
void codeGradeLoopFix(std::string errLocation);

int main() {
    stackType<url> backStack;      // Backward history stack
    stackType<url> forwardStack;  // Forward history stack
    url* currentURL = nullptr;    // Pointer to the current URL object

    // Open the navigation file
    std::ifstream navFile("navigation.txt");
    if (!navFile.is_open()) {
        std::cerr << "Error: Unable to open navigation file.\n";
        return 1; // Exit if the file is not found
    }

    std::string urlAddress, fileName;
    int choice;

    // Menu-driven loop
    while (choice != 4) {
        std::cout << "What would you like to do?\n"
                  << "1. Visit next URL\n"
                  << "2. Go back\n"
                  << "3. Go forward\n"
                  << "4. Exit\n";

        if (!(std::cin >> choice)) {
            resetStream(); // Handle invalid input
            continue;
        }

        try {
            switch (choice) {
            case 1: // Visit next URL
                if (navFile >> urlAddress >> fileName) {
                    if (currentURL != nullptr) {
                        backStack.push(*currentURL); // Move current URL to the back stack
                        delete currentURL;
                    }
                    currentURL = new url(urlAddress, fileName); // Create a new URL object
                    currentURL->displayFile(); // Display the content of the file
                    forwardStack.initializeStack(); // Clear the forward stack
                } else {
                    std::cout << "No more URLs in the navigation file.\n";
                }
                break;

            case 2: // Go back
                if (!backStack.isEmptyStack()) {
                    if (currentURL != nullptr)
                        forwardStack.push(*currentURL); // Move the current URL to the forward stack
                    currentURL = new url(backStack.top()); // Retrieve the URL from the back stack
                    backStack.pop();
                    currentURL->displayFile();
                } else {
                    std::cout << "Back history is empty.\n";
                }
                break;

            case 3: // Go forward
                if (!forwardStack.isEmptyStack()) {
                    if (currentURL != nullptr)
                        backStack.push(*currentURL); // Move the current URL to the back stack
                    currentURL = new url(forwardStack.top()); // Retrieve the URL from the forward stack
                    forwardStack.pop();
                    currentURL->displayFile();
                } else {
                    std::cout << "Forward history is empty.\n";
                }
                break;

            case 4: // Exit
                delete currentURL; // Clean up dynamically allocated memory
                navFile.close();
                return 0;

            default:
                std::cout << "Invalid choice. Please try again.\n";
            }
        } catch (const std::exception& ex) {
            std::cerr << "Error: " << ex.what() << "\n";
            codeGradeLoopFix("main menu"); // Handle input-related issues
        }
    }
}

// Function to reset input stream when invalid input is entered
void resetStream() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "You did not enter a number." << std::endl;
}

// Function to handle end-of-input stream issues
void codeGradeLoopFix(std::string errLocation) {
    if (std::cin.eof()) {
        std::cout << "There was a problem and there is no more input! @" + errLocation << std::endl;
        throw std::invalid_argument(errLocation);
    }
}