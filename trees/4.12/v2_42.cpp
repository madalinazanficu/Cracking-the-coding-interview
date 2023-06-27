#include <iostream>
#include "/home/madalina/cracking/trees/lab-binary-tree/BinaryTree.h"

// Brute force solution => total time O(n * log n)

// O(log n) time 
void pathsFromCurrent(BinaryTreeNode <int> *node, int targetSum, int currSum, int total_paths) {
	
	if (node == nullptr) {
		return;
	}
	currSum = currSum + node->getData();
	if (currSum == targetSum) {
		total_paths++;
	}
	pathsFromCurrent(node->getLeftChild(), targetSum, currSum, total_paths);
	pathsFromCurrent(node->getRightChild(), targetSum, currSum, total_paths);
}

// recursive calls from all the nodes of the tree => O(N) time
int countPathsWithSum(BinaryTreeNode <int> *node, int targetSum) {

	if (node == nullptr) {
		return 0;
	}
    int total_paths = 0;
	pathsFromCurrent(node, targetSum, 0, total_paths);
    std::cout << total_paths;

	int pathsOnLeft = countPathsWithSum(node->getLeftChild(), targetSum);
	int pathsOnRight = countPathsWithSum(node->getRightChild(), targetSum);

	return total_paths + pathsOnLeft + pathsOnRight;
}

int main() {
    
    	int n, target;
    	std::cin >> n >> target;
    	BinaryTree <int> bt;

    	for (int i = 0; i < n; i++) {
        	int x;
        	std::cin >> x;
        	bt.insert(x);
    	}
	int paths = countPathsWithSum(bt.getRoot(), target);
	std::cout << paths << '\n';
    	return 0;
}