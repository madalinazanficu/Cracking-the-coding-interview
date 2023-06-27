#include <iostream>
#include "/home/madalina/cracking/trees/lab-binary-tree/BinaryTree.h"
#define ERROR -3
// O (n) time
// O (h) space

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
int get_heigh_r(BinaryTreeNode <int> *curr) {

    if (curr == nullptr) {
        return 0;
    }
    int h1 = get_heigh_r(curr->getLeftChild());
    if (h1 == ERROR) {
        return ERROR;
    }
    int h2 = get_heigh_r(curr->getRightChild());
     if (h2 == ERROR) {
        return ERROR;
    }

    int diff = abs(h1 - h2);
    if (diff > 1) {
        return ERROR;
    } else {
        return max(h1, h2) + 1;
    }
}



int main() {

    int n;
    std::cin >> n;
    BinaryTree <int> bt;

    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        bt.insert_left(x);
    }

    int heigh = get_heigh_r(bt.getRoot());
    if (heigh == ERROR) {
        std::cout << "Not balanced!\n";
    } else {
        std::cout << "Inaltimea copacului:" <<  heigh << '\n';
    }
    


    return 0;
}