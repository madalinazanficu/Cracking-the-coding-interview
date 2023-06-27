#include <iostream>
#include <vector>
#include <string>
#include "/home/madalina/cracking/graphs/lab-graphs/ListGraph.h"


void DFS_for_topo(ListGraph &graph, std::vector <int> &visited, std::vector <int> &order, int node) {

    visited[node] = 2;
    std::vector <int> neighbors = graph.getNeighbors(node);
    for(int &neighbor : neighbors) {
        if (visited[neighbor] == 2) {
            std::cout << "cycle\n";
            return;
        }

        if (visited[neighbor] == 0) {
            DFS_for_topo(graph, visited, order, neighbor);
            visited[neighbor] = 1;
        }
    }
    order.push_back(node);
    visited[node] = 1;


}


std::vector <int> build_order(ListGraph &graph) {

    std::vector <int> order;

    // 0 - nevizitat 1 - vizitat  2 - in progress
    std::vector <int> visited(graph.getSize());
    for (int i = 1; i <= graph.getSize(); ++i) {
        if (visited[i] == 0) {
            DFS_for_topo(graph, visited, order, i);
        }

    }
    return order;

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

    std::vector <int> result = build_order(graph);
    if (result.size() != n) {
        std::cout << "Not possible!\n";
    }
    for (int i = result.size() - 1; i >= 0; i--) {
        std::cout << result[i] << ' ';
    }
    std::cout << '\n';
    return 0;
}