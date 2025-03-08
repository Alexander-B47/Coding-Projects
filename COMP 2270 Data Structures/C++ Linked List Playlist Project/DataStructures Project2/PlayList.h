#pragma once
#include <string>
using namespace std;

extern int numSongs;

// Struct to build the linked list
struct Song
{
    string songName;
    string artistName;
    Song* nextSong;

};

// Class containing the functions to interact with the linked list
class PlayList
{
public:
    Song* buildPlaylist(string);
    void  showPlaylist(Song*);
    void  playSong(Song*);
    void  removeSong(Song*&);
    void  rearrangePlaylist(Song*&);
    int   showOptions();
};

