#include <iostream>
#include <fstream>
#include <vector>
#include "graph.h"

int main() {
    std::ifstream in("routes.txt");
    if (!in.is_open()) {
        std::cerr << "Error: Cannot open input file." << std::endl;
        return 1;
    }

    // Count the number of IP addresses in the input file
    std::string line;
    std::vector<std::string> ipAddresses;
    while (std::getline(in, line)) {
        if (line.find('.') != std::string::npos) { // Check if the line contains an IP address
            ipAddresses.push_back(line);
        } else {
            break; // Stop when adjacency list starts
        }
    }
    in.close();

    int maxSize = ipAddresses.size(); // Set maxSize to the number of IP addresses
    graphType graph(maxSize);

    try {
        graph.createGraph("routes.txt");

        std::string startIP, endIP;
        std::cout << "Enter the starting IP address: ";
        std::cin >> startIP;
        std::cout << "Enter the ending IP address: ";
        std::cin >> endIP;

        std::cout << "\nFinding path from " << startIP << " to " << endIP << std::endl;

        std::vector<std::string> path = graph.findPath(startIP, endIP);

        if (!path.empty()) {
            for (size_t i = 0; i < path.size(); i++) {
                std::cout << path[i];
                if (i != path.size() - 1) {
                    std::cout << "-->";
                }
            }
            std::cout << std::endl;
        } else {
            std::cout << "No path found between " << startIP << " and " << endIP << "." << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}