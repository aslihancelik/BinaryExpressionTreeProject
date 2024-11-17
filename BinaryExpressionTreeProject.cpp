// BinaryExpressionTreeProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// This program reads postfix expressions from an input file, builds a binary expression tree for each, 
// evaluates the result, and writes the results to an output file.


#include <iostream>
#include <fstream>
#include <string>
#include "binaryExpressionTree.h" 

using namespace std;

int main() {
    // Input and output file names
    const string inputFileName = "RpnData.txt";
    const string outputFileName = "expressionResults.txt";

    // Open the input file
    ifstream inputFile(inputFileName);
    if (!inputFile) {
        cerr << "Error: Unable to open input file: " << inputFileName << endl;
        return 1;
    }

    // Open the output file
    ofstream outputFile(outputFileName);
    if (!outputFile) {
        cerr << "Error: Unable to open output file: " << outputFileName << endl;
        return 1;
    }

    // Create an instance of binaryExpressionTree
    binaryExpressionTree expressionTree;

    string postfixExpression;
    while (getline(inputFile, postfixExpression)) {
        // Remove leading/trailing spaces from the input line
        postfixExpression.erase(0, postfixExpression.find_first_not_of(" "));
        postfixExpression.erase(postfixExpression.find_last_not_of(" ") + 1);

        // Skip empty lines
        if (postfixExpression.empty()) continue;

        // Destroy any existing tree before building a new one
        expressionTree.destroyTree();

        try {
            // Build the expression tree
            cout << "Processing expression: " << postfixExpression << endl;
            expressionTree.buildExpressionTree(postfixExpression);

            // Evaluate the expression tree
            double result = expressionTree.evaluateExpressionTree();
            cout << "Result: " << result << endl;

            // Write the result to the output file
            outputFile << postfixExpression << " = " << result << endl;
        }
        catch (const exception& e) {
            cerr << "Error while processing expression: " << postfixExpression << endl;
            cerr << e.what() << endl;
            outputFile << postfixExpression << " = ERROR" << endl;
        }
    }

    // Close the files
    inputFile.close();
    outputFile.close();

    cout << "Results written to " << outputFileName << endl;

    return 0;
}
