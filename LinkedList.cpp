//Code written for CS 341 at Butler University

#include "DoublyLinkedList.h"

LinkedList::LinkedList() : length(0), head_(nullptr), tail_(nullptr)
{
	//don't build anything here, insert can function without
	//head_ = new LinkedNode();
	//tail_ = new LinkedNode(); //<-- currently being leaked bc it never gets linked to list
	//head_->setNextLinkedNode(nullptr);
	//tail_->setNextLinkedNode(nullptr);
	//std::cout << "LL" << std::endl;
}
LinkedList::LinkedList(LinkedList * list) : length(0)
{
	head_ = list->head_;
	tail_ = list->tail_;
	//std::cout << "LN(C)" << std::endl;
}
LinkedList::~LinkedList()
{
	if(head_ != nullptr)
	{
		delete head_;
	}
	//std::cout << "~LL" << std::endl;
}
int LinkedList::getLength()
{
	return length;
}
void LinkedList::insert(int element)
{	
	//empty list
	if(isEmpty())
	{
		//add the node, head_ and tail_ point to the same node
		head_ = new LinkedNode(element);
		tail_ = head_;
		length++;
	}
	else
	{
		//put a new node in the node after the tail, then move the tail
		tail_->setNextLinkedNode(new LinkedNode(element)); //??????????
		tail_ = tail_->getNextLinkedNode();
		length++;
	}
}
bool LinkedList::isEmpty()
{
	if(length == 0)
	{
		return true;
	}
	return false;
}
void LinkedList::printList()
{
	printHelp(head_);
}
void LinkedList::removeNode(int key)
{
	//case #1: Key is head
	//case #2: Key is tail
	//case #3: Key is somewhere else
		
	if(key == head_->getData())
	{
		//case 1
		
		if(head_->hasNextLinkedNode())
		{
			//move the head to the next node
			LinkedNode * currentNode = head_;
			LinkedNode * nextNode = head_->getNextLinkedNode();
			head_ = nextNode;
			
			//now clean up
			currentNode->setNextLinkedNode(nullptr);
			delete currentNode;
		}
		else
		{
			//list that has a head_ only (tail_ = head_)
			
			LinkedNode * currentHead = head_;
			head_ = nullptr;
			tail_ = nullptr;
			delete currentHead;
		}
		
	}
	else if(key == tail_->getData())
	{
		//case 2
		
		//find the node before the tail_
		LinkedNode * previousNode = nullptr;
		LinkedNode * currentNode = head_;
		
		//will stop when currentNode is tail_
		while(currentNode->hasNextLinkedNode())
		{
			previousNode = currentNode;
			currentNode = currentNode->getNextLinkedNode();
			
			//if(currentNode->getNextLinkedNode() == tail_)
			//{
			//	break;
			//}
		}
		
		//sever the tail, then move it back
		previousNode->setNextLinkedNode(nullptr);
		tail_ = previousNode;
		
		//clean up
		delete currentNode;
	}
	else
	{
		//case 3
		
		//same as last case
		LinkedNode * previousNode = nullptr;
		LinkedNode * currentNode = head_;
		
		//will stop when currentNode is tail_
		while(currentNode->getData() == key)
		{
			previousNode = currentNode;
			currentNode = currentNode->getNextLinkedNode();
			
			//if(currentNode->getNextLinkedNode() == tail_)
			//{
			//	break;
			//}
		}
		
		//then
		previousNode->setNextLinkedNode(currentNode->getNextLinkedNode());
		currentNode->setNextLinkedNode(nullptr);
		delete currentNode;
		
	}
}


//helpers
void LinkedList::printHelp(LinkedNode * front)
{
	if(front->hasNextLinkedNode())
	{
		std::cout << front->getData() << "-->";
		
		//recurses
		printHelp(front->getNextLinkedNode());
	}
	//end of list
	else
	{
		std::cout << front->getData();
		std::cout << std::endl;
	}
}