/*
Class to convert a string to postfix from infix
Arturo Burela
A01019906
*/
#ifndef POSTFIX_H
#define POSTFIX_H

#include <iostream>
#include <string>
#include "Stack.h"

class Postfix {
private:
  std::string infix;
  std::string postfix;

  int computeOperator(int num1, int num2, char sign);
  int comparePrecedence(char op1, char op2);
public:
  Postfix (std::string _infix) { infix = _infix; }
  void setInfix (std::string _infix) { infix = _infix; }
  void convertToPostfix();
  int evaluate();
};

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
  //Returns the difference in the precedence
  //If <0 value1 has higher precedence
  return value1 - value2;
}

void Postfix::convertToPostfix(){
  int size = infix.length();
  postfix = ""; //Empty string
  Stack<char> conversionStack;
  Node<char> * item;
  char token;
  for (int i = 0; i < size; i++) {
    token = infix[i];
    //CASE 1: Numbers
    if (token >= '0' && token <= '9') {
      postfix += token;
    }
    //CASE 2:
    else if (token == '(') {
      conversionStack.push(token);
    }
    //Case 3:
    else if (token == ')') {
      while (conversionStack.top()->getData() != '('){
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
      //CASE 4: )
      else if (token == '^' || token == '*' || token == '/' || token == '%' || token == '+' || token == '-') {
        //Determine the higher precedence
        if (conversionStack.isEmpty() || conversionStack.top()->getData() == '(' || comparePrecedence(token, conversionStack.top()->getData()) > 0) {
          conversionStack.push(token);
        }else{
          while (comparePrecedence(token, conversionStack.top()->getData()) <= 0) {
            item = conversionStack.pop();
            postfix += item->getData();
            delete item;
          }
          conversionStack.push(token);
        }
      }
    }
    while (!conversionStack.isEmpty()) {
      item = conversionStack.pop();
      postfix += item->getData();
      delete item;
    }
}

int Postfix::evaluate(){
  
}

#endif
