// Alexander Bordenet
// Prog2.cpp
// 9/20/23
// Encrypt a text document two ways into separate text files

#include <iostream>
#include <fstream>
using namespace std;

const int SIZE = 1000;

/**********************************************************
* Name: readFile.
* Description: This function is called to store a text document as a single c string
* Input: A c string
* Output: Nothing
**********************************************************/
void readFile(char text[])
{
    int num = 0;
    ifstream inFile("plain.txt");
    inFile.get(text[num]);

    while (inFile)
    {
        num++;
        inFile.get(text[num]);
        
    }
    text[num] = '\0';
    
}

/**********************************************************
* Name: showArray.
* Description: This function takes in the encrypted/decrypted word and displays it to the screen
* Input: A c string
* Output: Nothing
**********************************************************/
void showArray(char text[])
{
    cout << endl;
    for (int i = 0; i < strlen(text); i++)
        cout << text[i];
}
/**********************************************************
* Name: getCaesarCipher.
* Description: This function takes in the decrypted word and converts it to an encrypted version by shifting the character 13 places.
* Input: A c-string with the unencrypted message, and an empty c-string to store the converted message.
* Output: Nothing
**********************************************************/
void getCaesarCipher(char text[], char encrypted[])
{
    int num = 0;
 
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] != ' ')
        {
            num = (text[i] - 65 + 13) % 26;
            encrypted[i] = (num + 65);

        }
        else
            encrypted[i] = ' ';
    }
}
/**********************************************************
* Name: getAtbashCipher.
* Description: This function takes in the decrypted word and converts it to an encrypted version by swapping the character with its opposite character in the alphabet
* like A = Z , B = Y , etc.
* Input: A c-string with the unencrypted message, and an empty c-string to store the converted message
* Output: Nothing
**********************************************************/
void getAtbashCipher(char text[], char encrypted[])
{
    int num = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] != ' ')
        {
            num = text[i] - 65;
            encrypted[i] = ((25 - num)) + 65;
        }
        else
            encrypted[i] = ' ';
    }
}

int main()
{
    char untext[SIZE];
    char encrypted[SIZE] = { '\0'};
    
    cout << "Here is the unencrypted message: " << endl;
    readFile(untext); //takes in the base text
    showArray(untext); //prints the base text
    
    //Caeser cipher
    cout << endl << "\nHere is the message encrypted using ROT 13: \n";
    getCaesarCipher(untext , encrypted); //converts the base text into the encrypted c string
    showArray(encrypted); //prints the encrypted c string
    ofstream outFile ("cipher1.txt"); //sets up the output to file
    outFile << encrypted; //outputs the c string to the file

    //atBash cipher
    cout << endl << "\nHere is the message encrypted using Atbash encryption: \n";
    getAtbashCipher(untext, encrypted); //converts the base text into the encrypted c string
    showArray(encrypted); // prints the encrypted c string
    cout << "\n";
    ofstream outFile2("cipher2.txt"); //sets up the output to file
    outFile2 << encrypted; //outputs the c string to the file
    return 0;
}