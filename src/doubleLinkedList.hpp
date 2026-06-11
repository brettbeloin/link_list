#pragma once
#include <print>
#include <sstream>
#include <stdexcept>
#include <string>

template <typename T> class doubleLinkList {
private:
  struct Node {
    T data;
    Node *next;
    Node(T value) : data(value), next(nullptr) {}
  };

  Node *head;
  Node *tail;
  int size;

public:
  doubleLinkList() : head(nullptr), tail(nullptr), size(0) {}
  ~doubleLinkList() {
    Node *node = head;
    Node *temp;

    for (int i = 0; i <= size - 1; i++) {
      temp = node->next;
      delete node;
      node = temp;
    }

    head = nullptr;
    tail = nullptr;
    size = 0;
  }

  void Add(T val) {
    Node *new_node = new Node(val);
    if (!head) {
      head = tail = new_node;
    } else {
      tail->next = new_node;
      tail = new_node;
    }
    size++;
  }

  void Insert(T val, int index) {
    if (index < 0 || index >= size) {
      throw std::out_of_range("Index out of bounds");
    }

    Node *node = head;
    Node *new_node = new Node(val);

    if (index == 0) {
      head = new_node;
      new_node->next = node;
      size++;
      return;
    }

    for (int i = 0; i < index - 1; i++) {
      node = node->next;
    }

    new_node->next = node->next;
    node->next = new_node;

    size++;
  }

  void Clear() {
    Node *node = head;
    Node *temp;

    for (int i = 0; i <= size - 1; i++) {
      temp = node->next;
      delete node;
      node = temp;
    }

    head = nullptr;
    tail = nullptr;
    size = 0;
  }

  int Search(T val) {
    if (size == 0) {
      throw std::out_of_range("The List is empty");
    }

    Node *node = head;

    for (int i = 0; i <= size - 1; i++) {
      if (node->data == val) {
        return i;
      }
      node = node->next;
    }

    return -1;
  }

  int Count() { return size; }

  T Get(int index) {
    if (index < 0 || index >= size) {
      throw std::out_of_range("Index out of bounds");
    }

    Node *curr_node = head;
    for (int i = 0; i < index; i++) {
      curr_node = curr_node->next;
    }

    return curr_node->data;
  }

  T Remove() {
    if (size == 0) {
      throw std::out_of_range("The List is empty");
    }

    Node *node = head;
    T removed_val = node->data;
    head = node->next;

    if (size == 1) {
      tail = head;
    }

    delete node;

    size--;
    return removed_val;
  }

  T RemoveAt(int index) {
    if (index < 0 || index >= size) {
      throw std::out_of_range("Index out of bounds");
    }

    Node *node = head;
    Node *temp;

    if (index == 0) {
      T removed_val = node->data;
      head = node->next;
      delete node;
      size--;
      return removed_val;
    }

    for (int i = 0; i < index - 1; i++) {
      node = node->next;
    }

    if (index == size - 1) {
      T removed_val = node->next->data;
      delete node->next;
      tail = node;
      size--;
      return removed_val;
    }

    temp = node->next->next;
    T removed_val = node->next->data;
    delete node->next;
    node->next = temp;
    size--;

    return removed_val;
  }

  T RemoveLast() {
    if (size == 0) {
      throw std::out_of_range("The List is empty");
    }

    Node *node = head;

    if (size == 1) {
      T removed_val = node->data;
      delete node;
      head = nullptr;
      tail = nullptr;
      size--;
      return removed_val;
    }

    for (int i = 0; i < size - 2; i++) {
      node = node->next;
    }

    T removed_val = node->next->data;
    delete node->next;
    tail = node;
    size--;

    return removed_val;
  }

  std::string ToString() {
    if (size == 0) {
      return "";
    }

    std::ostringstream oss;
    Node *node = head;

    for (int i = 0; i <= size - 1; i++) {
      oss << node->data;

      if (i < size - 1) {
        oss << ", ";
      }

      node = node->next;
    }

    return oss.str();
  }
};
