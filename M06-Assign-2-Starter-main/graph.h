#ifndef GRAPH_H
#define GRAPH_H

#include "unorderedLinkedList.h"
#include "linkedQueue.h"
#include <string>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <vector>
#include <regex>

class graphType {
public:
    bool isEmpty() const;
    void createGraph(std::string filename);
    void clearGraph();
    std::string printGraph() const;
    graphType(int size = 0);
    ~graphType();

    std::vector<std::string> findPath(const std::string &startIP, const std::string &endIP);

    std::string depthFirstTraversal();
    std::string dftAtVertex(int vertex);
    std::string breadthFirstTraversal();

private:
    int maxSize;
    int gSize;
    unorderedLinkedList<int> *graph;
    std::vector<std::string> ipAddresses; // Vector to store IP addresses

    bool findPathDFS(int start, int end, std::vector<bool> &visited, std::vector<int> &path);
    void dft(int v, bool visited[], std::string &output);
};

#endif