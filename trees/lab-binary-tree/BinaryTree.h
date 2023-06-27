#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#include <vector>
#include <queue>

template <typename T>
class BinaryTreeNode {
private:
	T data;
	BinaryTreeNode<T> *leftChild;
	BinaryTreeNode<T> *rightChild;

public:
	BinaryTreeNode(T data) {
		this->data = data;
		this->leftChild = nullptr;
		this->rightChild = nullptr;
	}

	~BinaryTreeNode() {
		this->leftChild = nullptr;
		this->rightChild = nullptr;
	}

	void setData(T data) {
		this->data = data;
	}

	T getData() {
		return this->data;
	}

	// setters 1
	void setLeftChild(BinaryTreeNode *newLeft){
		this->leftChild = newLeft;
	}

	void setRightChild(BinaryTreeNode *newRight) {
		this->rightChild = newRight;
	}

	// setters 2
	void setLeftChild(T data) {
		BinaryTreeNode <T> *newLeft = new BinaryTreeNode <T> (data);
	}

	void setRightChild(T data) {
		BinaryTreeNode <T> *newRight = new BinaryTreeNode <T> (data);
	}


	// setters 3
	void setLeftChild(BinaryTreeNode node) {
		this->leftChild = new BinaryTreeNode(node.getData());
	}


	void setRightChild(BinaryTreeNode node) {
		this->rightChild = new BinaryTreeNode(node.getData());
	}

	// getters
	BinaryTreeNode* getLeftChild() {
		return this->leftChild;
	}

	BinaryTreeNode* getRightChild() {
		return this->rightChild;
	}
};

template <typename T>
class BinaryTree {
private:
	int size;
	BinaryTreeNode<T> *root;
public:
	BinaryTree() {
		this->root = nullptr;
		this->size = 0;
	}

	~BinaryTree() {
		deletetree(this->root);
		this->root = nullptr;
	}

	void insert(T data) {
		BinaryTreeNode<T> *add = new BinaryTreeNode<T> (data);

		if (root == nullptr) {
			root = add;
			size++;
			return;
		}

		std::queue<BinaryTreeNode<T>*> q;
		q.push(root);
		while (q.size() != 0) {
			BinaryTreeNode<T> *cur = q.front();
			q.pop();

			if (cur->getLeftChild() == nullptr) {
				cur->setLeftChild(*add);
				delete add;
				while (q.size() != 0)
					q.pop();
			} else {

				
				q.push(cur->getLeftChild());
				if (cur->getRightChild() == nullptr) {
					cur->setRightChild(*add);
					delete add;
					while (q.size() != 0)
						q.pop();
				} else {
					q.push(cur->getRightChild());
				}
			}
		}
		size++;
	}

	void insert_left(T data) {
		BinaryTreeNode<T> *add = new BinaryTreeNode<T> (data);
		if (root == nullptr) {
			root = add;
			size++;
			return;
		}

		BinaryTreeNode <T> *curr = root;
		while(curr->getLeftChild() != nullptr) {
			curr = curr->getLeftChild();
		}
		curr->setLeftChild(add);
		size++;
	}

	void deletetree(BinaryTreeNode<T> *nod) {
		if (nod == nullptr)
			return;
		
		deletetree(nod->getLeftChild());
		deletetree(nod->getRightChild());
		
		delete nod;
		nod = nullptr;
	}

	void inorder(BinaryTreeNode<T> *nod, std::vector<T> &trav) {
		if (nod == nullptr)
			return;
		inorder(nod->getLeftChild(), trav);
		trav.push_back(nod->getData());
		inorder(nod->getRightChild(), trav);
	}

	std::vector<T> traversal() {
		std::vector<T> trav;
		inorder(root, trav);
		return trav;
	}

	BinaryTreeNode<T>* getRoot() {
		return this->root;
	}
};

#endif // __BINARYTREE_H__