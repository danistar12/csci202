#include "burger.h"

burger::burger(int numPatties)
{
	setNumPatties(numPatties);
}

std::string burger::getToppings()
{
	std::string c;
	c = toppingStr[toppings[0]];
	for (int i = 1; i < numToppings; i++)
	{
		c += ", " + toppingStr[toppings[i]];
	}
	return c;
}

void burger::setNumPatties(int num)
{
	if (num > 0)
		numPatties = num;
	else
		std::cout << "The number of patties should be greater than 0." << std::endl;
}

std::string burger::tostring()
{
	std::ostringstream out;
	out << std::setprecision(2) << std::fixed << std::showpoint;
	out << "Number of patties: " << numPatties << std::endl;
	out << "Toppings: " << getToppings();

	return out.str();
}
