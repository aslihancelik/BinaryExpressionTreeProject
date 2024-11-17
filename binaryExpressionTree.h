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

	double evaluateExpressionTree(const nodeType<string>*); //???????????????????????




private:


	double evaluateExpressionTree(nodeType<string>* );



};