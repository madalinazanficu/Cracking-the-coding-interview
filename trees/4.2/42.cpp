#include <iostream>
#include <vector>
#include "minimal_tree_node.h"
#define NMAX 1001

MinimalTreeNode <int> *create_minimal_tree(int array[NMAX], int left, int right) {

    if (left > right) {
        return nullptr;
    }
    int m = (left + right) / 2;
    int middle = array[m];

    MinimalTreeNode <int> *node = new MinimalTreeNode <int> (middle);

    node->setLeftChild(create_minimal_tree(array, left, m - 1));
    node->setRightChild(create_minimal_tree(array, m + 1, right));

    return node;
}

int main() {

    int n;
    std::cin >> n;

    // array should be sorted
    int array[NMAX];
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }
    MinimalTreeNode <int> *root = create_minimal_tree(array, 0, n - 1);
    std::vector <int> trav = root->traversal(root);

    for (int i = 0; i < trav.size(); ++i) {
        std::cout << trav[i] << " ";
    }
    std::cout << std::endl;

    root->free_memory(root);

    return 0;
}