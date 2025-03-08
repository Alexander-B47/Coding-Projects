// Name: Alexander Bordenet
// File Name: prog5.cpp
// Date: 10/18/23
// Program Description: This program will create a playlist using a file and allow the user to manipulate it
// This will also show my ability to use linked lists.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;



struct Song
{
    string songName;
    string artistName;
    Song* nextSong;
    
};

Song* buildPlaylist();
void showPlaylist(Song* );
void playSong(Song*);
void removeSong(Song*&);

int main()
{
    Song* head = NULL;
    int contin = 0;
    int ans = 0;
    bool valid = false;

    head = buildPlaylist();
    while (contin != 4)
    {
        cout << endl << "1) Show the playlist" << endl;
        cout << "2) Play a song" << endl;
        cout << "3) Remove a song" << endl;
        cout << "4) Quit" << endl;
        cout << "Enter your answer: ";
        cin >> ans;
       
        if (ans > 4|| ans == 0)
        {
            while (valid == false)
            {
                cout << endl << "Invalid option,";
                cout << "enter again: ";
                cin >> ans;
                if (ans < 4 && ans != 0)
                    valid = true;
            }
        }

        if (ans == 1)
        {
            showPlaylist(head);
        }
        else if (ans == 2)
        {
            playSong(head);
        }
        else if (ans == 3)
        {
            removeSong(head);
        }
        else if (ans == 4)
        {
            contin = 4;
        }
    }

    

    
    
    
    return 0;
}

/***********************************************************************************
* This will ask the user for the name of the txt file that stores the playlist data
* It will use this to create a linked list of songs.
* input: none
* output: a song pointer head. 
***********************************************************************************/
Song* buildPlaylist()
{
    Song* head = NULL;
    Song* tail = NULL;
    string fileName;
    string songArtist;
    int colonPos;

    cout << "Enter the playlist File name:";
    cin >> fileName;

    ifstream inFile(fileName);
    head = new Song;
    getline(inFile , songArtist);
    colonPos = songArtist.find(":");
    head->songName = songArtist.substr(0, colonPos);
    head->artistName = songArtist.substr(colonPos+1);
    head->nextSong = NULL;
    tail = head;
    
    while (getline(inFile, songArtist))
    {
        Song* pnew = new Song;
        
        colonPos = songArtist.find(":");
        pnew->songName = songArtist.substr(0, colonPos);
        pnew->artistName = songArtist.substr(colonPos+1);
        pnew->nextSong = NULL;
        tail->nextSong = pnew;
        tail = pnew;
        pnew = NULL;
    }
    inFile.close();

    cout << endl << "Playlist created!" << endl;
    
    return head;
}

/************************************************************************
* This will take in the head of the linked list for the playlist
* and will use it to display each member of the list in order
* while also being formatted.
* Input : Song pointer head pointing to the start of the linked list.
* Output : None.
*************************************************************************/
void showPlaylist(Song* head)
{
    Song* walker = NULL;
    walker = head;
    int index = 1;

    cout << endl << "-------------------------------------------" << endl;

    while (walker != NULL)
    {
        
        cout << index << ") " << setw(25) << left << walker->songName;
        
        cout << walker->artistName << endl;
        walker = walker->nextSong;
        index++;
    }
    cout << endl << "-------------------------------------------" << endl;
}

/**********************************************************
* This function will use the head pointer to
* find the specific song name to be displayed to the screen
* Input: Song pointer head
* Output: None
**********************************************************/
void playSong(Song* head)
{
    int songNum = 0;
    Song* walker = head;
    bool valid = false;
    int index = 1;

    cout << endl << "Enter the song number: ";
    cin >> songNum;
    while (walker != NULL && valid == false)
    {
        
        if (index == songNum)
        {
            valid = true;
            cout << endl << "Now playing \"" << walker->songName << "\" by " << walker->artistName;
        }
        else
        {
            walker = walker->nextSong;
            index++;
        }
        

    }
    if (valid == false)
        cout << endl << "Song not found";
   
    
}

/************************************************************************
* This function will use the head pointer by reference
* and go through the playlist until it finds the song
* that needs to be deleted. It will also reconnect the playlist together
* Input: Song pointer head passed by reference
* Ouput: None
************************************************************************/
void removeSong(Song* &head)
{
    int songNum;
    int index = 1;
    bool valid = false;
    Song* pre = NULL,
        * cur = NULL,
        * temp = NULL,
        * walker = head;


    cout << endl << "Enter the song number: ";
    cin >> songNum;

    if (songNum == 1)
    {
        temp = head;
        head = head->nextSong;
        cout << endl << "\"" << temp->songName << "\" removed from playlist!" << endl;
        delete temp;
    }
    else if(songNum != 0)
    {
        while (walker != NULL && valid == false)
        {

            if (index == songNum - 1 && walker -> nextSong != NULL)
            {
                pre = walker;
                cur = pre->nextSong;
                pre->nextSong = cur->nextSong;
                cout << endl << "\"" << cur->songName << "\" removed from playlist!" << endl;
                delete cur;

                valid = true;
            }
            else
            {
                walker = walker->nextSong;
                index++;
            }


        }
  
        if (valid == false)
            cout << endl << "Song not found";
    }
    else
    {
        cout << endl << "Song not found";
    }   
}
