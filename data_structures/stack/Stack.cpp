#include "Stack.h"
#include <iostream>

int main() {
  Stack stack;

  stack.push(10).push(15).push(20).push(25);
  stack.print();

  std::cout << "Stack length: " << stack.length() << std::endl;
  std::cout << "Stack peek: " << stack.peek() << std::endl;

  stack.pop();
  stack.print();

  std::cout << "Is empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

  stack.clear();

  std::cout << "Stack length: " << stack.length() << std::endl;
  std::cout << "Is empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

  return 0;
}
