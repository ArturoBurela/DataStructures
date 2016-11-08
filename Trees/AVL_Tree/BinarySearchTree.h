/*
    Class template for a Binary Search Tree
    
    Gilberto Echeverria
    gilecheverria@yahoo.com
    19/10/2016
*/

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <iomanip>
#include "TreeNode.h"

#define INCREMENT 5

template <class T>
class BinarySearchTree {
    private:
        TreeNode<T> * root = nullptr;

        // Recursive methods, that take the root of the subtree
        void clear(TreeNode<T> * _root);
        void insert(TreeNode<T> * _root, TreeNode<T> * new_node);
        bool search(TreeNode<T> * _root, T data);
        TreeNode<T> * remove(TreeNode<T> * _root, T data);
        TreeNode<T> * getMin(TreeNode<T> * _root);
        void printInOrder(TreeNode<T> * _root);
        void printTree(TreeNode<T> * _root, int indent, char branch);
        
    public:
        BinarySearchTree () {}
        BinarySearchTree (TreeNode<T> * node) { root = node; }
        ~BinarySearchTree () { clear(); }
        void clear();
        TreeNode<T> * getRoot() { return root; }
        void setRoot(TreeNode<T> * _root) { root = _root; }
        void insert(T data);
        void insert(TreeNode<T> * new_node);
        bool search(T data) { return search(root, data); }
        void remove(T data) { root = remove(root, data); }
        TreeNode<T> * getMin() { return getMin(root); }
        int countLeaves();
        void printInOrder() { printInOrder(root); }
        void printTree() { printTree(root, INCREMENT, '-'); }
};

// Public method to delete all the nodes in the tree
template <class T>
void BinarySearchTree<T>::clear ()
{
    clear(root);
    // Indicate that this is an empty tree
    root = nullptr;
}

// Private method to delete all the nodes in the subtree specified
template <class T>
void BinarySearchTree<T>::clear (TreeNode<T> * _root)
{
    if (_root == nullptr)
        return;
    // Clear the subtrees free
    clear(_root->getLeft());
    clear(_root->getRight());
    // Free the memory for this node
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

// Private insertion method that gets the root of the subtree
//  to insert, and the new tree node
template <class T>
void BinarySearchTree<T>::insert(TreeNode<T> * _root, TreeNode<T> * new_node)
{
    // Check the subtree where the data must be inserted
    if (new_node->getData() < _root->getData())
    {
        // Insert in the next empty branch
        if (_root->getLeft() == nullptr)
            _root->setLeft(new_node);
        else
            insert(_root->getLeft(), new_node);
    }
    else if (new_node->getData() > _root->getData())
    {
        // Insert in the next empty branch
        if (_root->getRight() == nullptr)
            _root->setRight(new_node);
        else
            insert(_root->getRight(), new_node);
    }
    else
        return; // Do not insert duplicated data
}

template <class T>
bool BinarySearchTree<T>::search(TreeNode<T> * _root, T data)
{
    // The data is not found in an empty tree
    if (_root == nullptr)
        return false;
    // Look in the left subtree
    else if (data < _root->getData())
        return search(_root->getLeft(), data);
    // Look in the right subtree
    else if (data > _root->getData())
        return search(_root->getRight(), data);
    // The data has been found
    else
        return true;
}

template <class T>
TreeNode<T> * BinarySearchTree<T>::remove(TreeNode<T> * _root, T data)
{
    if (!_root)
    //if (_root == nullptr)
        return nullptr;
    else if (data < _root->getData())
    {
        _root->setLeft( remove(_root->getLeft(), data) );
        // This node did not change
        return _root;
    }
    else if (data > _root->getData())
    {
        _root->setRight( remove(_root->getRight(), data) );
        // This node did not change
        return _root;
    }
    // This is the node with the data to delete
    else
    {
        // Case 1: Leaf node
        if (!_root->getLeft() && !_root->getRight())
        {
            delete _root;
            return nullptr;
        }
        // Case 2: Only left child
        else if (!_root->getRight())
        {
            TreeNode<T> * tmp_node = _root->getLeft();
            delete _root;
            return tmp_node;
        }
        // Case 3: Only right child
        else if (!_root->getLeft())
        {
            TreeNode<T> * tmp_node = _root->getRight();
            delete _root;
            return tmp_node;
        }
        // Case 4: Both children
        else
        {
            // Get the node with the smallest value on the right
            TreeNode<T> * tmp_node = getMin(_root->getRight());
            // Change the value in the current node
            _root->setData( tmp_node->getData() );
            // Delete the smallest data from the right subtree
            _root->setRight( remove(_root->getRight(), tmp_node->getData()) );
            // This node did not change
            return _root;
        }
    }
}

template <class T>
TreeNode<T> * BinarySearchTree<T>::getMin(TreeNode<T> * _root)
{
    // Keep looking for nodes in the left
    if (_root->getLeft())
    //if (_root->getLeft() != nullptr)
        return getMin(_root->getLeft());
    // Return a node with no left subtree
    return _root;
}

template <class T>
int BinarySearchTree<T>::countLeaves() { return 0; }

template <class T>
void BinarySearchTree<T>::printInOrder(TreeNode<T> * _root)
{
    if (_root)
    //if (_root != nullptr)
    {
        printInOrder(_root->getLeft());
        std::cout << " " << _root->getData() << " ";
        printInOrder(_root->getRight());
    }
}

// Private method to print the tree in a semi graphical form in the terminal
// The tree will appear rotated 90 degrees counter clock-wise
template <class T>
void BinarySearchTree<T>::printTree(TreeNode<T> * _root, int indent, char branch)
{
    if (_root)
    //if (_root != nullptr)
    {
        printTree(_root->getRight(), indent+INCREMENT, '/');
        std::cout << std::setw(indent) << branch << "- " << _root->getData() << std::endl;
        printTree(_root->getLeft(), indent+INCREMENT, '\\');
    }
}

#endif