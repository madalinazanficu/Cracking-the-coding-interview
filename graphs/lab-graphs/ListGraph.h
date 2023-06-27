
#ifndef __LISTGRAPH_H__
#define __LISTGRAPH_H__

#include <vector>

// graf orietntat
struct Node {
    std::vector <int> neighbours;

    Node() = default;

};

class ListGraph {

    private:
        std::vector <Node> nodes;
        int size;

    public:

        // Constructor
        ListGraph(const int size) {
            this->size = size;

            for (int i = 0; i < size; ++i) {
                nodes.push_back(Node());
            }
            
        }

        // Destructor
        ~ListGraph() {}


        void addEdge(int src, int dst) {

            if (hasEdge(src, dst) == false) 
                nodes[src].neighbours.push_back(dst);
        }

        void removeEdge(int src, int dst) {

            std::vector <int>::iterator it = nodes[src].neighbours.begin();
            for (unsigned int i = 0; i < nodes[src].neighbours.size(); ++i) {
                if (nodes[src].neighbours[i] == dst) {
                    nodes[src].neighbours.erase(it);
                    return;
                }
                it++;
            }
        }

        bool hasEdge(int src, int dst) {

            for (unsigned int i = 0; i < nodes[src].neighbours.size(); ++i) {
                if (nodes[src].neighbours[i] == dst) {
                    return true;
                }
            }
            return false;
        }

        // getter for the neighbours of one specifc node
        std::vector <int> getNeighbors(int node) {
            return nodes[node].neighbours;
        }

        int getSize() {
            return size;
        }


};

#endif // __LISTGRAPH_H__


