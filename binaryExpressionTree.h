#pragma once

#include "binaryTree.h"
#include <string>

using namespace std;

class binaryExpressionTree : public binaryTreeType<string>
{
public:

	bool search(const string& searchItem) const override;

	void insert(const string& insertItem) override;

	void deleteNode(const string& deleteItem) override;

	void buildExpressionTree(string postfixExpression);

	double evaluateExpressionTree();




private:


	double evaluateExpressionTree(nodeType<string>* );



};