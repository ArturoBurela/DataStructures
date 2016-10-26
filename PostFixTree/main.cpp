/*
Arturo Burela A01019906

Program that creates Postfix Trees and Evaluates them

*/

#include <iostream>
#include "Postfix.h"
int main()
{
  //Create new postfix
  Postfix expression;
  //Store the infix
  string infix = "";
  while (infix!="q") { //Continue asking if infix is not q
    std::cout << std::endl << std::endl << "ENTER THE INFIX TO CONVERT: (q to quit)" << std::endl;
    std::cin >> infix;
    if (infix=="q") {
      std::cout << "Goodbye!" << std::endl;
      break;
    }
    //Set infix
    expression.setInfix(infix);
    //Print all the postfix data
    expression.print();
  }
  return 0;
}
