#include <iostream>
#include <forward_list>
#include <vector>
#include "/home/madalina/cracking/trees/lab-binary-tree/BinaryTree.h"

// O(n + log n) time + complexity
// log n - recursive calls

void list_of_depths(BinaryTreeNode <int> *curr, std::vector<std::forward_list <BinaryTreeNode <int> *>> &result, int level) {

    if (curr == nullptr) {
        return;
    }
    
    // check if we need to create a new linked list
    if (result.size() == level) {

        std::forward_list <BinaryTreeNode <int> *> level_list;
        level_list.push_front(curr);
        result.push_back(level_list);
    } else {

        std::forward_list <BinaryTreeNode <int> *> *level_list = &(result.at(level));
        level_list->push_front(curr);
    }
    // Preorder => Root Left Right
    list_of_depths(curr->getLeftChild(), result, level + 1);
    list_of_depths(curr->getRightChild(), result, level + 1);

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
    std::vector<std::forward_list <BinaryTreeNode <int> *>> result;
    list_of_depths(bt.getRoot(), result, 0);

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