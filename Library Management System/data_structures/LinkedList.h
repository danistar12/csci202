#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        clear();
    }

    void addNode(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void removeNode(T value) {
        if (!head) return;

        if (head->data == value) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node<T>* current = head;
        Node<T>* previous = nullptr;

        while (current && current->data != value) {
            previous = current;
            current = current->next;
        }

        if (current) {
            previous->next = current->next;
            delete current;
        }
    }
    void forEach(std::function<void(const T&)> func) const {
        Node* current = head;
        while (current != nullptr) {
            func(current->data);
            current = current->next;
        }
    }    
    void traverse() const {
        Node<T>* temp = head;
        while (temp) {
            std::cout << temp->data << " "; // This now works because of operator<<
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void clear() {
        while (head) {
            removeNode(head->data);
        }
    }
};

#endif // LINKEDLIST_H