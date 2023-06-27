#include <iostream>
#include "/home/madalina/cracking/trees/lab-binary-tree/BinaryTree.h"
#include <list>
#include <vector>


void weaveLists(std::list<int> &first, std::list<int> &last, std::list<int> &prefix, std::vector<std::list<int>> &weaved) {

	if (first.empty() || last.empty()) {
		std::list<int> result;
		
		// copy what we already had into result
		for (int &it : prefix) {
			result.push_back(it);
		}

		// copy the list which is not empty in result
		for (int &it : first) {
			result.push_back(it);
		}

		for(int &it : last) {
			result.push_back(it);
		}
		weaved.push_back(result);
		return;
	}
	// set the head of the first list as the start
	int headFirst = first.front();
	first.pop_front();
	prefix.push_back(headFirst);

	// recursive call for the remaining elements
	weaveLists(first, last, prefix, weaved);

	// remove the start element from prefix
	prefix.pop_back();

	// put the first element back => to keep the linked list the same
	first.push_front(headFirst);

	// same for the last list
	int headLast = last.front();
	last.pop_front();
	prefix.push_back(headLast);
	weaveLists(first, last, prefix, weaved);
	prefix.pop_back();
	last.push_front(headLast);
}


std::vector<std::list<int>> allSeq(BinaryTreeNode <int> *node) {

	// the result vector of sequences
	std::vector<std::list<int>> result;

	// we reach the end
	if (node == nullptr) {

		// add a new list to the result
		result.push_back(std::list <int>());
		return result;
	}
	std::list <int> prefix;
	prefix.push_back(node->getData());

	// going on right and left => recursively
	std::vector<std::list<int>> leftSeq = allSeq(node->getLeftChild());
	std::vector<std::list<int>> rightSeq = allSeq(node->getRightChild());

	// combine the left and right sequences
	for (std::list<int> &left : leftSeq) {
		for (std::list <int> &right :rightSeq) {

			std::vector<std::list<int>> weaved;
			weaveLists(left, right, prefix, weaved);
			
			// the final result => every list weaved
			for (std::list<int> &list : weaved) {
				result.push_back(list);
			}
		}
	}
	return result;
}


int main() {
    
    int n, x;
    BinaryTree<int> bt;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        bt.insert(x);
    }

    std::vector<std::list<int>> res = allSeq(bt.getRoot());

    for (std::list<int> &lst : res) {
        for (int &elem : lst) {
            std::cout << elem << " ";
        }
        std::cout<<std::endl;
    }

    return 0;

}