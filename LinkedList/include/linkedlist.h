/*
 * linkedlist.h
 *
 *  Created on: 27-May-2018
 *      Author: Sahil S
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>

using namespace std;

struct Node{
	// all members public in structure
	int data;
	Node *next;
};

class LinkedList{

public:
	/**
	 * Method to print elements of LinkedList
	 * input arg: pointer to struct
	 */
	static void printLinkedList(Node* traverse);

	/**
	 * Method to add node front of the linkedlist
	 * add to the front
	 */
	static void insertionFront(Node** first, int data);

	/**
	 * Method to add node to the back of the linkedlist
	 * add to the end
	 */
	static void insertionLast(Node** last, int data);

	/**
	 * Method to insert after one node in linkedlist
	 */
	static void insertAfter(Node* prev, int data);

	/**
	 *Method to delete a node at given position
	 */
	static void deleteNode(Node** head,int position);

	/**
	 * Method to count the length of linkedlist
	 */
	static int length(Node* head);
private:
	static int counter; //declared global so initialized to zero
};
#endif /* LINKEDLIST_H_ */
