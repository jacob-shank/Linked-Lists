//Code written for CS 341 at Butler University

#ifndef LINKEDNODE_H
#define LINKEDNODE_H

#include "Node.h"

class LinkedNode : public Node
{
	public:
		LinkedNode() {}
		LinkedNode(int data);
		LinkedNode(int data, LinkedNode * nextLinkedNode, LinkedNode * prevLinkedNode);
		virtual ~LinkedNode();
		LinkedNode * getNextLinkedNode();
		LinkedNode * getPrevLinkedNode();
		void setNextLinkedNode(LinkedNode * nextptr);
		void setPrevLinkedNode(LinkedNode * prevptr);
		bool hasNextLinkedNode();
		bool hasPrevLinkedNode();
	private:
		LinkedNode * nextLinkedNode_;
		LinkedNode * prevLinkedNode_;
};

#endif