#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>

struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
  Node *root;

  Node *insertHelper(Node *node, int value) {
    if (!node) {
      return new Node(value);
    }

    if (value < node->data) {
      node->left = insertHelper(node->left, value);
    } else if (value > node->data) {
      node->right = insertHelper(node->right, value);
    } else {
      std::cout << "Value already exists: " << value << std::endl;
    }

    return node;
  }

  void clearHelper(Node *node) {
    if (!node)
      return;

    clearHelper(node->left);
    clearHelper(node->right);
    delete node;
  }

public:
  BinarySearchTree() : root(nullptr){};

  ~BinarySearchTree() { clear(); };

  void insert(int value) { root = insertHelper(root, value); }

  bool search(int value) const {
    Node *current = root;

    while (current) {
      if (value == current->data) {
        return true;
      } else if (value < current->data) {
        current = current->left;
      } else {
        current = current->right;
      }
    }

    return false;
  }

  bool isEmpty() const { return root == nullptr; }

  void clear() {
    clearHelper(root);
    root = nullptr;
  }
};

#endif