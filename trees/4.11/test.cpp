#include <iostream>
#include <string>
#include "BST.h"


int main() {

    int n, x;
    BST <int> bt;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        bt.insert(x);
    }

    std::vector <int> t = bt.traversal();
    for (int i = 0; i < n; i++) {
        std::cout << t[i] << " ";
    }
    std::cout << '\n';
    BSTNode <int> *random = bt.getRandom();
    std::cout << random->getData() << '\n';

    return 0;
}