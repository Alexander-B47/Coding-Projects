#include <iostream>
#include <string>
#include <iomanip>
#include "PlayList.h"
using namespace std;
// Name: Alexander Bordenet
// Date: 10/5/24
// Purpose: To use a PlayList class that I have created to make and manipulate a PlayList linked list
// Also to show I can use classes, including header files in C++.


int main()
{
	bool isValid = false;
	int answer = 0;
	PlayList playList;
	string fileName = "songs.txt";
	Song* head = playList.buildPlaylist(fileName);

	// while they didn't select quit
	while (answer != 5)
	{
		answer = playList.showOptions();
		
		// validation for their choice
		if (answer > 5 || answer < 1)
		{
			while (!isValid)
			{
				cout << endl << "Invalid option, enter again: ";
				cin >> answer;
				if (answer < 6 && answer > 0)
					isValid = true;
			}
		}
		if (answer == 1)
			playList.showPlaylist(head);
		else if (answer == 2)
			playList.playSong(head);
		else if (answer == 3)
			playList.removeSong(head);
		else if (answer == 4)
			playList.rearrangePlaylist(head);
		else if (answer == 5)
			cout << endl << "Goodbye!";
	}
	
	return 0;
}