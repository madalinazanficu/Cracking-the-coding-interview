#ifndef __LIST_GRAPH_H__
#define __LIST_GRAPH_H__

#include <vector>

// graf orietntat
struct Node {
    std::vector <int> neighbours;
};

class ListGraph {

    private:
        std::vector <Node> nodes;
        int size;

    public:

        // Constructor
        ListGraph(int size) {
            this->size = size;

            for (int i = 0; i < size; ++i) {
                Node add;
                nodes.push_back(add);
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
            for (int i = 0; i < nodes[src].neighbours.size(); ++i) {
                if (nodes[src].neighbours[i] == dst) {
                    nodes[src].neighbours.erase(it);
                    return;
                }
                it++;
            }
        }

        bool hasEdge(int src, int dst) {

            for (int i = 0; i < nodes[src].neighbours.size(); ++i) {
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

        int size() {
            return size;
        }


};

#endif // __LIST_GRAPH_H__