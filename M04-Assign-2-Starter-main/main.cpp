/* Program name: Main.cpp
* Author: Danielle Lloyd    
* Date last updated: 4/08/2025
* Purpose: This program tests the unordered linked list class and the product class.
*/
#include <iostream>
#include <fstream>
#include "unorderedLinkedList.h"
#include "product.h"

int compareDescription(product &item1, product &item2);
int comparePrice(product &item1, product &item2);
int compareRating(product &item1, product &item2);

int main()
{
    unorderedLinkedList<product> listByPrice;
    unorderedLinkedList<product> listByDescription;
    unorderedLinkedList<product> listByRating;
    // Read from file
    std::ifstream inFile("products.txt");
    if (!inFile)
    {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string description, productNumber;
    double price, rating;

    // Read file line-by-line, ensuring proper stream advancement
    while (inFile >> price)  
    {
        inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Consume any trailing newline

        std::getline(inFile, description);  // Read full description (handles spaces)
        std::getline(inFile, productNumber);  // Read full product number
        inFile >> rating;  // Read rating
        inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ensure new line is removed

        // Create product object and insert it into lists
        product newProduct(price, description, productNumber, rating);
        listByPrice.insert(newProduct);
        listByDescription.insert(newProduct);
        listByRating.insert(newProduct);
    }

    inFile.close();

    std::cout << "\nOriginal list for ordering by description:\n";
    listByDescription.print(std::cout, "\n");
    std::cout << "\nOriginal list for ordering by price:\n";
    listByPrice.print(std::cout, "\n");
    std::cout << "\nOriginal list for ordering by rating:\n";
    listByRating.print(std::cout, "\n");

    // Perform merge sort
    listByDescription.mergeSort(compareDescription);
    listByPrice.mergeSort(comparePrice);
    listByRating.mergeSort(compareRating);

    std::cout << "\nSorted by description:\n";
    listByDescription.print(std::cout, "\n");
    std::cout << "\nSorted by price:\n";
    listByPrice.print(std::cout, "\n");
    std::cout << "\nSorted by rating:\n";
    listByRating.print(std::cout, "\n");

    return 0;
}

// Comparison functions
int compareDescription(product &item1, product &item2)
{
    return item1.getDescription().compare(item2.getDescription());
}

int comparePrice(product &item1, product &item2)
{
    return (item1.getPrice() < item2.getPrice()) ? -1 : (item1.getPrice() > item2.getPrice() ? 1 : 0);
}

int compareRating(product &item1, product &item2)
{
    return (item1.getRating() < item2.getRating()) ? -1 : (item1.getRating() > item2.getRating() ? 1 : 0);
}