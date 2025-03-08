//Name: Alexander Bordenet
//Date: 11/1/23
//File name: prog6.cpp
//Description: Asks for a file name from the user. Uses the file to display basketball player stats
//and lets the user ask to display a specific player's stats

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int SIZE = 100;

struct Player
{
    string name;
    int gamesPlayed;
    int fieldGoalsMade;
    int fieldGoalsAtt;
    int threePointsMade;
    int threePointsAtt;
    int freeThrowsMade;
    int freeThrowsAtt;
    float fieldGoalPer;
    float threePointPer;
    float freeThrowPer;
    float avgPts;

    Player()
    {
        gamesPlayed = 0;
        fieldGoalsMade = 0;
        fieldGoalsAtt = 0;
        threePointsMade = 0;
        threePointsAtt = 0;
        freeThrowsMade = 0;
        freeThrowsAtt = 0;
        fieldGoalPer = 0;
        threePointPer = 0;
        freeThrowPer = 0;
        avgPts = 0;
    }

};


int readData(Player[]);
void calculateStats(Player[], int);
void sortPlayers(Player[], int);
void displayStats(Player[], int);
void searchPlayer(Player[], int);

int main()
{
    int numPlayers = 0;
    Player playerArr[SIZE];

    numPlayers = readData(playerArr);
    calculateStats(playerArr , numPlayers);
    sortPlayers(playerArr, numPlayers);
    displayStats(playerArr, numPlayers);
    searchPlayer(playerArr, numPlayers);
    
    return 0;
}


/********************************************
* Name: readData
* Description: This function asks the user for the name of a file containing basketball player statistics
* It will store them in an array if the file opens successfully.
* Input: a Player array called players
* Output: The number of players stored in the array
********************************************/
int readData(Player players [])
{
    int numPlayers = 0;
    string fileName;

    cout << "Please enter the input filename: ";
    cin >> fileName;
    cout << endl;

    ifstream inFile(fileName);

    if (inFile)
    {
        //takes info
        //gets the name and stops at the colon
        while (getline(inFile, players[numPlayers].name, ':'))
        {
            //gets the games played
            inFile >> players[numPlayers].gamesPlayed;
            
            //gets field goals made
            inFile >> players[numPlayers].fieldGoalsMade;
            
            //gets field goals attempted
            inFile >> players[numPlayers].fieldGoalsAtt;
            
            //gets three pointers made
            inFile >> players[numPlayers].threePointsMade;
            
            //gets three pointers attempted
            inFile >> players[numPlayers].threePointsAtt;
            
            //gets free throws made
            inFile >> players[numPlayers].freeThrowsMade;
            
            //gets free throws attempted
            inFile >> players[numPlayers].freeThrowsAtt;
            
            inFile.ignore();
            numPlayers++;
        }
    }
    else
        cout << "\nError opening file" << endl;


    return numPlayers;
}
/*******************************************
* Name: calculateStats
* Description: This will take in the Player array and number of players and
* calculates averages for various stats
* Input: Player array players , int numPlayers
* Output: None
*******************************************/
void calculateStats(Player players[], int numPlayers)
{
    int fieldGoals = 0;

    for (int i = 0; i < numPlayers; i++)
    {
        //calculate field goal percentage
        if (players[i].fieldGoalsAtt == 0)
            players[i].fieldGoalPer = 0.0;
        else
            players[i].fieldGoalPer = (float(players[i].fieldGoalsMade) / players[i].fieldGoalsAtt);
        
        //calculate three pointer percentage
        if (players[i].threePointsAtt == 0)
            players[i].threePointPer = 0.0;
        else
            players[i].threePointPer = (float(players[i].threePointsMade) / players[i].threePointsAtt);

        //calculate free throw percentage
        if (players[i].freeThrowsAtt == 0)
            players[i].freeThrowPer = 0.0;
        else
            players[i].freeThrowPer = (float(players[i].freeThrowsMade) / players[i].freeThrowsAtt);

        //calculate average points
        
        fieldGoals = players[i].fieldGoalsMade - players[i].threePointsMade;
        if (players[i].gamesPlayed == 0)
            players[i].avgPts = 0.0;
        else
        {
            players[i].avgPts = (fieldGoals * 2) + (players[i].threePointsMade * 3) + (players[i].freeThrowsMade);
            players[i].avgPts = float(players[i].avgPts) / players[i].gamesPlayed;
        }
        fieldGoals = 0;
    }
}
/***********************************
* Name: sortPlayers
* Description: This function will take in the players array and sort them in descending order 
* based on the average points for each player
* Input: Player array players , int numPlayers
* Output: None
***********************************/
void sortPlayers(Player players[], int numPlayers)
{
    int maxElement;
    int index;
    

    for (maxElement = numPlayers - 1; maxElement > 0; maxElement--)
    {
        for (index = 0; index < maxElement; index++)
        {
            if (players[index].avgPts < players[index + 1].avgPts)
            {
                Player temp;
                temp = players[index];
                players[index] = players[index + 1];
                players[index + 1] = temp;
            }
        }
    }
}

/*******************************
* Name: searchPlayer
* Description: This function will take in the players array
* and ask the user to enter a name of a player
* then it will display all of that players statistics
* Input: Player players[] , int numPlayers
* Output: None
*******************************/
void searchPlayer(Player players[], int numPlayers)
{
    string yOrN = " ";
    string playerName = " ";
    int index = 0;
    int i = 0;
    bool found = false;

    
    cout << endl << "Do you want to search any player? (y/n) ";
    cin >> yOrN;
    cout << endl;
    if (yOrN == "y")
    {
        while (yOrN == "y")
        {
            cout << "Enter the player name: ";
            cin.ignore();
            getline(cin, playerName);
            cout << endl;

            while (found == false && i < numPlayers)
            {
                if (players[i].name == playerName)
                {
                    index = i;
                    found = true;
                }
                i++;
            }
            if(found == true)
            {
                cout << endl << "Number of games played: " << players[index].gamesPlayed << endl;
                cout << "Field goal %: " << players[index].fieldGoalPer << endl;
                cout << "Three pointer %: " << players[index].threePointPer << endl;
                cout << "Free throw %: " << players[index].freeThrowPer << endl;
                cout << "Average points per game: " << players[index].avgPts << endl;
            }
            else
                cout << "Player not found or you did not spell the name correctly." << endl;

            cout << endl << "Do you want to search another player? (y/n) ";
            
            cin >> yOrN;
            if (yOrN == "n")
                cout << "Bye!" << endl;
            found = false;
            i = 0;
        }
    }
    else if (yOrN == "n")
        cout << endl << "Bye!" << endl;

}

void displayStats(Player players[], int numPlayers)
{
    
    cout << setw(20) << left << "Name" << setw(7) << left << "FG%" << setw(7) << left << "TP%" << setw(7) << left <<  "FT%" << setw(8) << right << "Average" << endl;
    cout << "-------------------------------------------------" << endl;
    for (int i = 0; i < numPlayers; i++)
    {
        cout << fixed << setprecision(2);
        cout << setw(20) << left  << players[i].name
             << setw(7) << left << players[i].fieldGoalPer 
             << setw(7) << left << players[i].threePointPer 
             << setw(7) << left << players[i].freeThrowPer 
             << setw(8) << right << setprecision(1) << players[i].avgPts 
             << endl;
    }
}