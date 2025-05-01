#include "hashTable.h"
#include <fstream>
#include <iostream>

int main() {
    const int TABLE_SIZE = 100003; // A prime number for better hashing

    // Create hash tables with different collision resolution strategies
    HashTable quadraticTable(TABLE_SIZE, QUADRATIC_PROBING);
    HashTable chainingTable(TABLE_SIZE, CHAINING);

    // Read numbers from nums.txt and insert them into both hash tables
    std::ifstream file("nums.txt");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open nums.txt" << std::endl;
        return 1;
    }

    int number;
    while (file >> number) {
        quadraticTable.insert(number);
        chainingTable.insert(number);
    }
    file.close();

    // Prompt the user to search for a number
    while (true) {
        std::cout << "Enter a number to search (-1 to quit): ";
        std::cin >> number;

        if (number == -1) {
            break;
        }

        bool foundInQuadratic = quadraticTable.search(number);
        bool foundInChaining = chainingTable.search(number);

        std::cout << "Number " << number << " is "
                  << (foundInQuadratic ? "found" : "not found")
                  << " in HashTable with Quadratic Probing." << std::endl;

        std::cout << "Number " << number << " is "
                  << (foundInChaining ? "found" : "not found")
                  << " in HashTable with Chaining." << std::endl;
    }

    return 0;
}