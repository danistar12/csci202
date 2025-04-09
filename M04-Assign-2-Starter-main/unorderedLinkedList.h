#ifndef UNORDERED_H
#define UNORDERED_H
#include "linkedList.h"

template <class type>
class unorderedLinkedList : public linkedListType<type>
{
public:
    void insert(const type &newdata) override;
    void deleteNode(const type &deleteItem) override;
    bool search(const type &searchItem) const override;
    void mergeSort(int (*compare)(type &, type &)); // Merge sort function

private:
    // Helper functions for merge sort
    node<type> *mergeSortHelper(node<type> *head, int (*compare)(type &, type &));
    // Merge two sorted lists
    node<type> *merge(node<type> *left, node<type> *right, int (*compare)(type &, type &));
};

// Insert function
template <class type>
inline void unorderedLinkedList<type>::insert(const type &newdata)
{
    node<type> *newNode = new node<type>;
    newNode->data = new type(newdata);  // Ensure data is copied properly
    newNode->link = nullptr;

    if (this->isEmptyList())
    {
        this->head = newNode;
        this->tail = newNode;
    }
    else
    {
        this->tail->link = newNode;
        this->tail = newNode;
    }
    this->count++;
}

// Delete node function (override base class)
template <class type>
inline void unorderedLinkedList<type>::deleteNode(const type &deleteItem)
{
    if (this->isEmptyList()) throw std::out_of_range("Cannot delete from an empty list.");

    node<type> *current = this->head;
    node<type> *prev = nullptr;

    while (current != nullptr && *(current->data) != deleteItem)
    {
        prev = current;
        current = current->link;
    }

    if (!current) throw std::out_of_range("Item not found in list. Cannot delete.");

    if (!prev) this->head = current->link;
    else prev->link = current->link;

    if (this->tail == current) this->tail = prev;

    delete current;
    this->count--;
}

// Search function (override base class)
template <class type>
inline bool unorderedLinkedList<type>::search(const type &searchItem) const
{
    node<type> *current = this->head;
    while (current != nullptr)
    {
        if (*(current->data) == searchItem) return true;
        current = current->link;
    }
    return false;
}

// Merge Sort
template <class type>
void unorderedLinkedList<type>::mergeSort(int (*compare)(type &, type &))
{
    if (!this->head || !this->head->link) return;
    this->head = mergeSortHelper(this->head, compare);
}

// Merge Sort Helper
template <class type>
node<type> *unorderedLinkedList<type>::mergeSortHelper(node<type> *head, int (*compare)(type &, type &))
{
    if (!head || !head->link) return head;

    node<type> *slow = head, *fast = head->link;
    while (fast && fast->link)
    {
        slow = slow->link;
        fast = fast->link->link;
    }

    node<type> *mid = slow->link;
    slow->link = nullptr;

    node<type> *left = mergeSortHelper(head, compare);
    node<type> *right = mergeSortHelper(mid, compare);

    return merge(left, right, compare);
}

// Merge two sorted lists
template <class type>
node<type> *unorderedLinkedList<type>::merge(node<type> *left, node<type> *right, int (*compare)(type &, type &))
{
    if (!left) return right;
    if (!right) return left;

    node<type> *result;
    if (compare(*(left->data), *(right->data)) <= 0)
    {
        result = left;
        result->link = merge(left->link, right, compare);
    }
    else
    {
        result = right;
        result->link = merge(left, right->link, compare);
    }

    return result;
}

#endif