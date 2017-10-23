///////////////////////
//  Edwardo Portet
//  Dong Hyun Kim
///////////////////////
//  LinkedList.h
//  Linked_List_Template
//

#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>
#include <iostream>
using namespace std;

/* A singly-linked list node */
template<typename T>
struct Node
{
    T data;
    Node<T> *next;
};

/* A class for a singly-linked list */
template<typename T>
class LinkedList
{
public:
  LinkedList();       // Constructor: Inits an empty singly-linked list
  ~LinkedList();      // Destructor: Destroys the singly-linked list 
  int size();         // Returns the size of the singly-linked list
  bool contains(T x);  // Returns true if x is in the list, otherwise returns false
  bool add(T x);    // Adds x if not already in the list and returns true, otherwise returns false
  bool remove(T x); // Removes x if in the list and returns true, otherwise returns false
  void print();       // Prints the content of the singly-linked list

private:
  Node<T> *head;         // Pointer to head of singly-linked list
  int listSize;       // Size of singly-linked list
};

template<typename T>
LinkedList<T>::LinkedList() {
  head = NULL;
  listSize = 0;
}

template<typename T>
LinkedList<T>::~LinkedList() {
  //cout << "OMG THIS WAS DESTROYED!!!" << endl;
}

template<typename T>
int LinkedList<T>::size() {
  return listSize;
}

template<typename T>
bool LinkedList<T>::contains(T x) {
  Node<T> *temp = head;
  while (temp != NULL) {
    if (temp->data == x) {
      return true;
    }
    else if (temp->next != NULL) {
      temp = temp->next;
    }
    else {
      return false;
    }
  }
  return false;
}

template<typename T>
bool LinkedList<T>::add(T x) {
  if (head == NULL) {
    head = new Node<T>();
    head->data = x;
    head->next = NULL;
    listSize++;

    return true;
  }
  
  Node<T>* temp = head;
  while (temp != NULL) {
    if (temp->data == x) {
      return false;
    }
    else if (temp->next != NULL) {
      temp = temp->next;
    }
    else {
      break;
    }
  }

  Node<T> *n = new Node<T>();
  temp->next = n;
  n->data = x;
  n->next = NULL;
  listSize++;

  return true;
}

template<typename T>
bool LinkedList<T>::remove(T x) {
  if (!contains(x)) {
    return false;
  }

  Node<T>* temp = head;
  while (temp->next->data != x) {
    temp = temp->next;
  }
  Node<T> *del = temp->next;
  temp->next = temp->next->next;
  delete del;

  return true;
}

template<typename T>
void LinkedList<T>::print() {
  Node<T>* temp = head;
  while (temp->next != NULL) {
    cout << temp->data << ", ";
    temp = temp->next;
  }
  cout << temp->data << endl;
}

#endif /* LinkedList_h */
