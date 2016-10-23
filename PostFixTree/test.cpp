#include <iostream>
#include "Postfix.h"
int main()
{
  Postfix expression;
  std::cout << "Infix: 9-3*2^2+5" << std::endl;
    expression.setInfix("9-3*2^2+5");
    expression.convertToPostfix();
    std::cout << "Postfix: " << expression.getPostfix() << std::endl;
    return 0;
}
