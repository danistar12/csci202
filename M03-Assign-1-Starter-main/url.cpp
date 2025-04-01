#include "url.h"
#include <iostream>
#include <fstream>

// Constructor
url::url(const std::string& url, const std::string& file)
    : urlAddress(url), fileName(file) {
    // Simulated HTML content
    std::ofstream outFile(fileName);
    if (outFile.is_open()) {
        outFile << "<HEADER>\n";
        outFile << "<TITLE>The World Wide Web project</TITLE>\n";
        outFile << "<NEXTID N=\"55\">\n";
        outFile << "</HEADER>\n";
        outFile << "<BODY>\n";
        outFile << "<H1>World Wide Web</H1>\n";
        outFile << "The WorldWideWeb (W3) is a wide-area\n";
        outFile << "<A NAME=0 HREF=\"WhatIs.html\">hypermedia</A> information retrieval\n";
        outFile << "initiative aiming to give universal access to a large universe of documents.<P>\n";
        outFile << "</BODY>\n";
        outFile.close();
    } else {
        std::cerr << "Error: Unable to open file " << fileName << "\n";
    }
}

// Function to display file contents
void url::displayFile(int lineLimit) const {
    std::ifstream inFile(fileName);
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open file " << fileName << "\n";
        return;
    }

    std::string line;
    int lineCount = 0;
    while (std::getline(inFile, line)) {
        std::cout << line << "\n";
        lineCount++;
        if (lineLimit > 0 && lineCount >= lineLimit)
            break;
    }
    inFile.close();
}