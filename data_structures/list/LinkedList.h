#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>

struct Node {
  int data;
  Node *next;

  Node(int value) {
    data = value;
    next = nullptr;
  }
};

class LinkedList {
private:
  Node *head;
  int size;

public:
  LinkedList() {
    head = nullptr;
    size = 0;
  }

  ~LinkedList() {
    while (head) {
      Node *next = head->next;
      delete head;
      head = next;
    }
  }

  LinkedList &push_front(int value) {
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    ++size;
    return *this;
  }

  LinkedList &push_back(int value) {
    if (!head) {
      head = new Node(value);
      ++size;
      return *this;
    }

    Node *current = head;

    while (current->next) {
      current = current->next;
    }

    current->next = new Node(value);
    ++size;
    return *this;
  }

  LinkedList &insert(int index, int value) {
    if (index < 0 || index > size) {
      std::cout << "Incorrect index." << std::endl;
      return *this;
    }

    Node *newNode = new Node(value);

    if (index == 0) {
      newNode->next = head;
      head = newNode;
    } else {
      Node *current = head;

      for (int i = 0; i < index - 1; ++i) {
        current = current->next;
      }

      newNode->next = current->next;
      current->next = newNode;
    }

    ++size;
    return *this;
  }

  int pop_front() {
    if (!head) {
      std::cout << "There are no items in the list." << std::endl;
      return -1;
    }

    int value = head->data;
    Node *temp = head;
    head = head->next;
    delete temp;
    --size;
    return value;
  }

  int pop_back() {
    if (!head) {
      std::cout << "There are no items in the list." << std::endl;
      return -1;
    }

    int value;

    if (!head->next) {
      value = head->data;
      delete head;
      head = nullptr;
    } else {
      Node *current = head;

      while (current->next->next != nullptr) {
        current = current->next;
      }

      value = current->next->data;
      delete current->next;
      current->next = nullptr;
    }

    --size;
    return value;
  }

  LinkedList &remove(int index) {
    if (index < 0 || index >= size) {
      std::cout << "Incorrect index." << std::endl;
      return *this;
    }

    if (index == 0) {
      Node *temp = head;
      head = head->next;
      delete temp;
    } else {
      Node *current = head;

      for (int i = 0; i < index - 1; ++i) {
        current = current->next;
      }

      Node *temp = current->next;
      current->next = temp->next;
      delete temp;
    }

    --size;
    return *this;
  }

  int get(int index) {
    if (index < 0 || index >= size) {
      std::cout << "Incorrect index." << std::endl;
      return -1;
    }

    Node *current = head;

    for (int i = 0; i < index; ++i) {
      current = current->next;
    }

    return current->data;
  }

  bool contains(int value) {
    Node *current = head;

    while (current) {
      if (current->data == value) {
        return true;
      }

      current = current->next;
    }

    return false;
  }

  int findIndex(int value) {
    Node *current = head;
    int index = 0;

    while (current) {
      if (current->data == value) {
        return index;
      }

      current = current->next;
      ++index;
    }

    return -1;
  }

  bool isEmpty() { return size == 0; }

  int length() { return size; }

  void clear() {
    while (head) {
      Node *temp = head;
      head = head->next;
      delete temp;
    }

    size = 0;
  }

  void print() {
    if (!head) {
      std::cout << "List is empty." << std::endl;
      return;
    }

    Node *current = head;

    std::cout << "LinkedList: ";

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