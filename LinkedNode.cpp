//Code written for CS 341 at Butler University

#include "LinkedNode.h"

LinkedNode::LinkedNode(int data) : Node(data), nextLinkedNode_(nullptr), prevLinkedNode_(nullptr)
{
	//std::cout << "LN" << std::endl;
}
LinkedNode::LinkedNode(int data, LinkedNode * nextLinkedNode, LinkedNode * prevLinkedNode) : Node(data), nextLinkedNode_(nextLinkedNode), prevLinkedNode_(prevLinkedNode)
{
	//std::cout << "LN(C)" << std::endl;
}
LinkedNode::~LinkedNode()
{
	if (nextLinkedNode_ != nullptr)
	{
		//sets the pointer to the previous node to null, as it is already deleted
		prevLinkedNode_ = nullptr;
		delete nextLinkedNode_;
	}
	//std::cout << "~LN" << std::endl;
}
LinkedNode * LinkedNode::getNextLinkedNode()
{
	return nextLinkedNode_;
}
LinkedNode * LinkedNode::getPrevLinkedNode()
{
	return prevLinkedNode_;
}
void LinkedNode::setNextLinkedNode(LinkedNode * nextptr)
{
	nextLinkedNode_ = nextptr;
}
void LinkedNode::setPrevLinkedNode(LinkedNode * prevptr)
{
	prevLinkedNode_ = prevptr;
}
bool LinkedNode::hasNextLinkedNode()
{
	if(nextLinkedNode_ != nullptr)
	{
		return true;
	}
	return false;
}
bool LinkedNode::hasPrevLinkedNode()
{
	if(prevLinkedNode_ != nullptr)
	{
		return true;
	}
	return false;
}