#include "PlayList.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int numSongs = 0; //Global for number of Songs

/***********************************************************************************
* This will ask the user for the name of the txt file that stores the playlist data
* It will use this to create a linked list of songs. Insertion at the end.
* input : A string containing the file name
* output: A Song pointer head.
***********************************************************************************/
Song* PlayList::buildPlaylist(string fileName)
{
    Song* head = nullptr;
    Song* tail = nullptr;
    string songArtist;
    int colonPos;

    ifstream inFile(fileName);
    if (inFile.fail())
        cout << "File not found/failed to open" << endl;
        
    head = new Song;
    getline(inFile, songArtist);
    colonPos = songArtist.find(":");
    head->songName = songArtist.substr(0, colonPos);
    head->artistName = songArtist.substr(colonPos + 1);
    head->nextSong = nullptr;
    tail = head;
    numSongs++;

    while (getline(inFile, songArtist))
    {
        //Temp node to build playlist
        Song* pnew = new Song;

        //Use find to locate the : so you can break up the song and artist
        colonPos = songArtist.find(":");
        pnew->songName = songArtist.substr(0, colonPos);
        pnew->artistName = songArtist.substr(colonPos + 1);
        pnew->nextSong = nullptr;
        tail->nextSong = pnew;
        tail = pnew;
        pnew = NULL;
        numSongs++;
    }
    inFile.close();
    cout << endl << "Playlist created!" << endl;
    return head;
}

/*****************************************************************
* This will take in the head of the linked list for the playlist
* and will use it to display each member of the list in order
* while also being formatted.
* Input : Song pointer head
* Output: None.
*****************************************************************/
void PlayList:: showPlaylist(Song* head)
{
    Song* walker = nullptr;
    walker = head;
    int index = 1;

    cout << endl << "-------------------------------------------" << endl;
    while (walker != nullptr)
    {
        cout << index << ") " << setw(25) << left << walker->songName;
        cout << walker->artistName << endl;
        walker = walker->nextSong;
        index++;
    }
    cout << "-------------------------------------------" << endl;
}

/**********************************************************
* This function will use the head pointer to
* find the specific song name to be displayed to the screen
* Input : Song pointer head
* Output: None
**********************************************************/
void PlayList:: playSong(Song* head)
{
    int songNum = 0;
    Song* walker = head;
    bool valid = false;
    int index = 1;

    cout << endl << "Enter the song number: ";
    cin >> songNum;
    while (walker != nullptr && valid == false)
    {
        if (index == songNum)
        {
            valid = true;
            cout << endl << "Now playing \"" << walker->songName << "\" by " << walker->artistName << endl;
        }
        walker = walker->nextSong;
        index++;
    }
    if (valid == false)
        cout << endl << "Song not found" << endl;
}

/************************************************************************
* This function will use the head pointer by reference
* and go through the playlist until it finds the song
* that needs to be deleted. It will also reconnect the playlist together
* Input : Song pointer head passed by reference
* Output: None
************************************************************************/
void PlayList:: removeSong(Song*& head)
{
    int songNumb;
    int index = 1;
    bool valid = false;
    Song* pre  = nullptr,
        * cur  = nullptr,
        * temp = nullptr,
        * walker = head;


    cout << endl << "Enter the song number: ";
    cin >> songNumb;

    // Delete from beginning
    if (songNumb == 1)
    {
        temp = head;
        head = head->nextSong;
        cout << endl << "\"" << temp->songName << "\" removed from playlist!" << endl;
        delete temp;
        numSongs--;
    }
    // Delete target node
    else if (songNumb != 0)
    {
        while (walker != NULL && valid == false)
        {
            if (index == songNumb - 1 && walker->nextSong != NULL)
            {
                pre = walker;
                cur = pre->nextSong;
                pre->nextSong = cur->nextSong;
                cout << endl << "\"" << cur->songName << "\" removed from playlist!" << endl;
                delete cur;
                numSongs--;
                valid = true;
            }
            else
            {
                walker = walker->nextSong;
                index++;
            }
        }
        if (valid == false)
            cout << endl << "Song not found" << endl;
    }
    else
        cout << endl << "Song not found" << endl;
}

/*******************************************************************
* This will take in the head pointer to the list Passed by reference
* to move a certain number of nodes to the beginning of the list
* Input : Song pointer head passed by reference
* Output: None
*******************************************************************/
void PlayList::rearrangePlaylist(Song*& head)
{
    int firstSong,
        secondSong,
        curSong = 1;
    cout << endl << "Enter your starting song number (1-" << numSongs << "): ";
    cin >> firstSong;
    cout << endl << "Enter your ending song number (" <<firstSong << "-" << numSongs << "): ";
    cin >> secondSong;
    cout << endl;

    // Validation for song choices
    if (firstSong > numSongs || firstSong < 1)
    {
        cout << "Invalid option." << endl;
        return;
    }
    if (secondSong < firstSong || secondSong > numSongs || secondSong < 1)
    {
        cout << "Invalid option." << endl;
        return;
    }

    // Find new first node and node before
    if (firstSong == 1)
    {
        cout << "Playlist rearranged." << endl;
        return;
    }

    Song* walker = head;
    while (walker->nextSong != nullptr && curSong != firstSong-1)
    {
        //step walker forward a song
        walker = walker->nextSong;
        curSong++;
    }
    Song* prev = walker;
    walker = walker->nextSong;

    // find end of block to be moved
    Song* walker2 = head;
    curSong = 1;
    while (walker2->nextSong != nullptr && curSong != secondSong)
    {
        //step walker2 forward a song
        walker2 = walker2->nextSong;
        curSong++;
    }
    
    Song* tempHead = head; //preserves old head
    head = walker; //moves head to point to new start 
    prev->nextSong = walker2->nextSong; //previous of the new start points to next song after end of block
    walker2->nextSong = tempHead; // end of block points to old head

    cout << "Playlist rearranged." << endl;
}

/********************************************************
* This function will display the options the user has to
* interact with the playlist
* Input : None
* Output: Integer ans storing the user's choice
********************************************************/
int PlayList::showOptions()
{
    int ans;
    cout << endl << "1) Show the playlist" << endl;
    cout << "2) Play a song" << endl;
    cout << "3) Remove a song" << endl;
    cout << "4) Rearrange playlist" << endl;
    cout << "5) Quit" << endl;
    cout << "Enter your option: ";
    cin >> ans;
    return ans;
}
