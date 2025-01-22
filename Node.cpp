//Code written for CS 341 at Butler University
#include "Node.h"

Node::Node(int data)
{
	data_ = data;
	//std::cout << "N" << std::endl;
}
Node::~Node()
{
	//std::cout << "~N" << std::endl;
}
int Node::getData()
{
	return data_;
}
void Node::setData(int data)
{
	data_ = data;
}