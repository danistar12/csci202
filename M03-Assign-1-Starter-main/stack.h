#ifndef STACK_H
#define STACK_H
#include "stackADT.h"
#include <stdexcept>
#include <iostream>

template <typename T>
class stackType {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* topNode; // Pointer to the top of the stack
    int currentSize; // Tracks the current size of the stack
    int maxSize; // Maximum size allowed (-1 means unlimited)

public:
    // Constructor
    stackType(int max = -1) : topNode(nullptr), currentSize(0), maxSize(max) {}

    // Destructor
    ~stackType() {
        initializeStack(); // Free all dynamically allocated memory
    }

    // Push (Add item to the stack)
    void push(const T& item) {
        if (maxSize > 0 && currentSize >= maxSize)
            throw std::overflow_error("Stack overflow: Maximum size exceeded.");
        Node* newNode = new Node{item, topNode};
        topNode = newNode;
        currentSize++;
    }

    // Pop (Remove item from the stack)
    void pop() {
        if (isEmptyStack())
            throw std::underflow_error("Stack underflow: Cannot pop from an empty stack.");
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        currentSize--;
    }

    // Top (Return top item non-destructively)
    T top() const {
        if (isEmptyStack())
            throw std::underflow_error("Stack underflow: Stack is empty.");
        return topNode->data;
    }

    // Check if the stack is empty
    bool isEmptyStack() const {
        return topNode == nullptr;
    }

    // Initialize stack (reset)
    void initializeStack() {
        while (!isEmptyStack())
            pop();
    }
};

#endif