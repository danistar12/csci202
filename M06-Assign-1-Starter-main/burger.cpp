#include "burger.h"
#include <iostream>

Burger::Burger(int numPatties) : numPatties(numPatties) {}

void Burger::addTopping(toppingType topping) {
    toppings.insert(topping);
}

std::string Burger::getToppings() const {
    std::ostringstream oss;
    Set<toppingType>::Iterator it = toppings.begin();
    bool first = true;
    while (it.hasNext()) {
        if (!first) {
            oss << ", ";
        }
        oss << toppingStr[it.next()];
        first = false;
    }
    return oss.str();
}

std::string Burger::toString() const {
    std::ostringstream out;
    out << "Number of patties: " << numPatties << std::endl;
    out << "Toppings: " << getToppings();
    return out.str();
}
