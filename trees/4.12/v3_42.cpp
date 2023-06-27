#include <iostream>
#include "/home/madalina/cracking/trees/lab-binary-tree/BinaryTree.h"
#include <map>

// O(n) time + O (log n) extra space for hashmap
// touch every node once = > O(N) + O(1) time for inserting in hashmap
int countPaths(BinaryTreeNode <int> *curr, int target, int runSum, std::map <int, int> Hashmap) {

    if (curr == nullptr) {
        return 0;
    }
    runSum = runSum + curr->getData();
    int diff = runSum - target;

    // searching for the difference in Hashmap, to make target possible
    int total_paths = Hashmap.count(diff);

    // we find a sum directly
    if (runSum == target) {
        total_paths++;
    }
    Hashmap.insert(std::pair<int, int>(runSum, 1));

    total_paths = total_paths + countPaths(curr->getLeftChild(), target, runSum, Hashmap);
    total_paths = total_paths + countPaths(curr->getRightChild(), target, runSum, Hashmap);

    Hashmap.erase(runSum);
    return total_paths;

}

int main() {
    
    	int n, target;
    	std::cin >> n >> target;
    	BinaryTree <int> bt;
        std::map <int, int> Hashmap;

    	for (int i = 0; i < n; i++) {
        	int x;
        	std::cin >> x;
        	bt.insert(x);
    	}
        int paths = countPaths(bt.getRoot(), target, 0, Hashmap);
	    std::cout << paths << '\n';
		
    	return 0;
}