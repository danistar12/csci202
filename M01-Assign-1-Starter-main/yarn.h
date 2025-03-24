#ifndef YARN_H
#define YARN_H

#include <string>
#include <map>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <sstream>

class YarnSkein {
    public:
        enum fiberType { ACRYLIC, BAMBOO, COTTON, SILK, WOOL };
        enum weightType { BULKY, FINE, JUMBO, LACE, LIGHT, MEDIUM, SUPERBULKY, SUPERFINE };
    
        static const std::map<fiberType, std::string> fiberToStr;
        static const std::map<std::string, fiberType> strToFiber;
        static const std::map<std::string, weightType> strToWeight;
        static const std::map<weightType, std::string> weightToStr;
    
        YarnSkein(std::string strandWeight, std::string color, double length, std::string fiber, double skeinWeight, double needleSize, double hookSize);
        YarnSkein(const YarnSkein &);
        ~YarnSkein();
        YarnSkein& operator=(const YarnSkein &);
    
        double getHookSize() const;
        double getLength() const;
        double getNeedleSize() const;
        double getSkeinWeight() const;
        std::string getColor() const;
        std::string getFiberList() const;
        std::string getStrandWeightName() const;
    
        void setColor(std::string color);
        void setLength(double length);
    
    private:
        double hookSize;
        double length;
        double needleSize;
        double skeinWeight;
        std::vector<fiberType> fiber;
        weightType strandWeight;
        std::string color;
    
        void setFiber(const std::string& fiberString);
    };
// Helper function for removing leading and trailing whitespace from a string
std::string trim(const std::string& str, const std::string& whitespace = " ");

#endif // YARN_H