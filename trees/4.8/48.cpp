#include <iostream>
#include "/home/mihnea_dnk/Desktop/cracking/4 - Trees/Lab8Skel/BinaryTree.h"

template <typename T>
class result {
private:
    BinaryTreeNode<T> *node;
    bool ok;

public:
    result(BinaryTreeNode<T> *node, bool ok) {
        this->node = node;
        this->ok = ok;
    }

    BinaryTreeNode<T> *getNode() {
        return this->node;
    }

    bool getOk() {
        return this->ok;
    }

    bool okay(BinaryTreeNode<T> *node) {
        if (this->node == node && ok)
            return true;
        if (this->node != node)
            return true;
        return false;
    }
};

result<int> LCA(BinaryTree<int> &bt, BinaryTreeNode<int> *node, BinaryTreeNode<int> *node1, BinaryTreeNode<int> *node2) {
    if (node == nullptr)
        return result<int>(nullptr, false);

    result<int> left = LCA(bt, node->getLeftChild(), node1, node2);
    result<int> right = LCA(bt, node->getRightChild(), node1, node2);

    if (node == bt.getRoot()) {
        if (left.getNode() == nullptr && right.getNode() == nullptr)
            return result<int>(nullptr, false);

        if ((left.getNode() == node1 && right.getNode() == node2) || (left.getNode() == node2 && right.getNode() == node1))
            return result<int>(node, false);
        
        if (left.getNode() != nullptr && (left.okay(node1) || left.okay(node2)))
            return result<int>(left.getNode(), false);

        if (right.getNode() != nullptr && (right.okay(node1) || right.okay(node2)))
            return result<int>(right.getNode(), false);

        return result<int>(nullptr, false);
    }

    if (node == node1 || node == node2)
        return result<int>(node, false);

    if ((left.getNode() == node1 && right.getNode() == node2) || (left.getNode() == node2 && right.getNode() == node1))
        return result<int>(node, false);

    if (((left.getNode() == node1 || right.getNode() == node1) && node == node2) || ((left.getNode() == node2 || right.getNode() == node2) && node == node1))
        return result<int>(node, true);

    if (left.getNode() == node1 || right.getNode() == node1)
        return result<int>(node1, false);
    
    if (left.getNode() == node2 || right.getNode() == node2)
        return result<int>(node2, false);
    
    return result<int>(nullptr, false);
}

int main() {

    int n, x;
    BinaryTree<int> bt;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        bt.insert(x);
    }

    BinaryTreeNode<int> *node1 = bt.getRoot()->getLeftChild()->getLeftChild()->getRightChild(); // 7
    BinaryTreeNode<int> *node2 = bt.getRoot()->getLeftChild()->getLeftChild(); // 6
    result<int> res = LCA(bt, bt.getRoot(), node1, node2);

    if (res.getNode() == nullptr)
        std::cout << "No LCA\n";
    else
        std::cout << res.getNode()->getData() << '\n';

    return 0;
}