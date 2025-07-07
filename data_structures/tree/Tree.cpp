#include "Tree.h" // make sure the path is correct
#include <iostream>

int main() {
  BinarySearchTree bst;

  bst.insert(50);
  bst.insert(30);
  bst.insert(70);
  bst.insert(20);
  bst.insert(40);
  bst.insert(60);
  bst.insert(80);
  bst.insert(30);

  std::cout << "Search 40: " << (bst.search(40) ? "Found" : "Not found")
            << std::endl;
  std::cout << "Search 90: " << (bst.search(90) ? "Found" : "Not found")
            << std::endl;

  bst.clear();
  std::cout << "Tree cleared." << std::endl;

  std::cout << "Search 50 after clearing: "
            << (bst.search(50) ? "Found" : "Not found") << std::endl;

  return 0;
}
