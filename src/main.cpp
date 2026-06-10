#include "singleLinkedList.h"
#include <iostream>

int main() {
  singleLinkedList<int> list;

  std::cout << "the count of the list is: " << list.Count() << "\n";
  list.Add(75);
  std::cout << "the count of the list is: " << list.Count() << "\n";
  return 0;
}
