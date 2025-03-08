#pragma once
#include<string>
#include "List.h"
using namespace std;

struct treeNode {
	string english;
	List* latin;
	treeNode* left;
	treeNode* right;
};

class Tree
{
private:
	treeNode* root;

public:
	Tree();
	treeNode* insertBST(treeNode*, string, string);
	void inOrderDisplay(treeNode*);
	void insertWords(string, string);
	void inOrderDisplay();
	treeNode* deleteBST(treeNode*);
	void deleteBST();

};

