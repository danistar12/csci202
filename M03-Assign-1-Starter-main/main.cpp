#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <limits>
#include "url.h"
#include "stack.h"

void resetStream();
void codeGradeLoopFix(std::string errLocation);

int main()
{
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "You did not enter a number." << std::endl;
}

void codeGradeLoopFix(std::string errLocation)
{
    if (std::cin.eof())
    {
        std::cout << "There was a problem and there is no more input! @" + errLocation << std::endl;
        throw std::invalid_argument(errLocation); // return or throw an exception here to force the program to end or return from the function.
    }
}