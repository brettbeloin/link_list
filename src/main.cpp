#include "singleLinkedList.h"
#include <print>

int main() {
  singleLinkedList<int> list;

  list.Add(1);
  list.Add(3);
  list.Add(7);
  list.Add(6);
  list.Add(2);

  std::println("{}.", list.toString());
  std::println("the 3'rd element is: {}", list.Get(3));

  singleLinkedList<std::string> newList;
  newList.Add("Hello");
  newList.Add("World");
  newList.Add("!");
  std::println("{}.", newList.toString());
  return 0;
}
