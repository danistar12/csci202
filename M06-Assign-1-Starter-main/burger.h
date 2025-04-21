#pragma once
#include <string>
#include <sstream>
#include <iomanip>
#include "set.h"

const int TOP_NUM = 8;

enum toppingType {
    GRILLONION,
    RAWONION,
    TOMATO,
    LETTUCE,
    BACON,
    MUSHROOM,
    PICKLE,
    NOTOP
};

const std::string toppingStr[] = {
    "Grilled Onion", "Raw Onion", "Tomato", "Lettuce", 
    "Bacon", "Grilled Mushroom", "Pickle", "None"
};

class Burger {
public:
    Burger(int numPatties);

    void addTopping(toppingType topping);

    std::string getToppings() const;

    std::string toString() const;

private:
    int numPatties;
    Set<toppingType> toppings;
};
