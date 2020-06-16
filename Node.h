#pragma once
#include <iostream>
using namespace std;

class Node
{
public:
	//CONSTRUCTOR 
	Node(unsigned int tempValue, Node* tempLeft, Node* tempRight);
	//ACCESSOR METHODS FOR NODES ON TREE
	unsigned int getValue() const;
	Node* getRight() const;
	Node* getLeft() const;
	//MUTATOR METHODS FOR NODES ON TREE
	void setValue(unsigned int tempValue);
	void setLeft(Node* tempLeft);
	void setRight(Node* tempRight);

private:
	unsigned int value;
	Node* left;
	Node* right;

};
