#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <list>
#include <iostream>
#include <stdexcept>

enum CollisionResolution {
    QUADRATIC_PROBING,
    CHAINING
};

class HashTable {
private:
    // Common attributes
    int size;
    CollisionResolution resolution;

    // Attributes for quadratic probing
    std::vector<int> table;
    std::vector<bool> occupied;

    // Attributes for chaining
    std::vector<std::list<int>> chainTable;

    // Hash function
    int hash(int key) const {
        return key % size;
    }

public:
    // Constructor
    HashTable(int tableSize, CollisionResolution res)
        : size(tableSize), resolution(res) {
        if (resolution == QUADRATIC_PROBING) {
            table.resize(size, -1);       // Initialize table with -1 (empty slots)
            occupied.resize(size, false); // Initialize all slots as unoccupied
        } else if (resolution == CHAINING) {
            chainTable.resize(size);      // Initialize chainTable with empty lists
        }
    }

    // Insert function
    void insert(int key) {
        if (resolution == QUADRATIC_PROBING) {
            int index = hash(key);
            int i = 0;

            while (occupied[index]) {
                index = (hash(key) + i * i) % size;
                i++;
                if (i == size) {
                    throw std::overflow_error("Hash table is full");
                }
            }

            table[index] = key;
            occupied[index] = true;
        } else if (resolution == CHAINING) {
            int index = hash(key);
            chainTable[index].push_back(key);
        }
    }

    // Search function
    bool search(int key) const {
        if (resolution == QUADRATIC_PROBING) {
            int index = hash(key);
            int i = 0;

            while (occupied[index]) {
                if (table[index] == key) {
                    return true;
                }
                index = (hash(key) + i * i) % size;
                i++;
                if (i == size) {
                    return false;
                }
            }

            return false;
        } else if (resolution == CHAINING) {
            int index = hash(key);
            for (int item : chainTable[index]) {
                if (item == key) {
                    return true;
                }
            }
            return false;
        }

        return false; // Should never reach here
    }
};

#endif // HASHTABLE_H