#include <iostream>
#include "BinaryTree.h"

template <typename T>
int rec_height(BinaryTreeNode<T> *nod) {
	if (nod == nullptr)
		return 0;
	
	int left = rec_height(nod->getLeftChild());
	int right = rec_height(nod->getRightChild());

	int maxx = 1;
	if (left < right)
		maxx += right;
	else
		maxx += left;

	return maxx;

	// maxx += left < right ? 0 : 1;
}

template <typename T>
int computeTreeHeight(BinaryTree<T> &bt) {
	int h = rec_height(bt.getRoot());
	return h;
}

int main() {

    BinaryTree<int> bt;

    for (int i = 0; i < 10; ++i) {
		bt.insert(i);
	}

    std::vector<int> trav = bt.traversal();

    for (int i = 0; i < trav.size(); i++)
        std::cout << trav[i] << " | ";

    int height = computeTreeHeight(bt);
	std::cout << "\n" << height << '\n';

    return 0;
}