#include "binaryExpressionTree.h"
#include <stack>
#include <cstring>

// Implement the search function
bool binaryExpressionTree::search(const string& searchItem) const
{
    // Implementation of search logic here
    return false;  // Example placeholder
}

// Implement the insert function
void binaryExpressionTree::insert(const string& insertItem)
{
    // Implementation of insert logic here
}

// Implement the deleteNode function
void binaryExpressionTree::deleteNode(const string& deleteItem)
{
    // Implementation of deleteNode logic here
}


void binaryExpressionTree::buildExpressionTree(string postfixExpression) {

    // Step 1: Initialize a stack of pointers to binary tree nodes
    stack<nodeType<string>*> treeStack;

    // Step 2: Convert the string to a character array
    char* expression = new char[postfixExpression.length() + 1];
    strcpy(expression, postfixExpression.c_str());

    // Step 3: Loop through each character in the expression
    string currentToken;  // To accumulate digits or characters for operands

    for (int i = 0; expression[i] != '\0'; ++i) {

        char currentChar = expression[i];

        //If the character is a digit, accumulate it into currentToken
        if (isdigit(currentChar)) {
            currentToken += currentChar;
        }
        //If the character is a space and currentToken is not empty
        else if (currentChar == ' ' && !currentToken.empty()) {
            /*Create a node
                Convert the token from a character array to a string
                Store the string in the info field
                Push the new node onto the stack*/

            // Create a node for the number
            nodeType<string>* newNode = new nodeType<string>;

            // Store the operand (number) 
            newNode->info = currentToken; 
            newNode->lLink = nullptr;
            newNode->rLink = nullptr;
            treeStack.push(newNode);  // Push the node onto the stack
            currentToken.clear();     // Clear the current token for the next operand

        }// If the character is an operator
        else if(currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/') {
        
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
            }else{
                //missing right operand for operator
                cerr << "Error- Stack is empty" << endl;
            }
        
        }
        else {
            cerr << "Error- unsupported token" << endl;
        }
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
    return evaluateExpressionTree(this->root);   //?????
}


double binaryExpressionTree::evaluateExpressionTree(nodeType<string>* node) {

    return evaluateExpressionTree(node);
}