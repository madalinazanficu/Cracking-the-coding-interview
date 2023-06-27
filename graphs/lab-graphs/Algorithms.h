
#ifndef __ALGORITHMS_H__
#define __ALGORITHMS_H__

#include <vector>
#include <queue>

#include "ListGraph.h"
#include "MatrixGraph.h"

class Algorithms {
public:
    
    // return a vector containing indexes of the nodes, visited using BFS.
    static std::vector<int> BFS(MatrixGraph matrixGraph) {
        
        std::queue <int> q;
        std::vector <int> order;

        std::vector <int> visited(matrixGraph.getSize());

        // starting from 0
        q.push(0);

        while(q.size() != 0) {
            
            int el = q.front();
            visited[el] = 1;
            order.push_back(el);
            q.pop();


            // list of neighbours
            std::vector <int> neighbours = matrixGraph.getNeighbors(el);
            for (unsigned int i = 0; i < neighbours.size(); ++i) {
                if (visited[neighbours[i]] == 0) {
                    q.push(neighbours[i]);
                    neighbours[i] = 1;
                }
            }
        }

        return order;
    }


    // return a vector containing indexes of the nodes, visited using BFS.
    static std::vector<int> BFS(ListGraph listGraph) {

        std::queue <int> q;
        std::vector <int> order;

        std::vector <int> visited(listGraph.getSize());

        // starting from 0
        q.push(0);

        while(q.size() != 0) {

            int el = q.front();
            visited[el] = 1;
            order.push_back(el);
            q.pop();

            // list of neighbours
            std::vector <int> neighbours = listGraph.getNeighbors(el);

            for (unsigned int i = 0; i < neighbours.size(); ++i) {
                if (visited[neighbours[i]] == 0) {
                    q.push(neighbours[i]);
                    visited[neighbours[i]] = 1;
                }
            }
            
        }

        return order;
    }

    // for ListGraph
    static void DFS_rec1(int node, std::vector <int> &visited, ListGraph &listGraph, std::vector <int> &order) {

        visited[node] = 1;
        order.push_back(node);
        std::vector <int> neighbors = listGraph.getNeighbors(node);
        for (unsigned int i = 0; i < neighbors.size(); ++i) {
            if (visited[neighbors[i]] == 0) {
                visited[neighbors[i]] = 1;
                DFS_rec1(neighbors[i], visited, listGraph, order);
            }
        }
    }

    // for MatrixGraph
    static void DFS_rec2(int node, std::vector <int> &visited, MatrixGraph &matrixGraph, std::vector <int> &order) {

        visited[node] = 1;
        order.push_back(node);
        std::vector <int> neighbors = matrixGraph.getNeighbors(node);

        for(int i = neighbors.size() - 1; i >= 0; i--) {
            if (visited[i] == 0 && matrixGraph.hasEdge(node, i) == 1) {
                DFS_rec2(i, visited, matrixGraph, order);
            }
        }
    }

    static std::vector<int> DFS(MatrixGraph matrixGraph) {
        
        std::vector <int> order;
        std::vector <int> visited(matrixGraph.getSize());
        DFS_rec2(0, visited, matrixGraph, order);
        return order;
    }


    static std::vector<int> DFS(ListGraph listGraph) {

        std::vector <int> order;
        std::vector <int> visited(listGraph.getSize());
        DFS_rec1(0, visited, listGraph, order);
        return order;
    }


    // direct recursive DFS
    static void rDFS(ListGraph& listGraph, std::vector<bool>& visited, std::vector<int>& nodeList, int node) {

        visited[node] = 1;
        nodeList.push_back(node);
        std::vector <int> neighbors = listGraph.getNeighbors(node);
        for (unsigned int i = 0; i < neighbors.size(); ++i) {
            if (visited[neighbors[i]] == 0) {
                visited[neighbors[i]] = 1;
                rDFS(listGraph, visited, nodeList, neighbors[i]);
            }
        }

    }

    /**
     * Applies Floyd-Warshall on the given graph.
     *
     * @param matrixGraph Matrix representation of a graph.
     * @return A matrix where A[i][j] contains the shortest path from node i to node j.
     */
    static std::vector<std::vector<int>> Floyd_Warshall(MatrixGraph matrixGraph) {
        // TODO: BONUS 2
        return std::vector<std::vector<int>>();
    }

    /**
     * Applies Kruskal on the given graph.
     *
     * @param matrixGraph Matrix representation of a graph.
     * @return A vector of edges (described by the two adjacent nodes) which compose the minimum spanning tree.
     */
    static std::vector<std::pair<int, int>> Kruskal(MatrixGraph matrixGraph) {
        // TODO: BONUS 3
        return std::vector<std::pair<int, int>>();
    }
};

#endif // __ALGORITHMS_H__
