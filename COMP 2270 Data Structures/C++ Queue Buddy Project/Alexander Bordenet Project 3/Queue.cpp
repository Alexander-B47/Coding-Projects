#include "Queue.h"

Queue::Queue() { 
	front = rear = nullptr;
	count = 0;
}

Queue::~Queue() { 
	while (front != nullptr)
		dequeue();
}

void Queue::enqueue(char x) {
	Node* tmp = new Node;
	if (tmp != nullptr) { // overflow check
		tmp->person = x;
		tmp->next = nullptr;
		if (rear == nullptr) // if empty queue
			front = tmp;
		else
			rear->next = tmp;
		rear = tmp;
		tmp = nullptr;
		count++;
	}
}

char Queue::dequeue() { 
	if (front != nullptr && count != 0) { // underflow case
		Node* tmp = front;
		front = front->next;
		if (front == nullptr) // if the queue becomes empty
			rear = front;
		char peep = tmp->person;
		delete tmp;
		tmp = nullptr;
		count--;
		return peep;
	}
	return '\0'; 
}

bool Queue::isEmpty() { return (front == nullptr); }