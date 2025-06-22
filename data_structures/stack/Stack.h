#ifndef STACK_H
#define STACK_H

#include <iostream>

struct Node {
  int data;
  Node *next;

  Node(int value) {
    data = value;
    next = nullptr;
  }
};

class Stack {
private:
  Node *top;
  int size;

public:
  Stack() {
    top = nullptr;
    size = 0;
    std::cout << "The stack is constructed." << std::endl;
  }

  ~Stack() {
    while (top) {
      Node *temp = top;
      top = top->next;
      delete temp;
    }
    std::cout << "The stack is destructed." << std::endl;
  }

  Stack &push(int value) {
    Node *newNode = new Node(value);
    newNode->next = top;
    top = newNode;
    ++size;
    return *this;
  }

  int pop() {
    if (!top) {
      std::cout << "The stack is empty." << std::endl;
      return -1;
    }

    int val = top->data;
    Node *temp = top;
    top = top->next;
    delete temp;
    --size;
    return val;
  }

  int peek() const {
    if (!top) {
      std::cout << "The stack is empty." << std::endl;
      return -1;
    }

    return top->data;
  }

  int length() const { return size; }

  bool isEmpty() const { return size == 0; }

  void clear() {
    while (top) {
      Node *temp = top;
      top = top->next;
      delete temp;
    }

    size = 0;
  }

  void print() const {
    if (!top) {
      std::cout << "The stack is empty." << std::endl;
      return;
    }

    Node *current = top;

    while (current) {
      std::cout << "[" << current->data << "]";

      if (current->next) {
        std::cout << " -> ";
      }

      current = current->next;
    }

    std::cout << std::endl;
  }
};

#endif