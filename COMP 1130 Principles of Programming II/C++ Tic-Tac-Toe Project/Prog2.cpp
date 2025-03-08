// Name: Alexander Bordenet
// File name: Prog2.cpp
// Date: 9/6/23
// Purpose: Make a working Tic Tac Toe game

#include <ctime>
#include <cmath>
#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
using namespace std;

const int NUMROWS = 3;
const int NUMCOLS = 3;
const int SIZE = 26;


//This function takes in the empty gameboard array and makes every value null to represent an empty space
void initializeBoard(char gameBoard[][NUMCOLS])
{
	for (int row = 0; row < NUMROWS; row++)
	{
		for (int col = 0; col < NUMCOLS; col++)
		{
			gameBoard[row][col] = '\0';
		}
	}
}

//This function takes in the gameboard array and uses it to print out the gameboard to the screen
void printBoard(char gameBoard[][NUMCOLS])
{
	cout << endl;
	for (int row = 0; row < NUMROWS; row++)
	{
		for (int col = 0; col < NUMCOLS; col++)
		{	
			if (col == 0 || col == 1)
			{
				if (gameBoard[row][col] == 'X')
					cout << " X |";
				else if (gameBoard[row][col] == 'O')
					cout << " O |";
				else
					cout << "   |";
			}
			else if (col == 2)
			{
				if (gameBoard[row][col] == 'X')
					cout << " X ";
				else if (gameBoard[row][col] == 'O')
					cout << " O ";
				else
					cout << "   ";
			}
			
		}
		if(row <2)
			cout << endl << "-----------" << endl;
	}
	cout << endl;
}

//This will check in each row on whether a player wins or not then returns the correct value.
int horizontalCheck(char gameBoard[][NUMCOLS])
{
	for (int row = 0; row < NUMROWS; row++)
	{

		if (gameBoard[row][0] == gameBoard[row][1] && gameBoard[row][1] == gameBoard[row][2])
		{
			if (gameBoard[row][0] == 'X')
				return 1;
			else if (gameBoard[row][0] == 'O')
				return 2;
		}
	}
	for (int col = 0; col < NUMCOLS; col++)
	{
		for (int row = 0; row < NUMROWS; row++)
		{
			if (gameBoard[row][col] == '\0')
				return 3;
		}
	}
	return 0;
}

//This will check in each column on whether a player wins or not then returns the correct value. 
int verticalCheck(char gameBoard[][NUMCOLS])
{
	for (int col = 0; col < NUMCOLS; col++)
	{
		
		if (gameBoard[0][col] == gameBoard[1][col] && gameBoard[1][col] == gameBoard[2][col])
		{
			if (gameBoard[0][col] == 'X')
				return 1;
			else if (gameBoard[0][col] == 'O')
				return 2;
		}
	}
	for (int col = 0; col < NUMCOLS; col++)
	{
		for (int row = 0; row < NUMROWS; row++)
		{
			if (gameBoard[row][col] == '\0')
				return 3;
		}
	}
	return 0;
}
//This will check in each diagonal on whether a player wins or not then returns the correct value.
int diagonalCheck(char gameBoard[][NUMCOLS])
{
	if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2])
	{
		if (gameBoard[0][0] == 'X')
			return 1;
		else if (gameBoard[0][0] == 'O')
			return 2;
	}
	else if (gameBoard[2][0] == gameBoard[1][1] && gameBoard[0][2] == gameBoard[1][1])
	{
		if (gameBoard[2][0] == 'X')
			return 1;
		else if (gameBoard[2][0] == 'O')
			return 2;
	}
	for (int col = 0; col < NUMCOLS; col++)
	{
		for (int row = 0; row < NUMROWS; row++)
		{
			if (gameBoard[row][col] == '\0')
				return 3;
		}
	}
	return 0;
}

