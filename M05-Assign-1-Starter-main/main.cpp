/* Program name: Main.cpp
* Author: Danielle Lloyd    
* Date last updated: 4/14/2025
* Purpose: Binary Search Tree Implementation using product class
*/
#include <iostream>
#include <fstream>
#include <string>
#include "binarySearchTree.h"
#include "product.h"

// Function to load products from a file into the binary search tree
void loadProducts(binarySearchTree<product> &tree, const std::string &filename)
{
    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    double price, rating;
    std::string description, prodNum;

    while (file >> price) // Read price
    {
        file.ignore(); // Ignore the newline after the price
        std::getline(file, description); // Read description
        std::getline(file, prodNum); // Read product number
        file >> rating; // Read rating
        file.ignore(); // Ignore the newline after the rating

        // Create a product object and insert it into the tree
        product prod(price, description, prodNum, rating);
        tree.insert(prod);
    }

    file.close();
}

int main()
{
    binarySearchTree<product> tree;
    loadProducts(tree, "products.txt");

    int choice;
    do
    {
        std::cout << "Menu:\n";
        std::cout << "1. Search for a product\n";
        std::cout << "2. Delete a product\n";
        std::cout << "3. Quit\n";
        std::cin >> choice;

        if (choice == 1)
        {
            std::string prodNum;
            std::cout << "Enter product number: ";
            std::cin >> prodNum;

            try
            {
                // Create a product object for searching
                product searchProd(1.0, "", prodNum, 0.0); // Use a valid price (e.g., 1.0)
                if (tree.search(searchProd))
                    std::cout << searchProd << std::endl; // Ensure operator<< outputs the correct format
                else
                    std::cout << prodNum << " is not found in the tree." << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
        else if (choice == 2)
        {
            std::string prodNum;
            std::cout << "Enter product number to delete: ";
            std::cin >> prodNum;

            try
            {
                // Create a product object for deletion
                product deleteProd(1.0, "", prodNum, 0.0); // Use a valid price (e.g., 1.0)
                tree.deleteNode(deleteProd);
                std::cout << "Product deleted " << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    } while (choice != 3);

    std::cout << "In-order traversal of the tree:\n";
    tree.inorderTraversal();

    return 0;
}