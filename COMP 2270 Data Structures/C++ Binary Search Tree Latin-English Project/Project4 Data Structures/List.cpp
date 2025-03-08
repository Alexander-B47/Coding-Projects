#include "List.h"
#include <iostream>
using namespace std;

List::List() {
	 head = nullptr;
	 tail = head;
}

void List::deleteList() {
	while (head != nullptr)
		deleteNode();
}

void List::insertNode(string latinW) {	
	
	node* pnew = new node;
	pnew->latin = latinW;
	pnew->next = NULL;
	
	if (head != NULL)
	{
		tail->next = pnew;
		tail = pnew;
		pnew = NULL;
		
	}
	else
	{
		head = tail = pnew;
		pnew->next = NULL;
	}
}

string List::deleteNode(){
	node* tmp = head;
	head = head->next;
	string la = tmp->latin;
	delete tmp;
	return la;
}

void List::displayList(){
	node* walker = head;
	while (walker != nullptr)
	{
		cout << walker->latin;
		walker = walker->next;
		if (walker != nullptr)
			cout << ", " << flush;
	}
	cout << endl;
}
