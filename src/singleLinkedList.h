#pragma once
#include <print>
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
   * RemoveAt
   */
  singleLinkedList() : head(nullptr), tail(nullptr), size(0) {}
  ~singleLinkedList() {
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
    Node *newNode = new Node(val);
    if (!head) {
      head = tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
    size++;
  }

  void Insert(T val, int index) {
    if (index < 0 || index >= size) {
      throw std::out_of_range("Index out of bounds");
    }

    Node *node = head;
    Node *newNode = new Node(val);

    if (index == 0) {
      head = newNode;
      newNode->next = node;
      size++;
      return;
    }

    for (int i = 0; i < index - 1; i++) {
      node = node->next;
    }

    newNode->next = node->next;
    node->next = newNode;

    if (newNode->next == nullptr) {
      tail = newNode;
    }

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
    T foo = node->data;
    head = node->next;

    if (size == 1) {
      tail = head;
    }

    delete node;

    size--;
    return foo;
  }

  T RemoveAt(int index) {}
  T RemoveLast() {
    if (size == 0) {
      throw std::out_of_range("The List is empty");
    }

    Node *node = head;

    if (size == 1) {
      T foo = node->data;
      delete node;
      head, tail = nullptr;
      size--;
      return foo;
    }

    for (int i = 0; i < size - 2; i++) {
      node = node->next;
    }

    T temp = node->next->data;
    delete node->next;
    tail = node;
    size--;

    return temp;
  }

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
    if (size == 0) {
      std::println("There is no head");
      return;
    }

    oss << head->data;
    std::println("The head is: {}", oss.str());
  }

  std::string printTail() {
    std::ostringstream oss;
    if (size == 0) {
      return "There is no tail";
    }
    oss << tail->data;
    return oss.str();
  }
};
