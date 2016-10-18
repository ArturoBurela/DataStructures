/*
Linked list class

Arturo Burela A01019906
Data Structures

*/
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdexcept>
#include "Node.h"

template <class T>
class LinkedList {
private:
  Node<T> * head = nullptr;
  //int length = 0;
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
  T deleteHead ();    // Return the data and deletes the node
  Node<T> * removeHead ();    // Return the node with the data
  Node<T> * removeTail ();
  Node<T> * removeItem (T data);
  Node<T> * removeFromPosition (int position);
  // Search methods
  T getDataAtHead ();
  T getDataAtTail ();
  T getDataAtPosition (int position);
  // Access methods
  int getLength();
  Node<T> * getHead () const { return head; }
  Node<T> * getHead () { return head; }
  // Print methods
  void printList ();
};

////// DESTRUCTOR //////
template <class T>
LinkedList<T>::~LinkedList()
{
  std::cout << "Destroying the list" << std::endl;
  clear();
}

template <class T>
void LinkedList<T>::clear()
{
  Node<T> * item = head;

  while (item != nullptr)
  {
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
  // Special case for an empty list
  if (head == nullptr)
  {
    insertHead(new_node);
  }
  else
  {
    Node<T> * item = head;
    while (item->getNext() != nullptr)
    {
      item = item->getNext();
    }
    item->setNext(new_node);
  }
}

////// DELETE METHODS //////

template <class T>
T LinkedList<T>::deleteHead ()
{
  T data = head->getData();
  Node<T> * item = head;
  // Update the head of the list
  head = item->getNext();
  // Free the memory for the node
  delete item;
  // Return the data only
  return data;
}

template <class T>
Node<T> * LinkedList<T>::removeHead ()
{
  // Return nothing if the list is empty
  if (head == nullptr)
  return nullptr;
  Node<T> * item = head;
  // Update the head of the list
  head = item->getNext();
  // Disconnect the node
  item->setNext(nullptr);
  // Return the node just removed
  return item;
}

template <class T>
Node<T> * LinkedList<T>::removeTail ()
{
  // Return nothing if the list is empty
  if (head == nullptr)
  return nullptr;
  // Only one element in the list
  if (head->getNext() == nullptr)
  {
    Node<T> * item = head;
    head = nullptr;
    return item;
  }
  // More than one element in the list
  Node<T> * previous = head;
  Node<T> * item = previous->getNext();
  while (item->getNext() != nullptr)
  {
    previous = item;
    item = item->getNext();
  }
  // Change the tail of the list
  previous->setNext(nullptr);
  return item;
}

template <class T>
Node<T> * LinkedList<T>::removeItem (T data)
{

}

template <class T>
Node<T> * LinkedList<T>::removeFromPosition (int position)
{

}

// Search methods
template <class T>
T LinkedList<T>::getDataAtHead ()
{
  if (head != nullptr)
  return head->getData();
  else
  throw std::runtime_error("Error: Empty list");
}

template <class T>
T LinkedList<T>::getDataAtTail ()
{
  if (head != nullptr)
  {
    Node<T> * item = head;
    while (item->getNext() != nullptr)
    {
      item = item->getNext();
    }
    return item->getData();
  }
  else
  throw std::runtime_error("Error: Empty list");
}

template <class T>
T LinkedList<T>::getDataAtPosition (int position)
{
  if (head != nullptr)
  {
    Node<T> * item = head;
    int index = 0;
    while (index < position && item->getNext() != nullptr)
    {
      item = item->getNext();
      index++;
    }
    return item->getData();
  }
  else
  throw std::runtime_error("Error: Empty list");
}

// Access methods
template <class T>
int LinkedList<T>::getLength()
{
  int length = 0;

  Node<T> * item = head;
  while (item != nullptr)
  {
    length++;
    item = item->getNext();
  }
  return length;
}

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
