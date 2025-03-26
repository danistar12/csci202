#ifndef OLLIST_H
#define OLLIST_H

#include "linkedList.h" 

template <typename Type>
class orderedLinkedList : public linkedList<Type> {
public:
    void insert(const Type &newItem);
    void insertFirst(const Type &newItem) override { insert(newItem); }
    void insertLast(const Type &newItem) override { insert(newItem); }
    void deleteNode(const Type &deleteItem) override;
    bool search(const Type &searchItem) const override;
};

template <typename Type>
void orderedLinkedList<Type>::insert(const Type &newItem) {
    node<Type> *newNode = new node<Type>;
    newNode->info = new Type(newItem);
    newNode->link = nullptr;

    if (this->first == nullptr || *(newNode->info) < *(this->first->info)) {
        newNode->link = this->first;
        this->first = newNode;
        if (this->last == nullptr) this->last = newNode;
    } else {
        node<Type> *current = this->first;
        while (current->link != nullptr && *(current->link->info) < *(newNode->info)) {
            current = current->link;
        }
        newNode->link = current->link;
        current->link = newNode;
        if (newNode->link == nullptr) this->last = newNode; 
    }
    this->count++;
}

template <typename Type>
bool orderedLinkedList<Type>::search(const Type &searchItem) const {
    node<Type> *current = this->first;
    while (current != nullptr) {
        if (*(current->info) == searchItem) return true;
        if (*(current->info) > searchItem) return false; 
        current = current->link;
    }
    return false;
}

template <typename Type>
void orderedLinkedList<Type>::deleteNode(const Type &deleteItem) {
    if (this->first == nullptr) return; 
    if (*(this->first->info) == deleteItem) {
        node<Type> *temp = this->first;
        this->first = this->first->link;
        delete temp;
        this->count--;
        if (this->first == nullptr) this->last = nullptr;
        return;
    }
    node<Type> *current = this->first;
    while (current->link != nullptr && !( *(current->link->info) == deleteItem )) {
        current = current->link;
    }
    if (current->link != nullptr) {
        node<Type> *temp = current->link;
        current->link = current->link->link;
        delete temp;
        this->count--;
        if (current->link == nullptr) this->last = current; 
    }
}
#endif