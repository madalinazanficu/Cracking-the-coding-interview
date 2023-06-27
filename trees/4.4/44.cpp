#include <iostream>
#include "/home/madalina/cracking/trees/lab-binary-tree/BinaryTree.h"
// O (n log n) time

int get_heigh_r(BinaryTreeNode <int> *curr) {

    if (curr == nullptr) {
        return 0;
    }
    int h1 = get_heigh_r(curr->getLeftChild()) + 1;
    int h2 = get_heigh_r(curr->getRightChild()) + 1;

    if (h1 > h2) {
        return h1;
    } else {
        return h2;
    }
}

bool check_balance(BinaryTreeNode <int> *curr) {

    // zero children 
    if (curr == nullptr) {
        return true;
    }

   int diff_h = abs(get_heigh_r(curr->getRightChild()) - get_heigh_r(curr->getLeftChild()));
   if (diff_h > 1) {
       return 0; 
   } else {
        int left = check_balance(curr->getLeftChild());
        int right = check_balance(curr->getRightChild());
        return left && right;
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
    std::cout << "Inaltimea copacului:" <<  heigh << '\n';
    std::cout << "Arborele este balansat " << check_balance(bt.getRoot()) << '\n';


    return 0;
}