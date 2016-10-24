/*
Arturo Burela A01019906

Program that creates Postfix Trees and Evaluates them

*/

#include <iostream>
#include "Postfix.h"
int main()
{
  Postfix expression;
  expression.setInfix("9-3*2^2+5+4^2^3");
  expression.postfixTree();
  std::cout << "Infix: 9-3*2^2+5" << std::endl;
  std::cout << "Postfix: " << expression.getPostfix() << std::endl;

  return 0;
}
