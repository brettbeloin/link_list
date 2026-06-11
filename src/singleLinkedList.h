#pragma once
#include "print"
#include <sstream>
#include <stdexcept>
#include <string>

template <typename T> class singleLinkedList {
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
  /*
   * Search
   * RemoveLast
   * Insert
   * RemoveAt
   */
  singleLinkedList() : head(nullptr), tail(nullptr), size(0) {}

  void Add(T val) {
    Node *newNode = new Node(val);
    if (!head) {
      head = tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
    size++;
  }
  void Insert(T val, int index) {}
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

  int Search(T val) { return -1; }
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
    T foo = node->data;
    head = node->next;

    if (size == 1) {
      tail = head;
    } else if (size == 0) {
      tail = nullptr;
    }

    delete node;

    size--;
    return foo;
  }

  T RemoveAt(int index) {}
  T RemoveLast() {}

  std::string toString() {
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

  void printHead() {
    std::ostringstream oss;
    oss << head->data;
    std::println("The head is: {}", oss.str());
  }

  void printTail() {
    std::ostringstream oss;
    oss << tail->data;
    std::println("The tail is: {}", oss.str());
  }
};
