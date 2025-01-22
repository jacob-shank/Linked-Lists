//Code written for CS 341 at Butler University

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LinkedNode.h"

class LinkedList
{
	public:
		LinkedList();
		LinkedList(LinkedList * list);
		virtual ~LinkedList();
		bool isEmpty();
		int getLength();
		virtual void insert(int element);
		virtual void printList();
		void removeNode(int key);
	protected:
		LinkedNode * head_;
		LinkedNode * tail_;
		int length;
		
	private:
		//helpers
		void printHelp(LinkedNode * front);
};

#endif