
#ifndef __LISTGRAPH_H__
#define __LISTGRAPH_H__

#include <vector>
#include <queue>

// graf orietntat
struct Node {

    std::vector <int> neighbours;
    int depend;
    Node() {
        depend = 0;
    };

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

            if (hasEdge(src, dst) == false) {
                nodes[src].neighbours.push_back(dst);
                nodes[dst].depend++;
            }
        }

        void removeEdge(int src, int dst) {

            std::vector <int>::iterator it = nodes[src].neighbours.begin();
            for (unsigned int i = 0; i < nodes[src].neighbours.size(); ++i) {
                if (nodes[src].neighbours[i] == dst) {
                    nodes[src].neighbours.erase(it);
                    nodes[dst].depend--;
                    return;
                }
                it++;
            }
        }

        void removeDependencies(int src) {
            for (unsigned int i = 0; i < nodes[src].neighbours.size(); ++i) {
                nodes[nodes[src].neighbours[i]].depend--;
            }
            nodes[src].neighbours.clear();
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

    
    void print_depend(int nr) {
        std::cout << nodes[nr].depend << " ";
    }

    bool chech_depend(int nr) {
        if (nodes[nr].depend == 0) {
            return false;
        }
        return true;
    }
    


};

#endif // __LISTGRAPH_H__


