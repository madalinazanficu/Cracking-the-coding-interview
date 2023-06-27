#include <iostream>
#include "/home/madalina/cracking/trees/lab-binary-tree/BinaryTree_parent.h"


BinaryTreeNode <int> *left_extremity(BinaryTreeNode <int> *curr) {

    while(curr->getLeftChild() != nullptr) {
        curr = curr->getLeftChild();
    }
    return curr;
}

BinaryTreeNode <int> *succesor(BinaryTreeNode <int> *curr) {

    // if we have  right subtree for the current node 
    // => we take the left extrmity node from the right subtree

    if (curr->getRightChild() != nullptr) {
       return left_extremity(curr->getRightChild());
    }

    // we need to go up, until we are not coming from the right
    BinaryTreeNode <int> *parent = curr->getParent();

    while(parent != nullptr && parent->getRightChild() == curr) {

        curr = parent;
        parent = parent->getParent();
    }
    return parent;
}


int main() {

    BinaryTree <int> bt;
    int n;

    std::cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        bt.insert(x);
    }

    // for testing
    BinaryTreeNode <int> *result = succesor(bt.getRoot()->getLeftChild()->getLeftChild());

    if (result == nullptr) {
        std::cout << "It was the last node from inorder!\n";
    } else {
        std::cout << result->getData() << '\n';
    }

    return 0;
}