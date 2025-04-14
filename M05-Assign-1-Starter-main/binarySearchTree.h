#ifndef SEARCH_H
#define SEARCH_H

#include "binaryTree.h"

// This is a binary search tree class that inherits from the binaryTreeType class.
template <class elemType>
class binarySearchTree : public binaryTreeType<elemType>
{
public:
    bool search(const elemType &searchItem) const override;
    void insert(const elemType &insertItem) override;
    void deleteNode(const elemType &deleteItem) override;

private:
    void deleteFromTree(nodeType<elemType> *&p);
};
// Search for an item in the binary tree.
template <class elemType>
bool binarySearchTree<elemType>::search(const elemType &searchItem) const
{
    nodeType<elemType> *current = this->root;

    while (current != nullptr)
    {
        if (*current->info == searchItem)
            return true;
        else if (*current->info > searchItem)
            current = current->lLink;
        else
            current = current->rLink;
    }

    return false;
}
// Insert an item into the binary tree.
// If the item already exists, do nothing.
// If the item is less than the current node, go left.
// If the item is greater than the current node, go right.
// If the current node is null, insert the new node.
template <class elemType>
void binarySearchTree<elemType>::insert(const elemType &insertItem)
{
    nodeType<elemType> *newNode = new nodeType<elemType>;
    newNode->info = new elemType(insertItem);
    newNode->lLink = nullptr;
    newNode->rLink = nullptr;

    if (this->root == nullptr)
    {
        this->root = newNode;
    }
    else
    {
        nodeType<elemType> *current = this->root;
        nodeType<elemType> *trailCurrent = nullptr;

        while (current != nullptr)
        {
            trailCurrent = current;
            if (*current->info == insertItem)
            {
                delete newNode;
                return; // Duplicate item, do nothing
            }
            else if (*current->info > insertItem)
                current = current->lLink;
            else
                current = current->rLink;
        }

        if (*trailCurrent->info > insertItem)
            trailCurrent->lLink = newNode;
        else
            trailCurrent->rLink = newNode;
    }
}
// Function to find the node to be deleted and call the deleteFromTree function.
// This function traverses the tree to find the node to be deleted.
template <class elemType>
void binarySearchTree<elemType>::deleteNode(const elemType &deleteItem)
{
    nodeType<elemType> *current = this->root;
    nodeType<elemType> *trailCurrent = nullptr;

    while (current != nullptr && *current->info != deleteItem)
    {
        trailCurrent = current;
        if (*current->info > deleteItem)
            current = current->lLink;
        else
            current = current->rLink;
    }

    if (current == nullptr)
        return; // Item not found

    if (current == this->root)
        deleteFromTree(this->root);
    else if (*trailCurrent->info > deleteItem)
        deleteFromTree(trailCurrent->lLink);
    else
        deleteFromTree(trailCurrent->rLink);
}
// takes a pointer to the node to be deleted and deletes it.
template <class elemType>
void binarySearchTree<elemType>::deleteFromTree(nodeType<elemType> *&p)
{
    nodeType<elemType> *current;
    nodeType<elemType> *trailCurrent;
    nodeType<elemType> *temp;
    
    if (p == nullptr)
        return;
    else if (p->lLink == nullptr && p->rLink == nullptr)
    {
        temp = p;
        p = nullptr;
        delete temp;
    }
    else if (p->lLink == nullptr)
    {
        temp = p;
        p = p->rLink;
        delete temp;
    }
    else if (p->rLink == nullptr)
    {
        temp = p;
        p = p->lLink;
        delete temp;
    }
    else
    {
        current = p->lLink;
        trailCurrent = nullptr;

        while (current->rLink != nullptr)
        {
            trailCurrent = current;
            current = current->rLink;
        }

        *p->info = *current->info;

        if (trailCurrent == nullptr)
            p->lLink = current->lLink;
        else
            trailCurrent->rLink = current->lLink;

        delete current;
    }
}

#endif