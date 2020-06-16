#include <iostream>
#include "Tree.h"
#include <string>
#include <array>
using namespace std;
//CONSTRUCTOR FOR TREE
Tree::Tree()
{
	
}
//METHOD TO INSERT A NODE INTO THE TREE
void Tree::Insert(Node* tempNode, unsigned int tempValue)
{
	//IF THE NODES VALUE IS GREATER THAN THAT OF THE WANTED VALUE, TO THE NODE ON THE LEFT AND RECALL THE METHOD
	if (tempNode->getValue() > tempValue)
	{
		if (tempNode->getLeft() != NULL)
		{
			Insert(tempNode->getLeft(), tempValue);
		}
		else
		{
			//WHEN YOU ARRIVE AT THE END NODE, INSERT THE NEW VALUE
			tempNode->setLeft(new Node(tempValue, NULL, NULL));
			leftHeight++;
		}
	}
	//IF THE NODES VALUE IS LESS THAN THAT OF THE WANTED VALUE, GO TO THE NODE ON THE RIGHT AND RECALL THE METHOD
	if (tempNode->getValue() < tempValue)
	{
		if (tempNode->getRight() != NULL)
		{
			Insert(tempNode->getRight(), tempValue);
		}
		else
		{
			//WHEN YOU ARRIVE AT THE END NODE, INSERT THE NEW VALUE
			tempNode->setRight(new Node(tempValue, NULL, NULL));
			rightHeight++;
		}
	}
	//CHECK TO SEE IF THE LEFT HEIGHT OR THE RIGHT HEIGHT IS GREATER AND MAKE THAT YOUR HEIGHT
	if (leftHeight > rightHeight)
	{
		height = leftHeight;
	}
	else
	{
		height = rightHeight;
	}
}
//funciton to insert a value into the tree if the root is not yet created
void Tree::Insert(unsigned int tempValue)
{
	if (root == NULL)
	{
		root=new Node(tempValue, NULL, NULL);
	}
	else
	{
		Insert(root, tempValue);
	}
}
//method to find a given number in the tree
unsigned int Tree::find(Node* theNode, unsigned int toFind)
{
	//IF THE NODE'S VALUE IS NULL RETURN -1
	unsigned int returnValue = 0;
	if (theNode == NULL)
	{
		cout << -1 << ' '<<"\n";
		returnValue = NULL;
		return returnValue;
	}
	//IF THE NODES VALUE IS EQUAL TO THE WANTED VALUE, PRINT IT 
	if (theNode->getValue() == toFind)
	{
		cout << theNode->getValue() <<' ';
		returnValue= theNode->getValue();
	}
	//IF THE NODES VALUE IS LESS THAN THE ONE WANTED, GO TO THE NODE ON THE RIGHT AND RECALL METHOD
	if (theNode->getValue() < toFind)
	{
		cout << theNode->getValue()<<' ';
		return find(theNode->getRight(), toFind);

	}
	//IF THE NODES VALUE IS GREATER THAN THE ONE WANTED, GO TO THE NODE ON THE LEFT AND RECALL THE METHOD
	if (theNode->getValue() > toFind)
	{
		cout << theNode->getValue() << ' ';
		return find(theNode->getLeft(), toFind);
	}
	cout << returnValue << "\n";
	return returnValue;
}
//driver method for the find function
unsigned int Tree::find(unsigned int toFind)
{
	return find(root, toFind);
}

//print to print vertically
void Tree::print(Node* tempNode)
{
	
	if (tempNode == NULL)
		return;
	//recursive method on the right child
	if (tempNode->getRight() != NULL)
	{
		counter++;
		print(tempNode->getRight());
		counter--;
	}
	//print the value of the current node 
	for (int i = 0; i < counter; i++)
	{
		cout << "--";
	}
	cout <<tempNode->getValue() << "\n";

	//call method on the left node
	if (tempNode->getLeft() != NULL)
	{
		counter++;
		print(tempNode->getLeft());
		counter--;
	}
}

//driver method for the vertical print function
void Tree::print()
{
	return print(root);
}

//VERTICAL PRINT IS ACTUALLY HORIZONTAL PRINT
void Tree::verticalPrint(Node* tempNode, string *&theArray)
{
	//id the node is null, do nothing
	if (tempNode != NULL)
	{
		//horizontal counter increases and decreases based on the level of the tree
		//if there is a left node to go into, go into it and call the verticalprint again
		if (tempNode->getLeft() != NULL)
		{
			horizontalCounter++;
			verticalPrint(tempNode->getLeft(), theArray);
			horizontalCounter--;
		
		}
		//loop through array
		for (int i = 0; i < height-1; i++)
		{
			//if the horizontal counter is equal to i add the value of the current node to the array index
			if (i == horizontalCounter)
			{
				//if thevalue at temp node is greater than just add it to the array
				if (tempNode->getValue() > 9)
				{
					string theadd = to_string(tempNode->getValue());
					theArray[i] += theadd;
				}
				else
				{	//if thevalue at temp node is 9 or less add an extra space to the string 
					string toadd = to_string(tempNode->getValue());
					theArray[i] += toadd + "  ";
				}
			}
			else
			{
				theArray[i] += "  ";
			}
		}

		//call method on the right node, same as when called on left node above
		if (tempNode->getRight() != NULL)
		{
			horizontalCounter++;
			verticalPrint(tempNode->getRight(), theArray);
			horizontalCounter--;
		}
	}
}

void Tree::verticalPrint()
{
	//create an array of size height and pass it into private print function
	string  *myArray = new string[height];
	verticalPrint(root, myArray);
	//print out the array 
	for (int i = 0; i < height - 1; i++)
	{
		cout << myArray[i] << "\n";
	}
}