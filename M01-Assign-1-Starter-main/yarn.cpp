/* Program name: yarn.cpp
* Author: Danielle Lloyd
* Date last updated: 3/18/2025
* Purpose: Yarn Maps
*/
#include "yarn.h"

const std::map<YarnSkein::fiberType, std::string> YarnSkein::fiberToStr = {
    {ACRYLIC, "ACRYLIC"}, {BAMBOO, "BAMBOO"}, {COTTON, "COTTON"}, {SILK, "SILK"}, {WOOL, "WOOL"}
};

const std::map<std::string, YarnSkein::fiberType> YarnSkein::strToFiber = {
    {"ACRYLIC", ACRYLIC}, {"BAMBOO", BAMBOO}, {"COTTON", COTTON}, {"SILK", SILK}, {"WOOL", WOOL}
};

const std::map<std::string, YarnSkein::weightType> YarnSkein::strToWeight = {
    {"BULKY", BULKY}, {"FINE", FINE}, {"JUMBO", JUMBO}, {"LACE", LACE},
    {"LIGHT", LIGHT}, {"MEDIUM", MEDIUM}, {"SUPERBULKY", SUPERBULKY}, {"SUPERFINE", SUPERFINE}
};

const std::map<YarnSkein::weightType, std::string> YarnSkein::weightToStr = {
    {BULKY, "BULKY"}, {FINE, "FINE"}, {JUMBO, "JUMBO"}, {LACE, "LACE"},
    {LIGHT, "LIGHT"}, {MEDIUM, "MEDIUM"}, {SUPERBULKY, "SUPERBULKY"}, {SUPERFINE, "SUPERFINE"}
};

YarnSkein::YarnSkein(std::string strandWeightStr, std::string color, double length, std::string fiberString, double skeinWeight, double needleSize, double hookSize)
    : color(color), length(length), skeinWeight(skeinWeight), needleSize(needleSize), hookSize(hookSize) {
    // Convert strand weight string to weightType
    auto weightIt = strToWeight.find(strandWeightStr);
    if (weightIt == strToWeight.end()) {
        throw std::invalid_argument("Invalid strand weight");
    }
    strandWeight = weightIt->second;

    // Parse and set fibers
    setFiber(fiberString);

    // Validate numerical attributes
    if (length <= 0 || skeinWeight <= 0 || needleSize <= 0 || hookSize <= 0) {
        throw std::invalid_argument("Invalid numerical values");
    }
}

YarnSkein::YarnSkein(const YarnSkein &other)
    : color(other.color), length(other.length), skeinWeight(other.skeinWeight), 
      needleSize(other.needleSize), hookSize(other.hookSize), strandWeight(other.strandWeight), 
      fiber(other.fiber) {}

YarnSkein::~YarnSkein() {}

YarnSkein& YarnSkein::operator=(const YarnSkein &other) {
    if (this != &other) {
        color = other.color;
        length = other.length;
        skeinWeight = other.skeinWeight;
        needleSize = other.needleSize;
        hookSize = other.hookSize;
        strandWeight = other.strandWeight;
        fiber = other.fiber;
    }
    return *this;
}

void YarnSkein::setFiber(const std::string& fiberString) {
    std::string token;
    size_t pos = 0;
    std::string input = fiberString;

    while ((pos = input.find(',')) != std::string::npos) {
        token = input.substr(0, pos);
        input.erase(0, pos + 1);

        // Convert to uppercase
        std::transform(token.begin(), token.end(), token.begin(), ::toupper);

        auto fiberIt = strToFiber.find(token);
        if (fiberIt == strToFiber.end()) {
            throw std::invalid_argument("Invalid fiber type");
        }
        fiber.push_back(fiberIt->second);
    }

    // Handle the last token
    std::transform(input.begin(), input.end(), input.begin(), ::toupper);
    auto fiberIt = strToFiber.find(input);
    if (fiberIt == strToFiber.end()) {
        throw std::invalid_argument("Invalid fiber type");
    }
    fiber.push_back(fiberIt->second);
}

double YarnSkein::getHookSize() const {
    return hookSize;
}

double YarnSkein::getLength() const {
    return length;
}

double YarnSkein::getNeedleSize() const {
    return needleSize;
}

double YarnSkein::getSkeinWeight() const {
    return skeinWeight;
}

std::string YarnSkein::getColor() const {
    return color;
}

std::string YarnSkein::getFiberList() const {
    std::string fiberList;
    for (size_t i = 0; i < fiber.size(); ++i) {
        fiberList += fiberToStr.at(fiber[i]);
        if (i < fiber.size() - 1) {
            fiberList += ", ";
        }
    }
    return fiberList;
}

std::string YarnSkein::getStrandWeightName() const {
    return weightToStr.at(strandWeight);
}

void YarnSkein::setColor(std::string newColor) {
    color = newColor;
}

void YarnSkein::setLength(double newLength) {
    if (newLength <= 0) {
        throw std::invalid_argument("Invalid length value");
    }
    length = newLength;
}
