#include <iostream>
#include "/home/madalina/cracking/trees/lab-binary-tree/BinaryTree.h"


template <typename T>
class Result {

    private:
        BinaryTreeNode <T> *node;
        bool isAncestor;

    public:
        Result(BinaryTreeNode <T> *node, bool isAncestor) {
            node = node;
            isAncestor = isAncestor;
        }

        //getters
        BinaryTreeNode <T> *getNode() {
            return node;
        }

        bool getAncestor() {
            return isAncestor;
        }

};


Result <int> first_common_ancestor(BinaryTreeNode <int>* root, BinaryTreeNode <int> *curr, BinaryTreeNode <int> *node1, BinaryTreeNode <int> *node2) {

    if (curr == nullptr) {
        return Result <int> (nullptr, false);
    }
    Result <int> left = first_common_ancestor(root, curr->getLeftChild(), node1, node2);
    Result <int> right = first_common_ancestor(root, curr->getRightChild(), node1, node2);

    // cand am intorc in root, dupa toate apelurile recursive
    if (curr == root) {

        // nu am gasit nici pe stanga, nici pe dreapta
        if (left.getNode() == nullptr && right.getNode() == nullptr) {
            return Result <int> (nullptr, false);
        }

        // avem 2 cazuri :
        // 1. Daca unul dintre noduri se afla in subarobele celuilalt => isAncestor 1
        // 2. Daca intorcandu-ma pe recursivitate, unul din noduri a fost gasit si altul nu

        // Cazul 1
        if ((left.getNode() == node1 || left.getNode() == node2) && right.getNode() == nullptr) {
            if (left.getAncestor() == true) {
                return Result <int> (left.getNode(), false);
            }
        }

        if ((right.getNode() == node1 || right.getNode() == node2) && left.getNode() == nullptr) {
              if (right.getAncestor() == true) {
                return Result <int> (right.getNode(), false);
            }
        }
        // Cazul 2
        if (left.getNode() != nullptr && right.getNode() == nullptr) {
            return Result <int> (left.getNode(), false);
        }

        if (right.getNode() != nullptr && left.getNode() == nullptr) {
            return Result <int> (right.getNode(), false);
        }
        
    }

    // cand se intoarce de pe recusrivitate, verifica daca am gasit vreun node
    if ((left.getNode() == node1 && right.getNode() == node2) ||(left.getNode() == node2 && right.getNode() == node1)) {
        return Result <int> (curr, true);
    }

    // cand un nod se afla deasupra celuilalt => el este first_common_ancestor
    if ((left.getNode() == node1 && curr == node2) || (left.getNode() == node2 && curr == node1)) {
        return Result <int> (curr, true);
    }
    if ((right.getNode() == node1 && curr == node2)|| (right.getNode() == node2 && curr == node1)) {
        return Result <int> (curr, true);
    }

    // daca am gasit unul din noduri 
    if (left.getNode() == node1 || left.getNode() == node2) {
        return Result <int> (left.getNode(), false);
    }

    if(right.getNode() == node1 || right.getNode() == node2) {
        return Result <int> (right.getNode(), false);
    }
    return Result <int> (nullptr, false);
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
    BinaryTreeNode<int> *node2 = bt.getRoot()->getLeftChild()->getLeftChild(); // 6

    Result <int> result = first_common_ancestor(bt.getRoot(), bt.getRoot(), node1, node2);
    if (result.getNode() == nullptr) {
        std::cout << "Error\n";
        return 0;
    }
    std::cout << result.getNode()->getData() <<"\n";

    return 0;
}