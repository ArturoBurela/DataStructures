/*
Arturo Burela
A01019906

Template class for a binary search tree, adapted to print in PostOrder
*/

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <iomanip>
#include "TreeNode.h"
#include "Stack.h"

#define INCREMENT 5

template <class T>
class BinarySearchTree {
    private:
        TreeNode<T> * root = nullptr;
        //variable to identify if we have reached te endo of the operators
        bool end = false;
        // Recursive methods, that take the root of the subtree
        void clear(TreeNode<T> * _root);
        void insert(TreeNode<T> * _root, TreeNode<T> * new_node);
        void printInOrder(TreeNode<T> * _root);
        void printTree(TreeNode<T> * _root, int indent, char icon);
        //Print in PostOrder
        void printPostOrder(TreeNode<T> * _root);

    public:
        BinarySearchTree () {}
        BinarySearchTree (TreeNode<T> * node) { root = node; }
        ~BinarySearchTree () { clear(); }
        void clear();
        TreeNode<T> * getRoot() { return root; }
        void setRoot(TreeNode<T> * _root) { root = _root; }
        void insert(T data);
        void insert(TreeNode<T> * new_node);
        //Added special insert methods to store postfix without binary search restrictions
        void insertPostFix(T data);
        void insertPostFix(TreeNode<T> * new_node);
        void printInOrder() { printInOrder(root); }
        void printTree() { printTree(root, INCREMENT, '-'); }
        void printPostOrder();
};

// Public method to delete all the nodes in the tree
template <class T>
void BinarySearchTree<T>::clear ()
{
    clear(root);
}

// Private method to delete all the nodes in the subtree specified
template <class T>
void BinarySearchTree<T>::clear (TreeNode<T> * _root)
{
    if (_root == nullptr)
        return;
    clear(_root->getLeft());
    clear(_root->getRight());
    delete _root;
}

// Public insertion method that gets the data
template <class T>
void BinarySearchTree<T>::insert(T data)
{
    TreeNode<T> * new_node = new TreeNode<T>(data);
    insert(new_node);
}

// Public insertion method that gets a tree node
template <class T>
void BinarySearchTree<T>::insert(TreeNode<T> * new_node)
{
    // Empty tree
    if (root == nullptr)
        root = new_node;
    else
        insert(root, new_node);
}

template <class T>
void BinarySearchTree<T>::printInOrder(TreeNode<T> * _root)
{
    if (_root != nullptr)
    {
        printInOrder(_root->getLeft());
        std::cout << " " << _root->getData() << " ";
        printInOrder(_root->getRight());
    }
}

template <class T>
void BinarySearchTree<T>::printTree(TreeNode<T> * _root, int indent, char icon)
{
    if (_root != nullptr)
    {
        printTree(_root->getRight(), indent+INCREMENT, '/');
        std::cout << std::setw(indent) << " " << icon << "- " << _root->getData() << std::endl;
        printTree(_root->getLeft(), indent+INCREMENT, '\\');
    }
}

//Aux method to print from outside
template <class T>
void BinarySearchTree<T>::printPostOrder() {
  printPostOrder(root);
}

//Print the tree in PostOrder
template <class T>
void BinarySearchTree<T>::printPostOrder(TreeNode<T> * _root){
  if (_root != nullptr)
  {
    //Call the left branch
    printPostOrder(_root->getLeft());
    //Call the right branch
    printPostOrder(_root->getRight());
    //after all the calls are made return and print the value
    std::cout << " " << _root->getData() << " ";
  }
}

#endif
