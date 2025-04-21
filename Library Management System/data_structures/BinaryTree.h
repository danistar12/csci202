#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

template <typename T>
class BinaryTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(T value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insertRec(Node* node, T value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else if (value > node->data) {
            node->right = insertRec(node->right, value);
        }
        return node;
    }

    Node* removeRec(Node* node, T value) {
        if (node == nullptr) {
            return node;
        }
        if (value < node->data) {
            node->left = removeRec(node->left, value);
        } else if (value > node->data) {
            node->right = removeRec(node->right, value);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = removeRec(node->right, temp->data);
        }
        return node;
    }

    bool searchRec(Node* node, T value) const {
        if (node == nullptr) {
            return false;
        }
        if (node->data == value) {
            return true;
        }
        return value < node->data ? searchRec(node->left, value) : searchRec(node->right, value);
    }

    void clearRec(Node* node) {
        if (node) {
            clearRec(node->left);
            clearRec(node->right);
            delete node;
        }
    }

    Node* minValueNode(Node* node) const {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree() { clear(); }

    void insert(T value) {
        root = insertRec(root, value);
    }

    void remove(T value) {
        root = removeRec(root, value);
    }

    bool search(T value) const {
        return searchRec(root, value);
    }

    void clear() {
        clearRec(root);
        root = nullptr;
    }

    void traverseInOrder(Node* node) const {
        if (node) {
            traverseInOrder(node->left);
            std::cout << node->data << " ";
            traverseInOrder(node->right);
        }
    }

    void display() const {
        traverseInOrder(root);
        std::cout << std::endl;
    }
};

#endif // BINARYTREE_H