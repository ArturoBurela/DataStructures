/*
Class implementation for a self balancing tree
Arturo Burela A01019906
*/

#ifndef AVL_TREE
#define AVL_TREE


#include "BinarySearchTree.h"
#include <algorithm>

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

template <class T>
void AVLTree<T>::updateHeight(TreeNode<T> * _root){
  //Validate the node is not empty
  if(!_root)
    return;
  int leftHeight = 0;
  int rightHeight = 0;
  if (_root->getLeft() != nullptr) {
    leftHeight = _root->getLeft()->getHeight();
  }
  if (_root->getRight() != nullptr) {
    rightHeight = _root->getRight()->getHeight();
  }
  _root->setHeight(std::max(leftHeight,rightHeight)+1);
}

template <class T>
int AVLTree<T>::getBalanceFactor(TreeNode<T> * _root){
  //Validate the node is not empty
  if(!_root)
    return;
  int leftHeight = 0;
  int rightHeight = 0;
  if (_root->getLeft() != nullptr) {
    leftHeight = _root->getLeft()->getHeight();
  }
  if (_root->getRight() != nullptr) {
    rightHeight = _root->getRight()->getHeight();
  }
  return leftHeight-rightHeight;
}

template <class T>
TreeNode<T> * AVLTree<T>::rotateRight(TreeNode<T> * _root){
  TreeNode<T> * child = _root->getLeft();
  _root->setLeft(child->getRight());
  child->setRight(_root);
  //Update heights
  updateHeight(_root);
  updateHeight(child);
  return child;
}

template <class T>
TreeNode<T> * AVLTree<T>::rotateLeft(TreeNode<T> * _root){
  TreeNode<T> * child = _root->getRight();
  _root->setRight(child->getLeft());
  child->setLeft(_root);
  //Update heights
  updateHeight(_root);
  updateHeight(child);
  return child;
}

template <class T>
TreeNode<T> * AVLTree<T>::balance(TreeNode<T> * _root){
  updateHeight(_root);
  int balance_factor = getBalanceFactor(_root);
  //Left is heavier
  if (balance_factor==2) {
    if (getBalanceFactor(_root->getLeft()) < 0){
      //LR case
      _root->setLeft(rotateLeft(_root->getLeft()));
    }
    //LL case
    _root = rotateRight(_root);
  }
  //Right is heavier
  if (balance_factor==-2) {
    if (getBalanceFactor(_root->getRight()) > 0){
      //RL case
      _root->setRight(rotateRight(_root->getRight()));
    }
    //RR case
    _root = rotateLeft(_root);
  }
  return _root;
}

template <class T>
TreeNode<T> * AVLTree<T>::insert(TreeNode<T> * _root, TreeNode<T> * new_node){
  insert(_root,new_node);
  balance(_root);
}

//Overload ot the public method
template <class T>
void AVLTree<T>::insert(TreeNode<T> * new_node){
  // Empty tree
  if (this->root == nullptr)
      this->root = new_node;
  else
      this->root=insert(this->root, new_node);
}

#endif
