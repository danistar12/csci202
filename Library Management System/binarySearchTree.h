#ifndef SEARCH_H
#define SEARCH_H

#include "binaryTree.h"

// Class definition for a binary search tree
template <class elemType>
class binarySearchTree : public binaryTreeType<elemType>
{
public:
    bool search(const elemType &searchItem) const override;
    void insert(const elemType &insertItem) override;
    void deleteNode(const elemType &deleteItem) override;

private:
    // Helper function to delete a node from the tree
    void deleteFromTree(nodeType<elemType> *&p);
};

// Function to search for an item in the binary search tree
template <class elemType>
bool binarySearchTree<elemType>::search(const elemType &searchItem) const
{
    nodeType<elemType> *current = this->root;
    while (current != nullptr)
    {
        if (*current->info == searchItem) // Item found
            return true;
        else if (*current->info > searchItem) // Search in the left subtree
            current = current->lLink;
        else // Search in the right subtree
            current = current->rLink;
    }
    return false; // Item not found
}

// Function to insert an item into the binary search tree
template <class elemType>
void binarySearchTree<elemType>::insert(const elemType &insertItem)
{
    // Create a new node for the item
    nodeType<elemType> *newNode = new nodeType<elemType>;
    newNode->info = new elemType(insertItem);
    newNode->lLink = nullptr;
    newNode->rLink = nullptr;

    if (this->root == nullptr) // Tree is empty
    {
        this->root = newNode; // Set the new node as the root
    }
    else
    {
        nodeType<elemType> *current = this->root;
        nodeType<elemType> *trailCurrent = nullptr;

        // Traverse the tree to find the correct position for the new node
        while (current != nullptr)
        {
            trailCurrent = current;
            if (*current->info == insertItem) // Duplicate item, do nothing
            {
                delete newNode;
                return;
            }
            else if (*current->info > insertItem) // Move to the left subtree
                current = current->lLink;
            else // Move to the right subtree
                current = current->rLink;
        }

        // Insert the new node at the correct position
        if (*trailCurrent->info > insertItem)
            trailCurrent->lLink = newNode;
        else
            trailCurrent->rLink = newNode;
    }
}

// Function to delete an item from the binary search tree
template <class elemType>
void binarySearchTree<elemType>::deleteNode(const elemType &deleteItem)
{
    nodeType<elemType> *current = this->root;
    nodeType<elemType> *trailCurrent = nullptr;

    // Traverse the tree to find the node to delete
    while (current != nullptr && *current->info != deleteItem)
    {
        trailCurrent = current;
        if (*current->info > deleteItem) // Move to the left subtree
            current = current->lLink;
        else // Move to the right subtree
            current = current->rLink;
    }

    if (current == nullptr) // Item not found
        return;

    // Delete the node
    if (current == this->root) // Node to delete is the root
        deleteFromTree(this->root);
    else if (*trailCurrent->info > deleteItem) // Node is in the left subtree
        deleteFromTree(trailCurrent->lLink);
    else // Node is in the right subtree
        deleteFromTree(trailCurrent->rLink);
}

// Helper function to delete a node from the tree
template <class elemType>
void binarySearchTree<elemType>::deleteFromTree(nodeType<elemType> *&p)
{
    nodeType<elemType> *current;
    nodeType<elemType> *trailCurrent;
    nodeType<elemType> *temp;

    if (p == nullptr) // Node is null, do nothing
        return;
    else if (p->lLink == nullptr && p->rLink == nullptr) // Case 1: No children
    {
        temp = p;
        p = nullptr;
        delete temp;
    }
    else if (p->lLink == nullptr) // Case 2: One child (right)
    {
        temp = p;
        p = p->rLink;
        delete temp;
    }
    else if (p->rLink == nullptr) // Case 2: One child (left)
    {
        temp = p;
        p = p->lLink;
        delete temp;
    }
    else // Case 3: Two children
    {
        // Find the in-order predecessor (rightmost node in the left subtree)
        current = p->lLink;
        trailCurrent = nullptr;

        while (current->rLink != nullptr)
        {
            trailCurrent = current;
            current = current->rLink;
        }

        // Replace the value of the node to delete with the in-order predecessor
        *p->info = *current->info;

        // Delete the in-order predecessor
        if (trailCurrent == nullptr) // Predecessor is the left child
            p->lLink = current->lLink;
        else
            trailCurrent->rLink = current->lLink;

        delete current;
    }
}

#endif