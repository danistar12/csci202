#include "graph.h"
#include <iostream>
bool graphType::isEmpty() const {
    return gSize == 0;
}

void graphType::createGraph(std::string filename) {
    std::ifstream in(filename);
    if (!in.is_open()) {
        throw std::runtime_error("Cannot open input file.");
    }

    std::string line;
    std::regex ipRegex(R"((\d{1,3}\.){3}\d{1,3})"); // Regex to match IP addresses
    ipAddresses.clear();

    while (std::getline(in, line)) {
        if (std::regex_match(line, ipRegex)) {
            // Line contains an IP address
            ipAddresses.push_back(line);
        } else {
            // Line contains adjacency list
            std::istringstream iss(line);
            int vertex, adjacentVertex;
            iss >> vertex;

            if (vertex < 0 || vertex >= maxSize) {
                throw std::runtime_error("Invalid vertex index in adjacency list: " + std::to_string(vertex));
            }

            while (iss >> adjacentVertex) {
                if (adjacentVertex == -999) {
                    break; // Stop processing neighbors for this vertex
                }

                // Skip invalid adjacent vertices
                if (adjacentVertex < 0 || adjacentVertex >= maxSize) {
                    continue;
                }

                graph[vertex].insert(adjacentVertex);
            }
        }
    }

    gSize = ipAddresses.size(); // Ensure this is inside the function
    in.close();                 // Ensure this is inside the function
}

void graphType::clearGraph() {
    for (int i = 0; i < gSize; i++) {
        graph[i].destroyList();
    }
    gSize = 0;
}

std::string graphType::printGraph() const {
    std::ostringstream out;

    for (int i = 0; i < gSize; i++) {
        out << i << ": ";
        out << graph[i].print(); // Call the print() function and append its result
        out << std::endl;
    }

    return out.str();
}

graphType::graphType(int size) {
    maxSize = size;
    gSize = 0;
    graph = new unorderedLinkedList<int>[size];
}

graphType::~graphType() {
    clearGraph();
    delete[] graph;
}

std::string graphType::depthFirstTraversal() {
    bool *visited;
    visited = new bool[gSize];
    std::string out = "";
    for (int i = 0; i < gSize; i++)
        visited[i] = false;
    for (int i = 0; i < gSize; i++) {
        if (!visited[i])
            dft(i, visited, out);
    }
    delete[] visited;
    return out;
}

std::string graphType::dftAtVertex(int vertex) {
    bool *visited;
    visited = new bool[gSize];
    for (int i = 0; i < gSize; i++)
        visited[i] = false;
    std::string out = "";
    dft(vertex, visited, out);
    delete[] visited;
    return out;
}

std::string graphType::breadthFirstTraversal() {
    linkedQueue<int> queue;
    bool *visited;
    visited = new bool[gSize];
    for (int i = 0; i < gSize; i++)
        visited[i] = false;
    std::string out = "";
    linkedListIterator<int> graphIt;
    for (int i = 0; i < gSize; i++) {
        if (!visited[i]) {
            queue.enqueue(i);
            visited[i] = true;
            out = out + " " + std::to_string(i) + " ";
            while (!queue.isEmptyQueue()) {
                int u = queue.dequeue();
                for (graphIt = graph[u].begin(); graphIt != graph[u].end(); ++graphIt) {
                    int w = *graphIt;
                    if (!visited[w]) {
                        queue.enqueue(w);
                        visited[w] = true;
                        out = out + " " + std::to_string(w) + " ";
                    }
                }
            }
        }
    }
    delete[] visited;
    return out;
}

void graphType::dft(int v, bool visited[], std::string &output) {
    visited[v] = true;
    output = output + " " + std::to_string(v) + " ";
    linkedListIterator<int> graphIt;
    for (graphIt = graph[v].begin(); graphIt != graph[v].end(); ++graphIt) {
        int w = *graphIt;
        if (!visited[w])
            dft(w, visited, output);
    }
}

std::vector<std::string> graphType::findPath(const std::string &startIP, const std::string &endIP) {
    int startIndex = -1, endIndex = -1;

    // Find indices of the start and end IP addresses
    for (int i = 0; i < ipAddresses.size(); i++) {
        if (ipAddresses[i] == startIP)
            startIndex = i;
        if (ipAddresses[i] == endIP)
            endIndex = i;
    }

    if (startIndex == -1 || endIndex == -1) {
        throw std::invalid_argument("One or both IP addresses not found.");
    }

    std::vector<bool> visited(gSize, false);
    std::vector<int> path;

    if (findPathDFS(startIndex, endIndex, visited, path)) {
        std::vector<std::string> result;
        for (int index : path) {
            result.push_back(ipAddresses[index]);
        }
        return result;
    } else {
        return {}; // No path found
    }
}

bool graphType::findPathDFS(int start, int end, std::vector<bool> &visited, std::vector<int> &path) {
    visited[start] = true;
    path.push_back(start);

    if (start == end)
        return true;

    linkedListIterator<int> it;
    for (it = graph[start].begin(); it != graph[start].end(); ++it) {
        int neighbor = *it;

        if (neighbor < 0 || neighbor >= maxSize) {
            continue; // Skip invalid neighbors
        }

        if (!visited[neighbor]) {
            if (findPathDFS(neighbor, end, visited, path))
                return true;
        }
    }

    path.pop_back();
    return false;
}
