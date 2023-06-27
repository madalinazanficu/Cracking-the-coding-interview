#include <iostream>
#include <string>
#include "/home/madalina/cracking/trees/lab-binary-tree/BinaryTree.h"
// O(m + n) time + space


// bool substring(std::string s1, std::string s2) {

//     int l1 = s1.length();
//     int l2 = s2.length();

//     int i, j, k = 0;
//     for (int i = 0; i < l1; ++i) {
//         if (s1[i] == s2[0]) {
//             for(int j = 0; j < l2; ++j) {
//                 if (s1[i + j] != s2[j]) {
//                     break;
//                 }
//                 k++;
//             }
//         }
//         if (j == l2 - 1) {
//             return true;
//         }
//     }
//     return false;
// }

// predorder => ROOT Left Right
void preorder(BinaryTreeNode <int> *curr, std::string &str) {
    
    if (curr == nullptr) {
        str.append("X");
        return;
    }
    str = str + std::to_string(curr->getData());
    preorder(curr->getLeftChild(), str);
    preorder(curr->getRightChild(), str);
    
}

bool subTree(BinaryTree <int> &bt, BinaryTree <int> &sub) {

    // preorder traversal, mark the nullptr as 'X'
    std::string tree;
    std::string subtree;

    preorder(bt.getRoot(), tree);
    preorder(sub.getRoot(), subtree);

    std::cout << tree << " " << subtree << "\n";

    // check if subtree is a substring of tree
    if (tree.find(subtree) != -1) {
        return true;
    }
    return false;
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
    std::cout << "Este subarbore: \n" << subTree(bt, sub) << '\n';

    return 0;
}