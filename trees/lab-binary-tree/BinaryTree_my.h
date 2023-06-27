#ifndef __BINARYTREE_MY_H__
#define __BINARYTREE_MY_H__

#include <vector>


template <typename T>
class BinaryTreeNode {

    private:
        T data;
        BinaryTreeNode <T> *left;
        BinaryTreeNode <T> *right;
    
    public:

        // Constructor
        BinaryTreeNode(T data) {

            this->data = data;
            this->left = new BinaryTreeNode <T>;
            this->right = new BinaryTreeNode <T>;
        }

        // Destructor
        ~BinaryTreeNode() {
            delete left;
            delete right;
        }

        void setData(T data) {
            this->data = data;
        }

        T getData() {
            return this->data;
        }

        void setLeftChild(BinaryTreeNode node) {
            this->left = node;
        }

        BinaryTreeNode *getLeftChild() {
            return this->left;
        }

        void setRightChild(BinaryTreeNode node) {
            this->right = node;
        }
        BinaryTreeNode *getRightChild() {
            return this->right;
        }
};

template <typename T>
class BinaryTree() {

    private:
        int size;
        BinaryTreeNode <T> *root;

    public:

        // Constructor
        BinaryTree() {
            this->size = 0;
            this->root = new BinaryTreeNode <T>;

        }

};



#endif // __BINARYTREE_H__