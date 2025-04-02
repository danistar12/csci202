#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "BugReport.h"
#include <iostream>

struct Node {
    BugReport data;
    Node* next;
    Node(const BugReport& bug) : data(bug), next(nullptr) {}
};

class priorityQueue {
private:
    Node* head;

public:
    priorityQueue() : head(nullptr) {}

    void enqueue(const BugReport& report) {
        Node* newNode = new Node(report);
        if (!head || report.getPriority() > head->data.getPriority()) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next && current->next->data.getPriority() >= report.getPriority()) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    BugReport dequeue() {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty.");
        }
        Node* temp = head;
        BugReport report = temp->data;
        head = head->next;
        report.setStatus("Finished");  // **Updates status when dequeued** 
        delete temp;
        return report;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void displayQueue() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << std::endl;
            current = current->next;
        }
    }

    ~priorityQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

#endif