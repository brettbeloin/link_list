#pragma once
// #include "cstdio"
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
   * Create:
   *    Add
   * Read:
   *    Get
   *    toString
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

  T Get(int index) {}
  T Remove() {}
  T RemoveAt(int index) {}
  T RemoveLast() {}

  std::string toString() { return ""; }
};
