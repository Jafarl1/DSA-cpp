#include <iostream>

using namespace std;

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
      cout << "Incorrect index." << endl;
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
      cout << "There are no items in the list." << endl;
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
      cout << "There are no items in the list." << endl;
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
      cout << "Incorrect index." << endl;
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
      cout << "Incorrect index." << endl;
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
      cout << "List is empty." << endl;
      return;
    }

    Node *current = head;

    cout << "LinkedList: ";

    while (current) {
      cout << "[" << current->data << "]";

      if (current->next) {
        cout << " -> ";
      }

      current = current->next;
    }

    cout << endl;
  }
};

int main() {
  LinkedList list;

  list.push_back(10).push_back(20).push_back(30);
  list.push_front(5).push_front(1);

  list.print();

  list.insert(2, 15).insert(0, 0);
  list.print();

  cout << "Element at index 3: " << list.get(3) << endl;

  cout << "Contains 15? " << (list.contains(15) ? "Yes" : "No") << endl;
  cout << "Index of 20: " << list.findIndex(20) << endl;

  list.pop_front();
  list.pop_back();
  list.remove(2);
  list.print();

  cout << "Is empty? " << (list.isEmpty() ? "Yes" : "No") << endl;
  cout << "Length: " << list.length() << endl;

  list.clear();
  list.print();

  return 0;
}
