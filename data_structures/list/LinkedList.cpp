#include "LinkedList.h"
#include <iostream>

int main() {
  LinkedList list;

  list.push_back(10).push_back(20).push_back(30);
  list.push_front(5).push_front(1);

  list.print();

  list.insert(2, 15).insert(0, 0);
  list.print();

  std::cout << "Element at index 3: " << list.get(3) << std::endl;

  std::cout << "Contains 15? " << (list.contains(15) ? "Yes" : "No")
            << std::endl;
  std::cout << "Index of 20: " << list.findIndex(20) << std::endl;

  list.pop_front();
  list.pop_back();
  list.remove(2);
  list.print();

  std::cout << "Is empty? " << (list.isEmpty() ? "Yes" : "No") << std::endl;
  std::cout << "Length: " << list.length() << std::endl;

  list.clear();
  list.print();

  return 0;
}
