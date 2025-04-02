/* Program name: Main.cpp
* Author: Danielle Lloyd    
* Date last updated: 4/02/2025
* Purpose: Priority Queues
*/
#include <iostream>
#include <regex>
#include <list>
#include "priorityQueue.h"

// Validate date format (yyyy-mm-dd)
bool validateDate(const std::string& date) {
    std::regex datePattern(R"(^(20\d{2})-(0[1-9]|1[0-2])-(0[1-9]|[12]\d|3[01])$)");
    return std::regex_match(date, datePattern);
}

int main() {
    priorityQueue bugQueue;
    std::list<BugReport> completedReports;
    int choice, idCounter = 1;

    do {
        std::cout << "Please choose from the following menu:\n";
        std::cout << "1. Enter Bug Report\n2. Distribute Bug Report\n3. Quit\n";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            std::string date, name, description;
            int priority;

            // Validate date input
            do {
                std::cout << "Enter the date of the report (yyyy-mm-dd): ";
                std::getline(std::cin, date);
                if (!validateDate(date)) {
                    std::cout << "The date entered is not valid. Please check that the date entered is in the correct format.\n";
                }
            } while (!validateDate(date));

            std::cout << "Enter the name of the reporter: ";
            std::getline(std::cin, name);
            std::cout << "Describe the bug: ";
            std::getline(std::cin, description);
            std::cout << "What is the priority 1 - 10 (1 is low, 10 is high):  ";
            std::cin >> priority;
            std::cin.ignore();

            BugReport newBug(idCounter++, description, name, "new", priority, date);
            bugQueue.enqueue(newBug);
        } 
        else if (choice == 2) {
            if (!bugQueue.isEmpty()) {
                BugReport nextBug = bugQueue.dequeue();
                std::cout << "Next bug report assigned:\n" << nextBug << std::endl;
                completedReports.push_back(nextBug);
            } else {
                std::cout << "No bug reports to distribute.\n";
            }
        }
    } while (choice != 3);
    
    // **Final Output Formatting**
    std::cout << "\nQuitting:\n";

    std::cout << "\nList of Finished Bug Reports:\n";
    for (const BugReport& report : completedReports) {
        std::cout << report << std::endl;
    }

    std::cout << "\nList of Unfinished Bug Reports:\n";
    bugQueue.displayQueue(); // Displays reports still in queue as "new"

    return 0;
}
