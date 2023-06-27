#pragma once
#include <vector>

template <typename T>
class MinimalTreeNode {

    private:
        T data;
        MinimalTreeNode <T> *leftChild;
        MinimalTreeNode <T> *rightChild;
    
    public:

        // Constructor
        MinimalTreeNode(T data) {
            this->data = data;
            this->leftChild = nullptr;
            this->rightChild = nullptr;
        }

        // Destructor
        ~MinimalTreeNode() {
            this->leftChild = nullptr;
            this->rightChild = nullptr;
        }

        // getters
        T getData() {
            return this->data;
        }

        MinimalTreeNode <T> *getLeftChild() {
            return this->leftChild;
        }

        MinimalTreeNode <T> *getRightChild() {
            return this->rightChild;
        }

        // setters
        void setLeftChild(T data) {
            MinimalTreeNode <T> *newLeft = new MinimalTreeNode <T> (data);
            this->leftChild = newLeft;
        }

        void setRightChild(T data) {
            MinimalTreeNode <T> *newRight = new MinimalTreeNode <T> (data);
            this->rightChild = newRight;
        }


        // setters 2
        void setLeftChild(MinimalTreeNode <T> *newLeft) {
            this->leftChild = newLeft;

        }

        void setRightChild(MinimalTreeNode <T> *newRight) {
            this->rightChild = newRight;
        }

        // traversal
        void inorder(MinimalTreeNode <T> *nod, std::vector <T> &trav) {
            if (nod == nullptr) {
                return;
            }
            inorder(nod->getLeftChild(), trav);
            trav.push_back(nod->getData());
            inorder(nod->getRightChild(), trav);

        }
        std::vector <T> traversal(MinimalTreeNode <T> *root) {
            std::vector <T> trav;
            inorder(root, trav);
            return trav;
        }

        // free the Minimal_tree created 
        void free_memory(MinimalTreeNode *current) {

            // under a leaf
            if (current == nullptr) {
                return;
            }
            free_memory(current->getLeftChild());
            free_memory(current->getRightChild());

            delete current;
        }
};