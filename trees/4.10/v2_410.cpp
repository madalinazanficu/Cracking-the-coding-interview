#include <iostream>
#include "/home/madalina/cracking/trees/lab-binary-tree/BinaryTree.h"


bool matchTree(BinaryTreeNode <int> *T1, BinaryTreeNode <int> *T2) {
    
    // nothing left in subtree
    if (T1 == nullptr && T2 == nullptr) {
        return true;
    } else {

        // only one tree reach the end
        if (T1 == nullptr || T2 == nullptr) {
            return false;
        }
        if (T1->getData() != T2->getData()) {
            return false;
        }
        // check for both left && right subtree
        int left = matchTree(T1->getLeftChild(), T2->getLeftChild());
        int right = matchTree(T1->getRightChild(), T2->getRightChild());
        return left && right;
        
    }
}

bool subTree(BinaryTreeNode <int> *T1, BinaryTreeNode <int> *T2) {

    // the bis tree is empty, and the subtree was not found
    if (T1 == nullptr) {
        return false;
    } else {

        if(T1->getData() == T2->getData() && matchTree(T1, T2) != false) {
            return true;
        }
        bool left = subTree(T1->getLeftChild(), T2);
        bool right = subTree(T1->getRightChild(), T2);
        return left || right;
    }
}


int main() {
    
    int n;
    std::cin >> n;
    BinaryTree <int> bt;
    BinaryTree <int> sub;

    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        bt.insert(x);
    }

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        sub.insert(x);
    }

    if (sub.getRoot() == nullptr) {
        std::cout << "Este subarbore!\n";
    } else{
        std::cout << "Este subarbore: \n" << subTree(bt.getRoot(), sub.getRoot()) << '\n';
    }
}