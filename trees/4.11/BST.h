#pragma once
#include <vector>

template <typename T>
class BSTNode {

    private:
        T data;
        BSTNode <T> *leftChild;
        BSTNode <T> *rightChild;
        int size = 0;
    
    public:

        // Constructor
        BSTNode(T data) {
            this->leftChild = nullptr;
            this->rightChild = nullptr;
            this->data = data;
            this->size = 1;
        }

        // Destructor
        ~BSTNode() {
            this->leftChild = nullptr;
            this->rightChild = nullptr;
        }

        // getters
        int getSize() {
            return size;
        }
        
        T getData() {
            return data;
        }

        BSTNode *getLeftChild() {
            return leftChild;
        }

        BSTNode *getRightChild() {
            return rightChild;
        }

        // setters
        void setLeftChild(T data) {
            BSTNode <T> *add =  new BSTNode <T> (data);
            this->leftChild = add;
        }

        void setRightChild(T data) {
            BSTNode <T> *add =  new BSTNode <T> (data);
            this->rightChild =  add;
        }
        void increaseSize() {
            size++;
        }

};


template <typename T>
class BST {

    private:
        BSTNode <T> *root;
        int size;
    
    public:
        // Constructor
        BST() {
            root = nullptr;
            size = 0;
        }

        // Destructor
        ~BST() {
            deletetree(root);
            root = nullptr;
        }

        void insert(T d) {

            // search for his place
            if (root == nullptr) {
                BSTNode <T> *add = new BSTNode <T> (d);
                root = add;
                size++;
                return;
            }

            BSTNode <T> *start = root;
            while(start != nullptr) {
                start->increaseSize();

                if (d <= start->getData()) {
                    if (start->getLeftChild() == nullptr) {
                        start->setLeftChild(d);
                        break;

                    } else {
                        start = start->getLeftChild();
                    }

                } else {
                    if (start->getRightChild() == nullptr) {
                        start->setRightChild(d);
                        break;
                    } else {
                        start = start->getRightChild();
                    }
                }
            }
            size++;
        }

        bool find(T d) {
   
            BSTNode <T> *start = root;
            while(start != nullptr) {
                if (start->getData() == d) {
                    return true;
                }
                if (d < start->getDara()) {
                    start = start->getLeftChild();
                } else {
                    start = start->getRightChild();
                }
            }
            return false;
        }
        
        void inorder(BSTNode<T> *nod, std::vector<T> &trav) {
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

        void deletetree(BSTNode<T> *nod) {
            if (nod == nullptr)
                return;
            
            deletetree(nod->getLeftChild());
            deletetree(nod->getRightChild());
            
            delete nod;
            nod = nullptr;
	    }

        BSTNode <T> *getIthNode (int index, BSTNode <T> *curr) {
            int leftSize = 0;
            if (curr->getLeftChild() != nullptr) {
                leftSize = curr->getLeftChild()->getSize();
            }
            if (index < leftSize) {
                return getIthNode(index, curr->getLeftChild());
            } else {
                if (index == leftSize) {
                    return curr;
                }
                return getIthNode(index - leftSize - 1, curr->getRightChild());
            }
        }


        BSTNode <T> *getRandom() {
             if (root == nullptr) {
                return nullptr;
            }

            // generate the random => assign for r, numbers between 0, size
            // take system time
            unsigned seed = time(0);
            srand(seed);
            int r = std::rand() % size;
            return getIthNode(r, root);
        }

};
