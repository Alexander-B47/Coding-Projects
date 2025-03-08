#include <iostream>
#include <algorithm>
#include <fstream>
#include "Tree.h"
using namespace std;

// Alexander Bordenet
// 11/7/24
// Program 4: To build a binary search tree and to use it to display english words and their latin equivalents


//*********************************************************************************
// breakdownCommas: This function will take in a string of english words that are
// separated by comma(s): englishWords, and the corresponding latin word: latin
// and the Tree object to insert them into: t. It will break the string down and 
// then insert each de-comma-ed segment of the string into the Tree object using
// the passed latin word for each.
// Input: Two strings, and a Tree object passed by reference
// Output: the new english words with one less comma
//*********************************************************************************
string breakdownCommas(string englishWords , string latin , Tree & t) {
	int commaPosition = englishWords.find(',');
	string newEnglishWords = " ";
	string singleEnglish = englishWords.substr(0, commaPosition);
	t.insertWords(singleEnglish, latin);
	newEnglishWords = englishWords.substr(commaPosition + 1, englishWords.length());
	return newEnglishWords;
}

// Reads in each of the english and latin words into the tree
void readFile(string fileName, Tree & t) {
	ifstream inFile = ifstream(fileName);

	while (inFile) {
		string line;
		getline(inFile, line);
		int colonPosition = line.find(':');
		string latin = line.substr(0, colonPosition);
		
		if (latin.empty())
			break;
		
		string englishWords = line.substr(colonPosition+1, line.length());
		if (englishWords.find(',') < englishWords.length()) {
			while (englishWords.find(',') < englishWords.length())
			{
				englishWords = breakdownCommas(englishWords, latin , t);
			}
			t.insertWords(englishWords, latin);
		}
		else
		{
			t.insertWords(englishWords, latin);
		}
	}
}

int main(int argc , char * argv[]) {

	Tree timmy;
	string fileName;
	fileName.append(argv[1]);
	readFile(fileName, timmy);
	timmy.inOrderDisplay();
	timmy.deleteBST();

	return 0;
}