//This function will return a value from 0 to 3 where; 0 is for a tie, 1 is for a win to player1, 2 is for a win to player2, and 3 means that the game continues
int getStatus(char gameBoard[][NUMCOLS])
{
	int status = 3;
	
	status = horizontalCheck(gameBoard);
	if (status == 3)
	{
		status = verticalCheck(gameBoard);
		if (status == 3)
			status = diagonalCheck(gameBoard);
	}
	return status;
}


void makeMove(char gameBoard[][NUMCOLS], int turn, string name)
{
	int rowPos, colPos;
	char xOrO = 0;
	bool validMove = false;

	//Determines if the player's move should be an O or an X
	if (turn == 1)
		xOrO = 'X';
	else if (turn == 0)
		xOrO = 'O';

	
	
		//Asks for the move
		cout << endl << name << " please specify your move: ";
		cin >> rowPos;
		cin >> colPos;

		//checks whether the move is allowed or not
		if (gameBoard[rowPos - 1][colPos - 1] != 'X' && gameBoard[rowPos - 1][colPos - 1] != 'O')
		{ 
			cout << "\n";
			cout << "your move is column: " << colPos << " row: " << rowPos << endl;
			gameBoard[rowPos - 1][colPos - 1] = xOrO;
			
		}
		else
		{
			while (validMove == false)
			{
				cout << "\n";
				cout << "your move is invalid please enter a valid move\n";
				cout << endl << name << " please specify your move: ";
				cin >> rowPos;
				cin >> colPos;

				if (gameBoard[rowPos - 1][colPos - 1] != 'X' && gameBoard[rowPos - 1][colPos - 1] != 'O')
				{
					cout << "\n";
					cout << "your move is column: " << colPos << " row: " << rowPos << endl;
					gameBoard[rowPos - 1][colPos - 1] = xOrO;
					break;
				}
			}
		}
	
}
int main()
{
	
	//Initialize all of the variables and the board
	srand((unsigned)time(0));
	char gameBoard[NUMROWS][NUMCOLS];
	initializeBoard(gameBoard);
	char player1Name [SIZE];
	char player2Name [SIZE];
	char player2Swap[SIZE];
	int player1 = 1;
	int player2 = 0;
	int gameStatus = 3;
	int turnOrder = rand() % 2;

	//Asks for the players names
	cout << "First player, enter your name: ";
	cin >> player1Name;
	cout << "Second player, enter your name: ";
	cin >> player2Name;

	//This is for the "coin toss" to determine who goes first
	if (turnOrder == 1)
	{
		cout << endl << player1Name << " has won the coin toss.\n";
	}
	else if (turnOrder == 0)
	{
		cout << endl << player2Name << " has won the coin toss.\n";
		strcpy_s(player2Swap, player1Name);
		strcpy_s(player1Name, player2Name);
		strcpy_s(player2Name, player2Swap);
	}

	//This while loop runs through each players turn until the game ends
	printBoard(gameBoard);
	while (gameStatus == 3)
	{
		//This asks for the first players turn, prints the new board, then checks for if they win or not
		makeMove(gameBoard, player1, player1Name);
		printBoard(gameBoard);
		gameStatus = getStatus(gameBoard);
		if (gameStatus == 1)
		{
			cout << "\nPlayer 1 wins!";
			break;
		}
		else if (gameStatus == 2)
		{
			cout << "\nPlayer 2 wins!";
			break;
		}
		else if (gameStatus == 0)
		{
			cout << "\nThe game is a tie!";
			break;
		}
		else if (gameStatus == 3)
			cout << "\nThe game continues!\n\n";

		//This asks for the second players turn, prints the new board, then checks for if they win or not
		makeMove(gameBoard, player2, player2Name);
		printBoard(gameBoard);
		gameStatus = getStatus(gameBoard);
		if (gameStatus == 1)
			cout << "\nPlayer 1 wins!";
		else if (gameStatus == 2)
			cout << "\nPlayer 2 wins!";
		else if (gameStatus == 0)
			cout << "\nThe game is a tie!";
		else if (gameStatus == 3)
			cout << "\nThe game continues!\n\n";
		
	}
	return 0;
}