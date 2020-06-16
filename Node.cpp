#include <iostream>
#include "Node.h"
using namespace std;

//CONSTRUCTOR FOR NODE
Node::Node(unsigned int tempValue, Node* tempLeft, Node* tempRight)
{
	value = tempValue;
	left = tempLeft;
	right = tempRight;
}

//ACCESSOR METHODS FOR NODE OF TREE
unsigned int Node::getValue() const
{
	return value;
}

Node* Node::getRight() const
{
	return right;
}

Node* Node::getLeft() const
{
	return left;
}

//MUTATOR METHODS FOR NODES ON TREE
void Node::setValue(unsigned int tempValue)
{
	value = tempValue;
}

void Node::setLeft(Node* tempLeft)
{
	left = tempLeft;
}
void Node::setRight(Node* tempRight)
{
	right = tempRight;
}