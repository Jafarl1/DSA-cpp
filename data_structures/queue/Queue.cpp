#include "Queue.h"
#include <iostream>

int main() {
  Queue queue;

  queue.enqueue(10).enqueue(20).enqueue(30);
  queue.print();

  std::cout << "Front: " << queue.front() << std::endl;
  std::cout << "Length: " << queue.length() << std::endl;

  std::cout << "Removed: " << queue.dequeue() << std::endl;
  queue.print();

  std::cout << "Removed: " << queue.dequeue() << std::endl;
  queue.print();

  std::cout << "Removed: " << queue.dequeue() << std::endl;
  queue.print();

  std::cout << "Is empty? " << (queue.isEmpty() ? "Yes" : "No") << std::endl;

  queue.enqueue(5).enqueue(15).enqueue(25);
  queue.print();

  queue.clear();
  queue.print();

  return 0;
}