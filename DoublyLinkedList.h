//Code written for CS 341 at Butler University

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#define PRINT_WIDTH 25

#include "LinkedList.h"

class DoublyLinkedList : public LinkedList
{
	public:
		DoublyLinkedList();
		DoublyLinkedList(DoublyLinkedList * dlist);
		virtual ~DoublyLinkedList();
		virtual void printList();
		virtual void insert(int element);
		void insertLinkedNode(LinkedNode * node, int data);
		void insertAfterLinkedNode(LinkedNode * node, int data);
		void insertBeforeLinkedNode(LinkedNode * node, int data);
		LinkedNode * getHead();
		LinkedNode * getTail();
		std::string getListString();
	private:
		
		//helpers
		void printHelp(LinkedNode *);
};

#endif