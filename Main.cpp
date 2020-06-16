#include <iostream>
#include "Tree.h"
#include "Node.h"
using namespace std;

int main()
{
	//CREATE TREE
	Tree tree = Tree();

	//INSERT NODES IN ORDER GIVEN
	tree.Insert(8);
	tree.Insert(4);
	tree.Insert(12);
	tree.Insert(2);
	tree.Insert(6);
	tree.Insert(10);
	tree.Insert(14);
	tree.Insert(1);
	tree.Insert(9);
	tree.Insert(11);

	//CALL FIND METHOD
	tree.find(4);
	tree.find(5);
	tree.find(6);
	tree.find(10);
	tree.find(9);

	//CALL VERTICAL PRINT
	tree.print();
	//CALL HORIZONTAL PRINT
	tree.verticalPrint();
}