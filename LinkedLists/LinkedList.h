/*
Linked list class. Uses the Node class to store data

*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"

template <class T>
class LinkedList {
    private:
        Node<T> * head = nullptr;
        int length = 0;
    public:
        // Constructors
        LinkedList () {}
        LinkedList (Node<T> * _data) { head = _data; }
        // Destructor
        ~LinkedList ();
        void clear();
        // Insertion methods
        void insertHead (T data);
        void insertHead (Node<T> * new_node);
        void insertTail (T data);
        void insertTail (Node<T> * new_node);
        void insertAtPosition (T data, int position);
        void insertAtPosition (Node<T> * new_node, int position);
        // Delete methods
        Node<T> * removeHead();
        Node<T> * removeTail();
        //Node<T> * removeItem(T data);
        //Node<T> * removeFromPosition(int position);
        // Search methods
        T getDataAtHead();
        T getDataAtTail();
        //T getDataAtPosition();
        // Print methods
        void printList ();
};

////Destructor/////
template <class T>
LinkedList<T>::~LinkedList(){
  //std::cout << "Destroying list" << std::endl;
  clear();
}

template <class T>
void LinkedList<T>::clear() {
  Node<T> * item = head;
  while (item != nullptr) {
    head = item->getNext();
    delete item;
    item = head;
  }
}

////// INSERTION METHODS //////

template <class T>
void LinkedList<T>::insertHead (T data)
{
    // Create a new node instance with the data provided
    Node<T> * new_node = new Node<T>(data);
    insertHead(new_node);
}

template <class T>
void LinkedList<T>::insertHead (Node<T> * new_node)
{
    new_node->setNext(head);
    head = new_node;
    length += 1;
}

template <class T>
void LinkedList<T>::insertTail (T data)
{
    // Create a new node instance with the data provided
    Node<T> * new_node = new Node<T>(data);
    insertTail(new_node);
}

template <class T>
void LinkedList<T>::insertTail (Node<T> * new_node)
{
  if (head == nullptr) {
    insertHead(new_node);
    length +=1;
  }
  else{
    Node<T> * item = head;
    std::cout << "[" << std::endl;
    while (item->getNext() != nullptr) {
      item = item->getNext();
    }
    std::cout << "]" << std::endl;
    length += 1;
  }
}
template <class T>
void LinkedList<T>::insertAtPosition (Node<T> * new_node, int position){
  if(position<=length-1){
    if(position==0){
      insertHead(new_node);
    }else{
      Node<T> * item = head;
      int i = 0;
      while (i<position-1) {
        item = item->getNext();
        i++;
      }
      //std::cout << "Prueba" << std::endl;//Prueba
      new_node->setNext(item->getNext());
      item->setNext(new_node);
          //new_node.setNext();
    }
  }else{
    std::cout << "position not valid" << std::endl;
    return;
  }
}
template <class T>
void LinkedList<T>::insertAtPosition (T data, int position){
  if(position<=length-1){
    // Create a new node instance with the data provided
    Node<T> * new_node = new Node<T>(data);
    insertAtPosition(new_node,position);
  }else{
    std::cout << "position not valid" << std::endl;
    return;
  }
}

////GET METHODS //////
template <class T>
T LinkedList<T>::getDataAtHead(){
  if(length>0){
  return head->getData();
  }else{
    std::cout << "No head in the list" << std::endl;
    return -1; // Does not work with strings, What to return for every T ???
  }
}
template <class T>
T LinkedList<T>::getDataAtTail(){
  if(length>0){
    Node<T> * item = head;
    while (item->getNext() != nullptr) {
      item = item->getNext();
    }
    return item->getData();
  }else{
    std::cout << "No tail in the list" << std::endl;
    return -1; // Does not work with strings, What to return for every T ???
  }
}
//T getDataAtPosition();

//////DELETE METHODS /////
template <class T>
Node<T> * LinkedList<T>::removeHead(){
  //Return nothing if the list is empty
  if(head==nullptr)
    return nullptr;
  Node<T> * item = head;
  ///Update the head of the list
  head = item->getNext();
  //Disconect the node
  item->setNext(nullptr);
  //Return the node just removed
  return item;
}
template <class T>
Node<T> * LinkedList<T>::removeTail(){
  //Return nothing if the list is empty
  if(head==nullptr)
    return nullptr;
  //Only one element on the list
  if(head->getNext()== nullptr){
    Node<T> * item = head;
    head = nullptr;
    return item;
  }
  //More than one element
  Node<T> * previous = head;
  Node<T> * item = head->getNext();
  while (item->getNext() != nullptr) {
    previous=item;
    item = item->getNext();
  }
  //Change the tail of the list
  previous->setNext(nullptr);
  return item;
}
//Node<T> * removeItem(T data);
//Node<T> * removeFromPosition(int position);


////// PRINT METHODS //////
template <class T>
void LinkedList<T>::printList()
{
    Node<T> * item = head;

    std::cout << "[ ";
    while (item != nullptr)
    {
        std::cout << item->getData() << " ";
        item = item->getNext();
    }
    std::cout << " ]" << std::endl;
}



#endif
