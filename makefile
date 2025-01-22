Link.exe: Node.o LinkedNode.o LinkedList.o DoublyLinkedList.o driver.o
	g++ Node.o LinkedNode.o LinkedList.o DoublyLinkedList.o driver.o -o Link.exe

Node.o: Node.cpp
	g++ -c Node.cpp -o Node.o

LinkedNode.o: LinkedNode.cpp
	g++ -c LinkedNode.cpp -o LinkedNode.o

LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp -o LinkedList.o

DoublyLinkedList.o: DoublyLinkedList.cpp
	g++ -c DoublyLinkedList.cpp -o DoublyLinkedList.o

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o