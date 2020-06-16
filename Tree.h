#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

class Tree 
{
public: 
	Tree();	
	void Insert(unsigned int tempValue);
	unsigned int find(unsigned int toFind);
	void print();
	void verticalPrint();
	
private: 
	//DECALRATIONS FOR METHODS, FURTHER EXPLANATIONS IN .CPP FILE
	Node* root;
	unsigned int find(Node* theNode, unsigned int toFind);
	void Insert(Node* tempNode, unsigned int tempValue);
	void print(Node* tempNode);
	int counter = 0;
	//VERTICAL PRINT IS ACTUALLY HORIZONTAL PRINT
	void verticalPrint(Node* tempNode, string *&theArray);
	int leftHeight = 0;
	int rightHeight = 0;
	int height = 0;
	int horizontalCounter = 0;
	
};