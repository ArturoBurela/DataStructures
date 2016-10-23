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
        // Special method to insert with difference restrictions
        void insertPostFix(TreeNode<T> * _root, TreeNode<T> * new_node);
        void printInOrder(TreeNode<T> * _root);
        void printTree(TreeNode<T> * _root, int indent, char icon);
        //Methods to classify chars in numbers and operators
        bool isOp(char c);
        bool isNum(char c);

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

// Public insertion method that inserts Postfix
template <class T>
void BinarySearchTree<T>::insertPostFix(T data)
{
    TreeNode<T> * new_node = new TreeNode<T>(data);
    insertPostFix(new_node);
}

// Public insertion method that that inserts Postfix
template <class T>
void BinarySearchTree<T>::insertPostFix(TreeNode<T> * new_node)
{
    // Empty tree
    if (root == nullptr)
        root = new_node;
    else
        insertPostFix(root, new_node);
}

// Private insertion method that gets the root of the subtree
//  to insert, and the new tree node
template <class T>
void BinarySearchTree<T>::insert(TreeNode<T> * _root, TreeNode<T> * new_node)
{
    if (new_node->getData() < _root->getData())
    {
        if (_root->getLeft() == nullptr)
            _root->setLeft(new_node);
        else
            insert(_root->getLeft(), new_node);
    }
    else if (new_node->getData() > _root->getData())
    {
        if (_root->getRight() == nullptr)
            _root->setRight(new_node);
        else
            insert(_root->getRight(), new_node);
    }
    else
        return; // Do not insert duplicated data
}

// Private insertion method that gets the root of the subtree, it inserts according to postfix rules
template <class T>
void BinarySearchTree<T>::insertPostFix(TreeNode<T> * _root, TreeNode<T> * new_node)
{
  /*if (isNum(new_node->getData())) {
    if (end) {
      if (_root->getRight()->getRight()==nullptr || _root->getRight()->getLeft()==nullptr) {
        insertPostFix(_root->getRight(),new_node);
      }else{
        _root->setLeft(new_node);
      }
    }else{
      if (_root->getRight()!=nullptr && isOp(_root->getRight()->getData())&&!end) {
        insertPostFix(_root->getRight(),new_node);
      }else if(_root->getLeft()==nullptr){
        _root->setLeft(new_node);
      }else if(_root->getRight()==nullptr){
        _root->setRight(new_node);
        end = true;
      }
      if (_root->getLeft()!=nullptr && isOp(_root->getLeft()->getData())&&!end) {
        insertPostFix(_root->getLeft(),new_node);
      }else if(_root->getLeft()==nullptr){
        _root->setLeft(new_node);
      }else if(_root->getRight()==nullptr){
        _root->setRight(new_node);
        end = true;
      }
    }
    */


    /*if (_root->getLeft()==nullptr && isOp(_root->getData()) && (_root->getRight()==nullptr || isNum(_root->getRight()->getData()))) {
      _root->setLeft(new_node);
      return;
    }
    if (_root->getRight()==nullptr && isOp(_root->getData())) {
      _root->setRight(new_node);
      return;
    }else{
      insertPostFix(_root->getRight(),new_node);
    }*/
    if (isNum(new_node->getData())) {
      if (_root->getRight()==nullptr && isOp(_root->getData())) {
        _root->setRight(new_node);
      }else if (_root->getLeft()==nullptr && isOp(_root->getData())) {
        _root->setLeft(new_node);
      }else{
        if (isOp(_root->getRight()->getData())) {
          insertPostFix(_root->getRight(),new_node);
        }
        std::cout << "Root Data: "<< _root->getData() << std::endl;
        if (isOp(_root->getLeft()->getData())) {
          insertPostFix(_root->getLeft(),new_node);
        }
      }
    }

  if (isOp(new_node->getData())) {
    end = false;
    if (_root->getRight()==nullptr && isOp(_root->getData())) {
      _root->setRight(new_node);
    }else if (_root->getLeft()==nullptr && isOp(_root->getData())) {
      _root->setLeft(new_node);
    }else{
      if (isOp(_root->getRight()->getData())) {
        std::cout << "Root Data: "<< _root->getData() << std::endl;
        insertPostFix(_root->getRight(),new_node);
      }
      if (isOp(_root->getLeft()->getData())) {
        insertPostFix(_root->getLeft(),new_node);
      }
    }
  }
}

//Methods to classify chars in numbers and operators
template <class T>
bool BinarySearchTree<T>::isOp(char c){
  if (c=='+'||c=='*'||c=='^'||c=='-') {
    return true;
  }else{
    return false;
  }
}

template <class T>
bool BinarySearchTree<T>::isNum(char c){
  if (c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9'||c=='0') {
    return true;
  }else{
    return false;
  }
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

#endif
