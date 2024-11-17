// binaryExpressionTree.cpp
// This file implements the binaryExpressionTree class methods to build and evaluate expression trees
// based on postfix expressions. It includes:
// - A method to construct an expression tree by parsing a postfix string.
// - Recursive evaluation of the tree to compute the result.
// - Error handling for invalid expressions, and division by zero etc.


#include "binaryExpressionTree.h"
#include <stack>
#include <cstring>
//#include <cctype>


void binaryExpressionTree::buildExpressionTree(string postfixExpression) {

    // Initialize a stack of pointers to binary tree nodes
    stack<nodeType<string>*> treeStack;

    // Convert the string to a character array
    char* expression = new char[postfixExpression.length() + 1];
    //strcpy(expression, postfixExpression.c_str());
    strcpy_s(expression, postfixExpression.length() + 1, postfixExpression.c_str()); // Copy the string to the char array

    // Loop through each character in the expression
    string currentToken;  // To accumulate digits or characters for operands

    for (int i = 0; expression[i] != '\0'; ++i) {
    //for (size_t i = 0; i < postfixExpression.length(); ++i) {
        
        //char currentChar = postfixExpression[i];
        char currentChar = expression[i];
        //If the character is a digit, accumulate it into currentToken
        if (isdigit(currentChar)) {
            currentToken += currentChar;
        }
        //If the character is a space and currentToken is not empty
        else if (currentChar == ' ' && !currentToken.empty()) {

            // Create a node for the number
            nodeType<string>* newNode = new nodeType<string>;

            // Store the operand (number) 
            newNode->info = currentToken;
            newNode->lLink = nullptr;
            newNode->rLink = nullptr;
            treeStack.push(newNode);  // Push the node onto the stack
            currentToken.clear();     // Clear the current token for the next operand

        }// If the character is an operator
        else if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/') {

            // Create a node for the number
            nodeType<string>* newNode = new nodeType<string>;

            // Store the operator 
            newNode->info = string(1, currentChar);  // Store the operator (as a string)

            newNode->lLink = nullptr;
            newNode->rLink = nullptr;

            if (!treeStack.empty()) {
                // Set the right child
                newNode->rLink = treeStack.top();
                treeStack.pop();
                if (!treeStack.empty()) {
                    // Set the left child
                    newNode->lLink = treeStack.top();
                    treeStack.pop();
                    treeStack.push(newNode);  // Push the node onto the stack
                }
                else {
                    //missing left operand for operator
                    cerr << "Error- Stack is empty" << endl;
                }
            }
            else {
                //missing right operand for operator
                cerr << "Error- Stack is empty" << endl;
            }

        }
      /*  else {
            cerr << "Error- unsupported token" << endl;
        }*/
    }

    // Check if the stack is still not empty after popping the root
    if (!treeStack.empty()) {
        root = treeStack.top(); // The final node is the root of the expression tree
        treeStack.pop();

        if (!treeStack.empty()){
            cout << "Error: Stack should be empty after processing the expression. Invalid expression." << endl;
            root = nullptr;  // Set root back to null if there's an error
        }
        else {
            cout << "Expression tree built successfully!" << endl;
        }

    }
    else {
        cout << "Error: Stack is empty, there was an issue building the expression tree." << endl;
    }

    // Clean up the allocated memory for the character array
    delete[] expression;
}


double binaryExpressionTree::evaluateExpressionTree() {
    return evaluateExpressionTree(this->root);   
}


double binaryExpressionTree::evaluateExpressionTree(nodeType<string>* node) {

    // If the tree has only one node (leaf node)
    if (node->lLink == nullptr && node->rLink == nullptr) {
        // Convert the value in the info field to double and return it
        return stod(node->info);
    }

    //If the tree has more than one node and the root contains an operator
    // Recursively evaluate the left and right subtrees
    double x = evaluateExpressionTree(node->lLink);  // Left operand
    double y = evaluateExpressionTree(node->rLink);  // Right operand

    // Apply the operator at the current node 
    if (node->info == "+") {
        return x + y;
    }
    else if (node->info == "-") {
        return x - y;
    }
    else if (node->info == "*") {
        return x * y;
    }
    else if (node->info == "/") {
        if (y == 0) {
            cerr << "Error: Division by zero" << endl;
            return 0;
        }
        return x / y;
    }
    else {
        cerr << "Error: Unsupported operator " << node->info << endl;
        return 0;
    }
}



