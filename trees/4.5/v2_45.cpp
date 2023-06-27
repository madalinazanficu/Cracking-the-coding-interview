#include <iostream>
#include "/home/madalina/cracking/trees/lab-binary-tree/BinaryTree.h"
// check if a binary tree is a binary search tree 
// => inorder traversal => left ROOT right



bool check_BST(BinaryTreeNode <int> *root, int &prev) {

    if (root == nullptr) {
        return true;
    }
    bool left = check_BST(root->getLeftChild(), prev);
    if (left == false) {
        return false;
    }
    // check is prev < the current
    if (prev != -1 && root->getData() < prev) {
        return false;
    }
    prev = root->getData();
    
    bool right = check_BST(root->getRightChild(), prev);
    if (right == false) {
        return false;
    }
    return true;

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

    int prev = -1;
    std::cout << "Is this a binary search tree? " << check_BST(bt.getRoot(), prev) << '\n';
    return 0;
}