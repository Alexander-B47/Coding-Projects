// Name: Alexander Bordenet
// File Name: prog3.cpp
// Date: 10/11/23
// Program Description: This program should read an html file and convert it into a text file or display it to the Console.

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int SIZE = 800; //this is 800 not 600 because Dr. Hossain said I can change it

/**********************************************************
* Name: readHtmlFile
* Description: This function will take in the name of a html file and an array to put the contents in.
* Input: Two character arrays, one htmlFileName and the other htmlFContents.
* Output: An integer that holds the number of characters in the html file.
**********************************************************/
int readHtmlFile(char htmlFileName[] , char htmlFContents[])
{
	int numChars = 0;
	ifstream inFile(htmlFileName);
	//ifstream inFile("test.html");

	//this loop will continue to grab the next character in the file while there is a character to grab
	while (inFile) 
	{
		//gets the next character including spaces
		inFile.get(htmlFContents[numChars]); 
		numChars++;
	}
	inFile.close();
	return numChars;
}

/**********************************************************
* Name: convertHtmlFile
* Description: This function will convert a passed html char array into a text array
* Input: Two character arrays, one is htmlFContent which has the unchanged contents of the html file
* The other array, txtConverted, will hold the updated character array without the html tags in it
* The final thing is an integer that will hold the size of the html array
* Output: Integer txtSize, this will be the size of the txtConverted number of characters.
**********************************************************/
int convertHtmlFile(char htmlFContent[], char txtConverted[], int htmlSize)
{
	int txtSize = 0;
	
	//This for loop will go up until index is at the end of the html array
	for (int index = 0; index < htmlSize; index++)
	{
		//This if will look for the start of any html tag
		if (htmlFContent[index] == '<')
		{
			//This will keep increasing the index while it is inside the html tag
			while (htmlFContent[index] != '>')
			{
				//This if will see if the html tag was a new line tag
				if (htmlFContent[index + 1] == 'b' && htmlFContent[index + 2] == 'r')
				{
					txtConverted[txtSize] = '\n';
					txtSize++;
				}
				

				index++;
			}
		}
		else 
		{
			txtConverted[txtSize] = htmlFContent[index];
			txtSize++;
		}
		
		
	}
	return txtSize;
}

/**********************************************************
* Name: outputTxtFile
* Description: This function will take in an output stream, a character array, and the size of the text.
* It will either display the text to the console or output the array to a txt file
* Input: ofstream outFile , char txtArray[] , int txtSize. 
* outFile will output the txt if that option is chosen, txtArray is what will be either displayed or put into a file,
* txtSize is the number of chars in txtArray.
* Output: None
**********************************************************/
void outputTxtFile(ofstream &outFile, char txtArray[], int txtSize)
{
	//use is_open to print to check if the file as been opened, otherwise display to the screen
	if (outFile.is_open() == true)
	{
		for (int index = 0; index < txtSize-1; index++)
		{
			if(txtArray[index] != '\0')
				outFile << txtArray[index];
		}
	}
	else
	{
		for (int index = 0; index < txtSize-1; index++)
		{
			if (txtArray[index] != '\0')
				cout << txtArray[index];
		}
	}
}

int main()
{
	char htmlFileContent[SIZE];
	char htmlConverted[SIZE];
	char fileName[20];
	char txtFileName[20];
	int numOfChars = 0;
	int txtSize = 0;
	int userChoice = 0;
	ofstream outFile;

	//This is the menu and will take the choices and the file names from the user
	cout << "HTML/TXT Converter\n"
		 << "------------------\n"
		 << "1) Display TXT to Console\n"
		 << "2) Write TXT to file\n"
		 << "Enter your choice: ";
	cin >> userChoice;
	cout << "Enter html filename: ";
	cin.ignore();
	cin.getline(fileName , 20);

	//This will take in the file name and take it in and they will convert it
	numOfChars = readHtmlFile(fileName, htmlFileContent);
	txtSize = convertHtmlFile(htmlFileContent, htmlConverted, numOfChars);

	//Option 1: this is what will display the message to the console instead of the file
	if (userChoice == 1)
	{
		outputTxtFile(outFile, htmlConverted, txtSize);
	}
	//Option 2: this is what will display the message to a file instead of to the console
	else if (userChoice == 2)
	{
		cout << "Enter the txt filename: ";
		cin.getline(txtFileName , 20);
		outFile.open(txtFileName);
		outputTxtFile(outFile, htmlConverted, txtSize);
	}
		
	return 0;
}
