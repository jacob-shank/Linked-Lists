//Code written for CS 341 at Butler University

#include "DoublyLinkedList.h"

void phase1();
void phase2();
void phase4();
void phase5();
//return a full DLL based on the input files
DoublyLinkedList getSortedDLL();
DoublyLinkedList getUnsortedDLL();
//returns the number of hops used
int doInsert(DoublyLinkedList & list, std::ofstream & fileOut);
void fillList(DoublyLinkedList & list, std::ifstream & dataIn);

//returns the node that should be targetted on insertion. Changes hops to the number of hops
LinkedNode * headInsert(int data, int & hops, DoublyLinkedList & list);
LinkedNode * tailInsert(int data, int & hops, DoublyLinkedList & list); 

int main()
{
	//phase1();
	//phase2();
	//phase4();
	phase5();
	
	return 0;
}
void phase1()
{
	LinkedNode * node1 = new LinkedNode(15);
	LinkedNode * node2 = new LinkedNode(10);
	LinkedNode * node3 = new LinkedNode(7);
	
	node1->setNextLinkedNode(node2);
	node2->setNextLinkedNode(node3);
	
	std::cout << "Next Node: " << node1->getNextLinkedNode()->getData() << std::endl;
	
	delete node1;
}
void phase2()
{
	LinkedList list = LinkedList();
	
	for(int i = 0; i < 100; i++)
	{
		if(i % 2 == 0)
		{
			list.insert(i-100);
			list.insert(i);
		}
	}
	
	std::cout << list.getLength() << std::endl;
	
	list.printList();
}
void phase4()
{
	DoublyLinkedList list = DoublyLinkedList();
	
	std::cout << list.isEmpty() << std::endl;
	list.insert(10);
	list.printList();
	list.insert(11);
	list.printList();
	
	LinkedNode * head = list.getHead();
	LinkedNode * tail = list.getTail();
	
	list.insertAfterLinkedNode(head,12);
	list.printList();
	list.insertLinkedNode(head->getNextLinkedNode(),13);
	list.printList();
	list.insertBeforeLinkedNode(tail,15);
	list.printList();
	list.insertAfterLinkedNode(tail,16);
	list.printList();
	list.insertBeforeLinkedNode(head,9);
	list.printList();
}
void phase5()
{
	std::ofstream sortedOut("sortedOutput.txt");
	DoublyLinkedList sortedList = getSortedDLL();
	int totalSortedHops = doInsert(sortedList,sortedOut);
	sortedOut << "Total big dawg hops: " << totalSortedHops;
	sortedOut.close();
	
	std::ofstream unsortedOut("output.txt");
	DoublyLinkedList unsortedList = getUnsortedDLL();
	int totalUnsortedHops = doInsert(unsortedList,unsortedOut);
	unsortedOut << "Total big dawg hops: " << totalUnsortedHops;
	unsortedOut.close();
}
DoublyLinkedList getSortedDLL()
{
	//get connection to the file that contains the list
	std::ifstream sortedIn("sorted.txt");
	DoublyLinkedList list = DoublyLinkedList();
	
	fillList(list, sortedIn);
	sortedIn.close();
	
	return list;
}
DoublyLinkedList getUnsortedDLL()
{
	//get connection to the file that contains the list
	std::ifstream unsortedIn("data.txt");
	DoublyLinkedList list = DoublyLinkedList();
	
	fillList(list, unsortedIn);
	unsortedIn.close();
	
	return list;
}
int doInsert(DoublyLinkedList & list, std::ofstream & fileOut)
{
	std::ifstream insertIn("inserts.txt");
	int current(0), headHops(0), tailHops(0), totalHops(0);
	LinkedNode * headInsertNode;
	LinkedNode * tailInsertNode;
	
	//show preliminary list
	fileOut << list.getListString() << "\n\n";
	
	while(insertIn >> current)
	{
		//test both
		headInsertNode = headInsert(current,headHops,list);
		tailInsertNode = tailInsert(current,tailHops,list);
		
		//when equal, defaults to the else, which is a tail insert
		if(headHops < tailHops)   //note: tail insert means use insertBeforeLinkedNode(), head insert means use insertAfterLinkedNode()
		{
			//insert using the head comparisons
			
			//case where there is not spot --> tail insert
			if(headInsertNode == nullptr)
			{
				list.insertLinkedNode(list.getTail(),current);
			}
			//everywhere else, insert before
			else
			{
				list.insertBeforeLinkedNode(headInsertNode,current);
			}
			
			fileOut << "Inserting " << current << " through head. " << "\tBig dawg hops: " << headHops << std::endl;
			
			totalHops += headHops;
		}
		else
		{
			//insert using tailComparisons
			
			//case where insert after tail
			if(tailInsertNode == nullptr)
			{
				list.insertAfterLinkedNode(list.getTail(),current);
			}
			//everywhere else, insert after
			else
			{
				list.insertAfterLinkedNode(tailInsertNode,current);
			}
			
			fileOut << "Inserting " << current << " through tail. " << "\tBig dawg hops: " << tailHops << std::endl;
			
			totalHops += tailHops;
		}
		//show the list
		fileOut << list.getListString() << "\n";
	}
	
	return totalHops;
}
void fillList(DoublyLinkedList & list, std::ifstream & dataIn)
{
	int current(0);
	while(dataIn >> current)
	{
		list.insert(current);
	}
}
LinkedNode * headInsert(int data, int & hops, DoublyLinkedList & list)
{
	LinkedNode * current = list.getHead();
	
	hops = 0;
	
	while(current->hasNextLinkedNode())
	{
		if(data < current->getData())
		{
			return current;
		}
		//not it, move current
		current = current->getNextLinkedNode();
		
		hops++;
	}
	
	//current == tail
	
	//loop didn't check tail
	if(data < current->getData())
	{
		//hops++;
		return current;
	}
	
	//no location for it, put it after tail
	hops = 0;
	return nullptr;
}
LinkedNode * tailInsert(int data, int & hops, DoublyLinkedList & list)
{
	LinkedNode * current = list.getTail();
	hops = 0;
	
	//Cases
	//1. finds a location --> return location
	//2. No suitable location found --> return null, insert after tail
	
	while(current->hasPrevLinkedNode())
	{
		if(data >= current->getData()) //data should go after this node
		{
			return current;
		}
		//not it, move current
		current = current->getPrevLinkedNode();
		
		hops++;
	}
	
	//current == head
	
	//the loop didn't check the head because head does not have a previous
	if(data >= current->getData())
	{
		//hops++;
		return current;
	}
	
	//if it has gotten this far, there is nothing in the list greater than data, return nullptr, insert after tail
	hops = 0;
	return nullptr;
}