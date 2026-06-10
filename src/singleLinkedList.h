#pragma once
// #include "print"
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
   * Order of Completed function following CRUD:
   * Delete:
   *    Remove
   *    Clear
   *
   * important, follow simaler logic as functions above
   * Insert
   * Search
   * RemoveLast
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
  void Clear() {}

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

  T Remove() {}
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
};
