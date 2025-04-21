#include <iostream>
#include <string>
#include <limits>
#include "burger.h"

void resetStream();
int promptNumPatties();
void promptToppings(Burger& burger);

int main() {
    // Prompt for the number of patties
    int pat = promptNumPatties();
    Burger myBurger(pat);

    // Prompt for toppings
    promptToppings(myBurger);

    // Output the burger details
    std::cout << myBurger.toString() << std::endl;

    return 0;
}

void resetStream() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int promptNumPatties() {
    int pat;
    std::cout << "How many patties do you want on your burger? ";
    std::cin >> pat;
    std::cout << std::endl;
    if (std::cin && pat > 0) {
        return pat;
    } else if (!std::cin) {
        resetStream();
    }
    std::cout << "You entered an invalid amount of patties. Please try again." << std::endl;
    return promptNumPatties();
}

void promptToppings(Burger& burger) {
    int topInt;
    while (true) {
        std::cout << "Please choose a topping from the list. Enter -1 to stop adding toppings." << std::endl;
        for (int i = 0; i < TOP_NUM; i++) {
            std::cout << i + 1 << ": " << toppingStr[i] << std::endl;
        }
        std::cin >> topInt;
        std::cout << std::endl;
        if (topInt == -1) {
            break; // Exit the loop if the user enters -1
        }
        while (!std::cin || topInt <= 0 || topInt > TOP_NUM) {
            if (!std::cin) {
                resetStream();
            }
            std::cout << "You did not choose a valid topping. Please try again." << std::endl;
            std::cin >> topInt;
            std::cout << std::endl;
        }
        burger.addTopping(static_cast<toppingType>(topInt - 1));
    }
}
