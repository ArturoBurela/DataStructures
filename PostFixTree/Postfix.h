/*
Class to convert a string to postfix from infix, it may create trees and evaluate them
Arturo Burela
A01019906
*/

#ifndef POSTFIX_H
#define POSTFIX_H

#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include "Stack.h"
#include "BinarySearchTree.h"

using namespace std;

class Postfix {
    private:
        std::string infix;
        std::string postfix;
        //Added the BinaryTree variable
        BinarySearchTree<char> treepostfix;
        int computeOperator(int num1, int num2, char sign);
        int comparePrecedence(char op1, char op2);
        //Methods to classify chars in numbers and operators
        bool isOp(char c);
        bool isNum(char c);
        //Evaluates the Postfix tree
        int recursiveTreeEvaluate(TreeNode<char> * root);
    public:
        Postfix () {}
        Postfix (std::string _infix) { infix = _infix; }
        void setInfix (std::string _infix) { infix = _infix; }
        void convertToPostfix();
        void postfixTree();
        int evaluate();
        std::string getPostfix() { return postfix; }
        void recursiveTreeEvaluate();
};

//Creates the postfix tree
void Postfix::postfixTree(){
  //Make sure the infix is converted to a Postfix string
  convertToPostfix();
  //Create a stack to hold tree nodes
  Stack<TreeNode<char>*> treestack;
  //Create a new treenode pointer
  TreeNode<char> * treenode = nullptr;
  //Make a loop to go over the string
  for (int j = 0; j < postfix.length(); j++) {
    //Check if the character is a number
    if (isNum(postfix.at(j))) {
      //Create a new treenode<char> with data of the number
      treenode= new TreeNode<char>(postfix.at(j));
      //Push the treenode to the stack
      treestack.push(treenode);
    }
    //Check if is is a valid operator
    if (isOp(postfix.at(j))) {
      //Create a new treenode with the operator as data
      treenode = new TreeNode<char>(postfix.at(j));
      //Get the top node and set as the right, it gets deleted from stack
      treenode->setRight(treestack.popD());
      //Get the next stack node and set as the left
      treenode->setLeft(treestack.popD());
      //Push the new node that now has pointers to left and right
      treestack.push(treenode);
    }
  }
  //Set the root of the tree to the las pointer created
  treepostfix.setRoot(treenode);
  //Print the tree
  treepostfix.printTree();
}

//Used to call the recursive method
void Postfix::recursiveTreeEvaluate(){
  std::cout << "Postfix tree evaluation result: "<< recursiveTreeEvaluate(treepostfix.getRoot()) << std::endl;
}

//Evaluates the tree
int Postfix::recursiveTreeEvaluate(TreeNode<char> * root){
  if (root->getLeft()==nullptr && root->getRight()== nullptr) { //If both next nodes are null we are in a leaf
    //As we are on a leaf simple return the value, as the data is char we cast from ascii
    return (int)root->getData() - 48;
  }else{
    //If nodes aren't null is an operator, we call compute with char operator and the recursive evaluate of both sides
    return computeOperator(recursiveTreeEvaluate(root->getLeft()),recursiveTreeEvaluate(root->getRight()),root->getData());
  }
}

//Methods to classify chars in numbers and operators
bool Postfix::isOp(char c){
  if (c=='+'||c=='*'||c=='^'||c=='-'||c=='/'||c=='%') {
    return true;
  }else{
    return false;
  }
}

bool Postfix::isNum(char c){
  if (c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9'||c=='0') {
    return true;
  }else{
    return false;
  }
}

int Postfix::computeOperator(int num1, int num2, char sign)
{
    if (sign == '^')
        return pow(num1, num2);
    else if (sign == '*')
        return num1 * num2;
    else if (sign == '/')
        return num1 / num2;
    else if (sign == '%')
        return num1 % num2;
    else if (sign == '+')
        return num1 + num2;
    else if (sign == '-')
        return num1 - num2;
    else
        return 0;
}

int Postfix::comparePrecedence(char op1, char op2)
{
    char operators[] = { '^', '*', '/', '%', '+', '-' };
    int precedence[] = {   3,   2,   2,   2,   1,   1 };
    int size = sizeof(operators) / sizeof(operators[0]);
    int value1, value2;

    for (int i=0; i<size; i++)
    {
        if (op1 == operators[i])
            value1 = precedence[i];
        if (op2 == operators[i])
            value2 = precedence[i];
    }
    // Returns the difference in the precedence
    // If larger than 0, value 1 has higher precedence
    return value1 - value2;
}

void Postfix::convertToPostfix()
{
    int size = infix.length();
    Stack<char> conversionStack;
    Node<char> * item;
    char token;

    postfix = "";   // Initialize postfix as an empty string

    for (int i=0; i<size; i++)
    {
        token = infix[i];
        // Case 1: numbers
        if (token >= '0' && token <= '9')
            postfix += token;
        // Case 2: (
        else if (token == '(')
            conversionStack.push(token);
        // Case 3: )
        else if (token == ')')
        {
            while (conversionStack.top()->getData() != '(')
            {
                // Get the top element from the stack
                item = conversionStack.pop();
                // Append the data it holds to the postfix string
                postfix += item->getData();
                delete item;
            }
            // Get rid of the '('
            item = conversionStack.pop();
            delete item;
        }
        // Case 4: )
        else if (token == '^' || token == '*' || token == '/' ||
                 token == '%' || token == '+' || token == '-')
        {
            // This one has higher precedence
            if ( conversionStack.isEmpty() ||
                conversionStack.top()->getData() == '(' ||
                comparePrecedence(token, conversionStack.top()->getData()) > 0 )
            {
                conversionStack.push(token);
            }
            else
            {
                while ( !conversionStack.isEmpty() &&
                    comparePrecedence(token, conversionStack.top()->getData()) <= 0 )
                {
                    item = conversionStack.pop();
                    postfix += item->getData();
                    delete item;
                }
                conversionStack.push(token);
            }
        }   // Case 4
    }   // for
    // Pop anything left in the stack after finishing the string
    while ( !conversionStack.isEmpty() )
    {
        item = conversionStack.pop();
        postfix += item->getData();
        delete item;
    }
}

int Postfix::evaluate()
{
    return 0;
}

#endif
