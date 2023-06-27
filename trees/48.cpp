#include <iostream>
#include "/home/madalina/cracking/trees/lab-binary-tree/BinaryTree.h"

BinaryTreeNode <int> * first_common_ancestor(BinaryTreeNode <int>* root, BinaryTreeNode <int> *curr, BinaryTreeNode <int> *node1, BinaryTreeNode <int> *node2) {

    if (root == nullptr) {
        return nullptr;
    }
    BinaryTreeNode <int> *left = first_common_ancestor(root->getLeftChild(), node1, node2);
    BinaryTreeNode <int> *right = first_common_ancestor(root->getRightChild(), node1, node2);

    // daca am ajuns inapoi in root, dupa recursivitate
    if (curr == root) {

        // nu am gasit nici pe stanga, nici pe dreapta
        if (left == nullptr && right == nullptr) {
            return nullptr;
        }

        // nu am gasit unul dintre noduri
        if ((left == node1 || left == node2) && right == nullptr) {
            return nullptr;
        }

        // nu am gasit unul dintre noduri
        if ((right == node1 || right == node2) && left == nullptr) {
            return nullptr;
        }


    }

    // cand se intoarce de pe recusrivitate, verifica daca am gasit vreun node
    if ((left == node1 && right == node2) ||(left == node2 && right == node1)) {
        return curr;
    }

    // cand un nod se afla deasupra celuilalt => el este first_common_ancestor
    if ((left == node1 && curr == node2) || (left == node2 && curr == node1)) {
        return curr;
    }
    if ((right == node1 && curr == node2)|| (right == node2 && curr == node1)) {
        return curr;
    }

    // daca am gasit unul din noduri 
    if (left == node1 || left == node2) {
        return left;
    }

    if(right == node1 || right == node2) {
        return right;
    }
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
    BinaryTreeNode<int> *node1 = bt.getRoot()->getLeftChild()->getRightChild(); // 8
    BinaryTreeNode<int> *node2 = bt.getRoot()->getRightChild()->getRightChild(); // 4

    BinaryTreeNode <int> *result = first_common_ancestor(bt.getRoot(), bt.getRoot(), node1, node2);
    std::cout << result->getData() << "\n";

    return 0;
}