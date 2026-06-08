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

  void Add(T val) {}
  void Insert(T val, int index) {}
  void Clear() {}

  int Search(T val) {}

  T Get(int index) {}
  T Remove() {}
  T RemoveAt(int index) {}
  T RemoveLast() {}

  std::string toString() {}
};
