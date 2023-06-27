#include <iostream>
#include "/home/madalina/cracking/trees/lab-binary-tree/BinaryTree.h"
#define MIN -10000
#define MAX 10000

// check if a binary tree is a binary search tree
// O (n) time && O (h) space for recursive calls, h = height of the tree


bool check_BST(BinaryTreeNode <int> *current, int min, int max)
{
    // the leaf subtree is "balanced"
    if (current == nullptr) {
        return true;
    }

    // if I have max parameter => I am on the left subtree
    if (current->getData() > max && max != MAX) {
        return false;
    }

     // if I have min parameter => I am on the right subtree
    if (current->getData() < min && min != MIN) {
        return false;
    }

    bool left = check_BST(current->getLeftChild(), MIN, current->getData());
    bool right = check_BST(current->getRightChild(), current->getData(), MAX);

    if (left == false || right == false) {
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

    std::cout << "Is this a binary search tree? " << check_BST(bt.getRoot(), MIN, MAX) << '\n';
    return 0;
}