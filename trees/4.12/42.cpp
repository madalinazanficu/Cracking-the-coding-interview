#include <iostream>
#include "/home/madalina/cracking/trees/lab-binary-tree/BinaryTree.h"

// Brute force solution => total time O(n * log n)

// O(log n) time 
int pathsFromCurrent(BinaryTreeNode <int> *node, int targetSum, int currSum) {
	
	if (node == nullptr) {
		return 0;
	}
	currSum = currSum + node->getData();

	// for every node, consider we have 0 paths
	int total_paths = 0;

	// we find a path in which is the current node is included
	if (currSum == targetSum) {
		total_paths++;
	}
	// we continue to find paths from the current
	total_paths = total_paths + pathsFromCurrent(node->getLeftChild(), targetSum, currSum);
	total_paths = total_paths + pathsFromCurrent(node->getRightChild(), targetSum, currSum);

	return total_paths;
}

// recursive calls from all the nodes of the tree => O(N) time
int countPathsWithSum(BinaryTreeNode <int> *node, int targetSum) {

	if (node == nullptr) {
		return 0;
	}
	int paths = pathsFromCurrent(node, targetSum, 0);

	int pathsOnLeft = countPathsWithSum(node->getLeftChild(), targetSum);
	int pathsOnRight = countPathsWithSum(node->getRightChild(), targetSum);

	return paths + pathsOnLeft + pathsOnRight;
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