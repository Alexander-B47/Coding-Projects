#pragma once

struct Node {
	char person;
	Node* next;
};

class Queue {
private:
	Node* front, * rear;
	int count;
public:
	Queue(); // Constructor
	~Queue(); // De-constructor
	void enqueue(char); // Adds to Queue
	char dequeue(); // Removes from Queue
	bool isEmpty(); // Verifies amount in Queue
};

