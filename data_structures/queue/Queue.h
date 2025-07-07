#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

struct Node {
  int data;
  Node *next;

  Node(int value) {
    data = value;
    next = nullptr;
  }
};

class Queue {
private:
  Node *head;
  Node *tail;
  int size;

public:
  Queue() {
    head = nullptr;
    tail = nullptr;
    size = 0;
    std::cout << "The queue is constructed." << std::endl;
  };

  ~Queue() {
    while (head) {
      Node *temp = head;
      head = head->next;
      delete temp;
    }
    std::cout << "The queue is destructed." << std::endl;
  }

  Queue &enqueue(int value) {
    Node *newNode = new Node(value);

    if (!tail) {
      head = newNode;
    } else {
      tail->next = newNode;
    }

    tail = newNode;
    ++size;
    return *this;
  }

  int dequeue() {
    if (!head) {
      std::cout << "There are no items in the queue." << std::endl;
      return -1;
    }

    int value = head->data;
    Node *temp = head;
    head = head->next;
    delete temp;

    if (!head) {
      tail = nullptr;
    }

    --size;
    return value;
  }

  int front() const {
    if (!head) {
      std::cout << "There are no items in the queue." << std::endl;
      return -1;
    };

    return head->data;
  }

  bool isEmpty() const { return size == 0; }

  int length() const { return size; }

  void clear() {
    while (head) {
      Node *temp = head;
      head = head->next;
      delete temp;
    }

    tail = nullptr;
    size = 0;
  }

  void print() const {
    if (!head) {
      std::cout << "Queue is empty." << std::endl;
      return;
    }

    Node *current = head;

    std::cout << "Queue: ";

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
