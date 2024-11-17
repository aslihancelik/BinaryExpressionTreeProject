// binaryExpressionTree.h
// This header file defines the binaryExpressionTree class, which extends the binaryTreeType class to represent
// and evaluate expression trees using postfix notation. It provides methods to build the expression tree from
// a postfix expression, evaluate the tree, and override unused search, insert, and deleteNode functions from
// the base binaryTreeType class.


#pragma once

#include "binaryTree.h"
#include <string>

using namespace std;

class binaryExpressionTree : public binaryTreeType<string>
{
public:
	// Overriding pure virtual functions with no-op implementations
	// 
	//  search function
	bool search(const string& searchItem) const
	{
		return false;  
	}

	// insert function
	void insert(const string& insertItem)
	{
	}

	// deleteNode function
	void deleteNode(const string& deleteItem)
	{
	}

	void buildExpressionTree(string postfixExpression);

	double evaluateExpressionTree();

private:


	double evaluateExpressionTree(nodeType<string>* );



};