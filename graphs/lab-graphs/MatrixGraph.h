
#ifndef __MATRIXGRAPH_H__
#define __MATRIXGRAPH_H__

#include <vector>


class MatrixGraph {
private:
    std::vector<std::vector<int>> adjacency_matrix;
    int size;

public:
    // Constructor
    MatrixGraph(int size) {
        this->size = size;

        for (int i = 0; i < size; i++) {
            std::vector <int> vect(size); // initialization for every line
            adjacency_matrix.push_back(vect);

        }
    }

    // Destructor
    ~MatrixGraph() {}
        bool hasEdge(int src, int dst) {
        
        std::vector <int> my_source = adjacency_matrix[src];
        return my_source[dst];
    }


    void addEdge(int src, int dst) {
        (adjacency_matrix.at(src)).at(dst) = 1;
    }

    void removeEdge(int src, int dst) {

        std::vector <int> my_source = adjacency_matrix[src];
        if (hasEdge(src, dst) == true) {
            my_source[dst] = false;
        }
        
    }

    void addEdgeWithCost(int src, int dst, int cost) {
        // TODO: BONUS 2
    }

    int edgeCost(int src, int dst) {
        // TODO: BONUS 2
        return 0;
    }

    std::vector<int> getNeighbors(int node) {
        
        std::vector <int> neighbour = adjacency_matrix[node];
        return neighbour;
    }


    int getSize() {
        return size;
    }
};

#endif // __MATRIXGRAPH_H__
