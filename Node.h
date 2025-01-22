//Code written for CS 341 at Butler University

#ifndef NODE_H
#define NODE_H

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

class Node
{
	public:
		Node() {}
		Node(int data_);
		virtual ~Node();
		void setData(int data);
		int getData();
	private:
		int data_;
};

#endif