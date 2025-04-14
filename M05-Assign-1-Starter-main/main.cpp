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

//function to load products from a file into the binary search tree
void loadProducts(binarySearchTree<product> &tree, const std::string &filename)
{
    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }
    
    std::string prodNum, prodName;
    double price;
    int quantity;

    while (file >> prodNum >> prodName >> price >> quantity)
    {
        product prod(prodNum, prodName, price, quantity);
        tree.insert(prod);
    }

    file.close();
}

int main()
{
    binarySearchTree<product> tree;
    loadProducts(tree, "products.txt");

    int choice;
    do //opted for a do/while loop to ensure the menu is displayed
    {
        std::cout << "Menu:\n";
        std::cout << "1. Search for a product\n";
        std::cout << "2. Delete a product\n";
        std::cout << "3. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            std::string prodNum;
            std::cout << "Enter product number: ";
            std::cin >> prodNum;
            // Search for the product in the tree
            product searchProd(prodNum, "", 0.0, 0);
            if (tree.search(searchProd))
                std::cout << "Product found: " << searchProd << std::endl;
            else
                std::cout << prodNum << " is not found in the tree." << std::endl;
        }
        else if (choice == 2)
        {
            std::string prodNum;
            std::cout << "Enter product number to delete: ";
            std::cin >> prodNum;

            product deleteProd(prodNum, "", 0.0, 0);
            tree.deleteNode(deleteProd);
            std::cout << "Product deleted (if it existed)." << std::endl;
        }
    } while (choice != 3); // Exit the loop if the user chooses to quit

    std::cout << "In-order traversal of the tree:\n";
    tree.inorderTraversal();

    return 0;
}
