#include <iostream>
#include "ListGraph.h"
#include <queue>
// topo sort
// O(n + d) time n = number of nodes, d = number of dependecy pairs



void add_non_dependent(ListGraph &graph, std::vector <int> &order) {

    for(int i = 1; i <= graph.getSize(); ++i) {
        if (graph.chech_depend(i) == false) {
            order.push_back(i);
        }
    }
}

std::vector <int> buildOrder(ListGraph &graph) {

    std::vector <int> order;
    add_non_dependent(graph, order);

    int i = 0;
    while (i < order.size()) {

        // take every node children from order
        std::vector <int> neighbors = graph.getNeighbors(order[i]);
        for (int &nei : neighbors) {

            // remove the edges
            graph.removeEdge(order[i], nei);
            if (graph.chech_depend(nei) == false) {
                order.push_back(nei);
            }
        }
        i++;
    }
    return order;
}

bool check_cycle(ListGraph &graph) {

    for(int i = 1; i <= graph.getSize(); ++i) {
        if (graph.chech_depend(i) == true) {
            return false;
        }
    }
    return true;
}


int main() {

    int n, m;
    std::cin >> n >> m;
    ListGraph graph(n);

    for (int i = 0; i < m; i++) {
        int src, dst;
        std::cin >> src >> dst;
        graph.addEdge(src, dst);
    }

    std::cout << "Dependencies in graph\n";
    for (int i = 1; i <= graph.getSize(); i++) {
        std:: cout << "i= " << i << "\n";
        std::vector <int> nei = graph.getNeighbors(i);
        for (int i = 0; i < nei.size(); ++i) {
            std::cout << nei[i] << " -> ";
            graph.print_depend(nei[i]);
            std::cout << '\n';
        }
        std::cout << '\n';
    }

    std::cout << "Build order:\n";

    std::vector <int> result = buildOrder(graph);
    if (check_cycle(graph) == false) {
        std::cout << "error\n";
        return 0;
    }

    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << '\n';

    return 0;
}