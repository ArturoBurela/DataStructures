#include <iostream>
#include "Stack.h"
#include "Queue.h"
#define SIZE 20

int main()
{
  Stack the_stack(10);
  Queue the_queue(7);
  the_stack.pop();
  the_stack.top();
  the_stack.print();
  the_stack.push(1);
  the_stack.push(2);
  the_stack.push(3);
  the_stack.push(4);
  std::cout << the_stack.pop() << std::endl;
  the_stack.print();
  the_stack.push(9);
  the_stack.push(9);
  the_stack.push(9);
  the_stack.push(9);
  the_stack.push(9);
  the_stack.push(9);
  the_stack.push(9);
  std::cout << the_stack.top() << std::endl;
  the_stack.print();
  std::cout << the_stack.pop() << std::endl;
  std::cout << the_stack.pop() << std::endl;
  std::cout << the_stack.pop() << std::endl;
  std::cout << the_stack.pop() << std::endl;
  std::cout << the_stack.top() << std::endl;
  the_queue.pop();
  the_queue.top();
  the_queue.print();
  the_queue.push(1);
  the_queue.push(2);
  the_queue.push(3);
  the_queue.push(4);
  the_queue.push(5);
  the_queue.print();
  std::cout << the_queue.pop() << std::endl;
  std::cout << the_queue.top() << std::endl;
  the_queue.print();
  std::cout << the_queue.top() << std::endl;
  std::cout << the_queue.pop() << std::endl;
  std::cout << the_queue.pop() << std::endl;
  std::cout << the_queue.pop() << std::endl;
  std::cout << the_queue.pop() << std::endl;
  std::cout << the_queue.pop() << std::endl;
	return 0;
}
