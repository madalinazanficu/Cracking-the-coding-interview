#include <iostream>
#include <forward_list>
#include <vector>
#include "/home/madalina/cracking/trees/lab-binary-tree/BinaryTree.h"

// O(n) time O(n) space to store the result
// modification of BFS algorithm
// return an array of linked list which contain BinaryTreeNode

std::vector <std::forward_list <BinaryTreeNode <int>*>> list_of_depths (BinaryTreeNode <int> *root) {

    std::vector <std::forward_list <BinaryTreeNode <int> *>> result;

    // the current list specific for the level
    std::forward_list <BinaryTreeNode <int> *> current_list;

    // check for the root
    if (root != nullptr) {
        current_list.push_front(root);
    }

    // taking all the BinaryTreeNodes from the previous list, and adding children into a new level_list
    while(current_list.empty() == false) {

        // adding the previous list in the result array of lists
        result.push_back(current_list);
        
        // making the older list being the parent list
        std::forward_list <BinaryTreeNode <int> *> parent_list;

        for (BinaryTreeNode <int> * &current : current_list) {
            if (current != nullptr) {
                parent_list.push_front(current);
            }
        }
        current_list.clear();

        for (auto &parent: parent_list) {
            // adding children in current_list
            if (parent->getLeftChild() != nullptr) {
                current_list.push_front(parent->getLeftChild());
            }
            if (parent->getRightChild() != nullptr) {
                current_list.push_front(parent->getRightChild());
            }
        }
    }
    return result;
}


int main() {

    int n;
    std::cin >> n;
    BinaryTree <int> bt;

    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        bt.insert(x);
    }

    std::vector <std::forward_list <BinaryTreeNode <int> *>> result = list_of_depths(bt.getRoot());
    std::cout << result.size() << std::endl;
    for (int i = 0; i < result.size(); ++i) {
        std::forward_list <BinaryTreeNode <int> *> current = result.at(i);
        std::forward_list <BinaryTreeNode <int> *> ::iterator it = current.begin();

        std::cout << "New level :\n";
        while(it != current.end()) {
            std::cout << (*it)->getData() << " ";
            it++;
        }
        std::cout << std::endl;
    }
    return 0;
}