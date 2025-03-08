#include "Tree.h"
#include <string>
#include<iostream>
using namespace std;


Tree::Tree()
{
	root = nullptr;
}

void Tree::deleteBST() {
	root = deleteBST(root);
}

// Displays the binary tree's day(english words, list of latin words)
void Tree::inOrderDisplay(treeNode* root)
{
	if (root != NULL)
	{
		inOrderDisplay(root->left);
		cout << root->english << ": " << flush;
		root->latin->displayList();
		cout << flush;
		inOrderDisplay(root->right);
	}
}

// Helper function just used to call insertBST from the driver, who doesn't have access to root for recursion
void Tree::insertWords(string english, string latin) {
	root = insertBST(root, english, latin);
}

void Tree::inOrderDisplay() {
	inOrderDisplay(root);
}

treeNode* Tree:: insertBST(treeNode* root, string newEnglishWord, string newLatinWord)
{
	if (root == NULL)
	{
		root = new treeNode;
		root->english = newEnglishWord;
		root->left = root->right = NULL;
		root->latin = new List;
		root->latin->insertNode(newLatinWord);
		return root;
	}
	else if (newEnglishWord.compare(root->english) == 0) {
		root->latin->insertNode(newLatinWord);
	}
	else if (newEnglishWord < root->english)
		root->left = insertBST(root->left, newEnglishWord , newLatinWord);
	else // if (newEnglishWord >= root->english)
		root->right = insertBST(root->right, newEnglishWord, newLatinWord);
	return root;
}

treeNode* Tree::deleteBST(treeNode* root) 
{
	if (root == nullptr)
		return NULL;
	root->left = deleteBST(root->left);
	root->right = deleteBST(root->right);
	root->latin->deleteList();
	delete root;
	root = nullptr;
	return root;
}