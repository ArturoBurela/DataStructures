/*
Class implementation for a self balancing tree
Arturo Burela A01019906
*/

#ifndef AVL_TREE
#define AVL_TREE


#include "BinarySearchTree.h"

template <class T>
class AVLTree : public BinarySearchTree<T> {
    private:
      //Method for overload the Insertion
      TreeNode<T> * insert(TreeNode<T> * _root, TreeNode<T> * new_node);
      //Methods for rebalancing the TreeN
      int getBalanceFactor(TreeNode<T> * _root);
      void updateHeight(TreeNode<T> * _root);
      TreeNode<T> * balance(TreeNode<T> * _root);
      TreeNode<T> * rotateLeft(TreeNode<T> * _root);
      TreeNode<T> * rotateRight(TreeNode<T> * _root);
    public:
        AVLTree(){}
        AVLTree(TreeNode<T> * node){ this->root = node;}
        //Method to overload the Insertion
        void insert(TreeNode<T> * new_node);
};

#endif
