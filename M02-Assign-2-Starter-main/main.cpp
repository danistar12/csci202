/* Program name: Main.cpp
* Author: Danielle Lloyd    
* Date last updated: 3/26/2025
* Purpose: Create linkedlist
*/

#include "orderedLinkedList.h"
#include "snack.h"
#include <iostream>
#include <string>

int main() {
    orderedLinkedList<snack> snackList;

    std::string name, locCode;
    double price;
    int quantity;

    while (std::cin >> name >> locCode >> price >> quantity) {
        snack newSnack(name, locCode, price, quantity);
        snackList.insert(newSnack);
    }

    return 0;
}