// Edwardo Portet
// Dong Hyun Kim
//  LinkedList.cpp
//  Linked_List
//

#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList() {
	head = NULL;
	listSize = 0;
}

LinkedList::~LinkedList() {
	//cout << "OMG THIS WAS DESTROYED!!!" << endl;
}

int LinkedList::size() {
	return listSize;
}

bool LinkedList::contains(int x) {
	Node* temp = head;
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

bool LinkedList::add(int x) {
	if (head == NULL) {
		head = new Node();
		head->data = x;
		head->next = NULL;
		listSize++;

		return true;
	}
	
	Node* temp = head;
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

	Node *n = new Node();
	temp->next = n;
	n->data = x;
	n->next = NULL;
	listSize++;

	return true;
}

bool LinkedList::remove(int x) {
	if (!contains(x)) {
		return false;
	}

	Node* temp = head;
	while (temp->next->data != x) {
		temp = temp->next;
	}
	temp->next = temp->next->next;
	delete temp->next;

	return true;
}

void LinkedList::print() {
	Node* temp = head;
	while (temp->next != NULL) {
		cout << temp->data << ", ";
		temp = temp->next;
	}
	cout << temp->data << endl;
}