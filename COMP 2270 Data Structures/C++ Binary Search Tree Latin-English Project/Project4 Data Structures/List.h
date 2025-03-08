#pragma once
#include <string>
using namespace std;

struct node {
	string latin;
	node* next;
};

class List
{
private:
	node* head;
	node* tail;
public:
	List();
	void deleteList();
	void insertNode(string);
	string deleteNode();
	void displayList();

};

