#include <iostream>
#include <queue>
#include "/home/madalina/cracking/graphs/lab-graphs/ListGraph.h"

bool find_path_BFS(int start, int finish, ListGraph listGraph) {

    std::queue <int> q;
    std::vector <int> visited(listGraph.getSize());

    // starting from start
    q.push(start);

    while(q.size() != 0) {

        int el = q.front();
        visited[el] = 1;
        q.pop();

        // list of neighbours
        std::vector <int> neighbours = listGraph.getNeighbors(el);

        for (unsigned int i = 0; i < neighbours.size(); ++i) {
            if (visited[neighbours[i]] == 0) {
                q.push(neighbours[i]);
                visited[neighbours[i]] = 1;
            }
            // finding the path
            if (neighbours[i] == finish) {
                return true;
            }
        }
    }
    return false;
}



int main() {

    int n, m, start, finish;
    std::cin >> n >> m;
    std::cin >> start >> finish;

    ListGraph graph(n);
    for (int i = 0; i < m; ++i) {

        int src, dst;
        std::cin >> src >> dst;
        graph.addEdge(src, dst);
    }

    std::cout << "Am gasit drum:" << find_path_BFS(start, finish, graph) << std::endl;
    

    return 0;
}