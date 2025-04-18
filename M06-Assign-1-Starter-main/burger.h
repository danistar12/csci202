#pragma once
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cctype>

const int TOP_NUM = 8;

enum toppingType
{
	GRILLONION,
	RAWONION,
	TOMATO,
	LETTUCE,
	BACON,
	MUSHROOM,
	PICKLE,
	NOTOP
};
const std::string toppingStr[] = {"Grilled Onion",
								  "Raw Onion",
								  "Tomato",
								  "Lettuce",
								  "Bacon",
								  "Grilled Mushroom",
								  "Pickle",
								  "None"};
const toppingType toppingList[] = {
	GRILLONION,
	RAWONION,
	TOMATO,
	LETTUCE,
	BACON,
	MUSHROOM,
	PICKLE, NOTOP};
class burger
{
public:
	burger(int numPatties);
	std::string getToppings();
	void addTopping(toppingType);
	std::string tostring();
	void setNumPatties(int num);
	int getNumPatties() const;

private:
	toppingType toppings[7];
	make a set int numToppings;
	This should come from the set

		int numPatties;
};
