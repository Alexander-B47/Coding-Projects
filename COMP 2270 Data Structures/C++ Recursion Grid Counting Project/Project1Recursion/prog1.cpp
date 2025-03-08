#include <fstream>
#include <iostream>
using namespace std;

const int BOARDSIZE = 8; 

struct Board2D { // used for storing the board so I can return the board
	char arr[BOARDSIZE][BOARDSIZE];
};

void printBoard(Board2D board)
{
	for (int row = 0; row < BOARDSIZE; row++)
	{
		for (int col = 0; col < BOARDSIZE; col++)
		{
			cout << board.arr[col][row];
		}
		cout << endl;
	}
}
Board2D grabBoard()
{
	Board2D board{};
	ifstream inputFile("board.txt");
	if (!inputFile)
	{
		cout << "Failed to open file" << endl;
	}

	int row = 0;
	int col = 0;
	while (inputFile)
	{
		if (row > BOARDSIZE - 1)
		{
			row = 0;
			col++;
		}
		else{
			inputFile >> board.arr[row][col];
			row++;
		}
	}
	inputFile.close();

	return board;
}

int countWhite(char board[][BOARDSIZE], int row, int col)
{
	//cout << board[row][col] << endl;
	if (board[row][col] == 'b') // is not white so don't bother checking
		return 0;
	else { // is white so check the adjacent squares
		if (row == BOARDSIZE - 1 && col == BOARDSIZE - 1)
			return 0;
		cout << "Checking right: " << "new row: " << row + 1 << "     col: " << col << " Value: " << board[row + 1][col] << endl;
		if (row + 1 < BOARDSIZE && board[row][col] == 'w') //check right
			return 1 + countWhite(board, row + 1, col);

		cout << "Checking down: " << "     row: " << row << " new col: " << col + 1 << " Value: " << board[row][col + 1] << endl;
		if (col + 1 < BOARDSIZE && board[row][col] == 'w') //check down
			return 1 + countWhite(board, row, col + 1);

		cout << "Checking left: " << "     row: " << row << " new col: " << col - 1 << " Value: " << board[row - 1][col] << endl;
		if (row - 1 > 0 && board[row][col] == 'w') //check left
			return 1 + countWhite(board, row - 1, col);

		cout << "Checking up:    " << "new row: " << row - 1 << "    col: " << col << " Value: " << board[row][col - 1] << endl;
		if (col - 1 > 0 && board[row][col] == 'w')  //check up
			return 1 + countWhite(board, row, col - 1);
	}
	return 0; //failed each check, no more white
	
}

int main()
{
	int areaCount = 0;
	int whiteC = 0;
	Board2D board{};
	board = grabBoard();
	printBoard(board);
	cout << endl;
	//cout << "Number of cells in areas: ";
	cout << board.arr[0][3] << endl;
	whiteC += 1 + countWhite(board.arr, 0, 3);
	cout << whiteC << endl;

	/*for (int row = 0; row < BOARDSIZE; row++) {
		for (int col = 0; col < BOARDSIZE; col++) {
			whiteC = 0;
			if (board.arr[col][row] == 'w') {
				cout << "Found white at: " << row << " " << col << endl;
				//board.arr[col][row] = 'b';
				whiteC = countWhite(board.arr, col, row);
				//areaCount++;
				cout << whiteC << " " << endl;
			}
		}
	}*/

	cout << endl << "Number of areas: " << areaCount << endl;

	return 0;
}