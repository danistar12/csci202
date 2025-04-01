#ifndef URL_H
#define URL_H
#include <string>
#include <fstream>
#include <iostream>
#include "HTTPRequest.hpp"
class url {
    private:
        std::string urlAddress;
        std::string fileName;
    
    public:
        // Constructor
        url(const std::string& url, const std::string& file);
    
        // Function to display file contents
        void displayFile(int lineLimit = -1) const;
    };
    
#endif
    