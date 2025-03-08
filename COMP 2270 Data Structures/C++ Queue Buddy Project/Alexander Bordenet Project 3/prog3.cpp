#include <fstream>
#include <iostream>
#include <string>
#include "Queue.h"
using namespace std;

// Alexander Bordenet
// 10/20/24
// Project 3: To demonstrate that I am able to properly use and implement a queue.

const int SIZE = 26;

//**************************************************************
// grabKnowList: Will read from a file to build a string array.
// Input : Nothing
// Output: A string pointer to the created string array
//**************************************************************
string* grabKnowList() {
	ifstream input("buddies.txt");
	string* knowList = new string[SIZE];
	
	// File Validation
	if (input.good()) {
		for (int i = 0; i < SIZE; i++)
			getline(input, knowList[i]);
	}
	return knowList;
}

//*************************************************************************
// comparLists: takes in two integer arrays; one for the cop
// and one for the current suspect. It will then compare each element
// and return whether they are equal or not. If one person fails then they
// are not the burglar.
// Input : Two integer arrays
// Output: A boolean value containing whether the arrays matched or not.
//*************************************************************************
bool compareLists(int* cList, int* sList) {
	for (int i = 0; i < SIZE; i++) {
		if (cList[i] != sList[i]) 
			return false;
	}
	return true; 
}

//***********************************************************************
// enQueueOne: Takes in a Queue and a char to enqueue. Verifies that
// the specific character has not already been enqueued using the passed
// knowList. Updates the knowList accordingly.
// Input : Queue object passed by reference, a character, a integer array
// Output: Nothing.
//***********************************************************************
void enQueueOne(Queue& x, char p, int * knowList) {
	if (knowList[p - 'A'] == 0) {
		x.enqueue(p);
		knowList[p - 'A'] = 1;
	}
}

//*************************************************************************
// enQueueBuddies: This will loop through the person's buddies by calling
// enQueueOne for each character in the buddies string. Passes knowList to 
// be updated in enQueueOne.
// Input : Queue object passed by reference, a string, integer array
// Output: Nothing.
//*************************************************************************
void enQueueBuddies(Queue& x, string buddies, int * knowList) {
	for (int y = 0; y < buddies.length(); y++)
		enQueueOne(x, buddies.at(y), knowList);
}

//******************************************************************************
// knowListBuilder: This will repeatedly call the helper functions to construct
// the person's boolList. The helper functions are enQueueOne & enQueueBuddies
// Input : A Queue object passed by reference, integer array, string array, int
// Output: Nothing
//******************************************************************************
void knowListBuilder(Queue& x, int * boolList , string knows[], int start) {
	// Start with enqueue-ing the starting person outside loop
	enQueueOne(x, char('A' + start), boolList);

	while (!x.isEmpty()) {
		char tmp = x.dequeue();
		enQueueBuddies(x, knows[tmp - 'A'], boolList);
	}
}

int main() {	
	Queue myQueue; 
	bool similar = false;
	char burglar = '#'; 
	string* knowLists = grabKnowList();

	// Initialize the copList
	int copList[SIZE]{ 0 };
	knowListBuilder(myQueue, copList, knowLists, 2);
	copList['S' - 'A'] = 1;

	// Makes and compares each person's know list to the cop's list
	for (int i = 0; i < SIZE; i++) {
		int knowListBase[SIZE]{ 0 }; 
		
		// Builds current person's knowList. Skips C because we know it already
		if(i != 2)
			knowListBuilder(myQueue, knowListBase, knowLists, i); 
		
		// Compare cop to current list
		similar = compareLists(copList, knowListBase); 
		if (similar == true) {
			burglar = char('A' + i);
			break;
		}
	}
	cout << "I know who the burglar is, it is " << burglar << "." << endl;
	return 0;
}