//Code written for CS 341 at Butler University

#include "DoublyLinkedList.h"


//constructors
DoublyLinkedList::DoublyLinkedList() : LinkedList()
{
	//std::cout << "D" << std::endl;
}
DoublyLinkedList::DoublyLinkedList(DoublyLinkedList * dlist)
{
	head_ = dlist->head_;
	tail_ = dlist->tail_;
	//std::cout << "D(C)" << std::endl;
}

//destructor
DoublyLinkedList::~DoublyLinkedList()
{
	//since the LL destructor is run automatically, there is nothing to delete here
}


//tail_ insert
void DoublyLinkedList::insert(int element)
{
	//empty list
	if(isEmpty())
	{
		//std::cout << "Inserting " << element << "... " << std::endl;
		//add the node, head_ and tail_ point to the same node
		head_ = new LinkedNode(element);
		tail_ = head_;
		length++;
	}
	else
	{
		//just do a tail_ insertion
		insertAfterLinkedNode(tail_, element);
	}
}
//inserts at the location after the pointer
void DoublyLinkedList::insertLinkedNode(LinkedNode * node, int data)
{
	insertAfterLinkedNode(node, data);
}
void DoublyLinkedList::insertAfterLinkedNode(LinkedNode * node, int data)
{
	//std::cout << "Inserting " << data << "... " << std::endl;
	
	//won't be empty bc the function requires a pointer
	
	//inserting after tail_
	if(node == tail_)
	{
		//std::cout << "INSERT AT TAIL" << std::endl;
		//make a new node to be inserted
		LinkedNode * newNode = new LinkedNode(data);
		
		//set the pointers forward and backward
		node->setNextLinkedNode(newNode);
		newNode->setPrevLinkedNode(tail_);
		
		//move the tail_ to the new end
		tail_ = newNode;
	}
	//inserting elswhere
	else
	{
		//the pointer is pointing to something other than the tail_
		
		//make a new node that will be left in the tree when we're done
		LinkedNode * newNode = new LinkedNode(data);
		
		//now get the nodes on either side of the location of the insertion
		LinkedNode * nextNode = node->getNextLinkedNode();
		//node is the prevNode
		
		//now connect the pointers
		
		//first the pointers for between the new node and the prev nodes
		node->setNextLinkedNode(newNode);
		newNode->setPrevLinkedNode(node);
		
		//now connect newNode to the following node
		newNode->setNextLinkedNode(nextNode);
		nextNode->setPrevLinkedNode(newNode);
	}
	length++;
}
void DoublyLinkedList::insertBeforeLinkedNode(LinkedNode * node, int data)
{
	//insertion is at head
	if(node == head_)
	{
		//std::cout << "Inserting " << data << "... " << std::endl;
		
		LinkedNode * newNode = new LinkedNode(data);
		
		//create pointers too and from head_
		newNode->setNextLinkedNode(head_);
		head_->setPrevLinkedNode(newNode);
		
		//now move the head_ pointer
		head_ = newNode;
	}
	else //inserting elsewhere
	{
		//insert after
		insertLinkedNode(node->getPrevLinkedNode(), data);
	}
}
void DoublyLinkedList::printList()
{
	printHelp(head_);
}
LinkedNode * DoublyLinkedList::getHead()
{
	return head_;
}
LinkedNode * DoublyLinkedList::getTail()
{
	return tail_;
}
std::string DoublyLinkedList::getListString()
{
	int count = 0;
	
	std::string listString = "", dataString = "";
	LinkedNode * current = head_;
	
	std::stringstream converter;
	
	//gets everything execpt the tail
	while(current->hasNextLinkedNode())
	{
		converter.clear();
		converter.str("");
		dataString = "";
		
		converter << current->getData();
		converter >> dataString;
		
		listString.append(dataString).append("<-->");
		
		//now move current
		current = current->getNextLinkedNode();
		
		//QOL/appearance stuff
		count++;
		if(count > PRINT_WIDTH)
		{
			count = 0;
			listString.append("\n\t");
		}
	}
	
	//now add in the tail
	converter.clear();
	converter.str("");
	dataString = "";
	
	converter << current->getData();
	converter >> dataString;
	
	listString.append(dataString).append("\n");
	
	return listString;
}


//helpers
void DoublyLinkedList::printHelp(LinkedNode * front)
{
	if(front->hasNextLinkedNode())
	{
		std::cout << front->getData() << "<-->";
		
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

/*void DoublyLinkedList::removeNode(int key)
{
	if(key == head_->getData())
	{
		if(head_->hasNextLinkedNode())
		{
			LinkedNode * currentHead = head_;
			LinkedNode * nextNode = head_->getNextNode();
			head_ = nextNode;
			nextNode->setPrevLinkedNode(nullptr);
			currentHead->setNextLinkedNode(nullptr);
			delete currentHead;
		}
		else
		{
			LinkedNode * currentHead = head_;
			head_ = nullptr;
			tail_ = nullptr;
			delete currentHead;
		}
	}
	else if(key == tail_->getData())
	{
		if(tail_->hasPrevLinkedNode())
		{
			LinkedNode * currentTail = tail_;
			LinkedNode * previousNode = tail->getPrevLinkedNode();
			
			tail_ = previousNode;
			previousNode->setNextLinkedNode(nullptr);
			currentTail->setPrevLinkedNode(nullptr);
			delete currentTail;
		}
	}
	else
	{
		LinkedNode * currentNode = head_;
		bool isFound = false;
		
		while((currentNode->hasNextNode()) && (!isFound))
		{
			//do this first because we know its not the head
			currentNode->getNextLinkedNode();
			
			if(key == currentNode->getData())
			{
				isFound = true;
				
				currentNode->getPrevLinkedNode()->setNextLinkedNode(currentNode->getNextLinkedNode());
				currentNode->getNextLinkedNode()->setPrevLinkedNode(currentNode->getPrevLinkedNode());
				currentNode->setNextLinkedNode(nullptr);
				currentNode->setPrevLinkedNode(nullptr);
				delete currentNode;
			}
		}
		//never found it
		if(!isFound)
		{
			std::cout << "Key Not Found->" << std::endl;
		}
	}
}*/