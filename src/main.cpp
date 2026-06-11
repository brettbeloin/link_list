#include "singleLinkedList.h"
#include <print>

int main() {
  singleLinkedList<int> foo;
  foo.Add(10);
  std::println("Original Foo: {}. The size is: {}", foo.toString(),
               foo.Count());
  foo.printHead();
  foo.printTail();

  foo.Remove();
  std::println("modified Foo: {}. The size is: {}", foo.toString(),
               foo.Count());

  singleLinkedList<int> list;

  list.Add(1);
  list.Add(3);
  list.Add(7);
  list.Add(6);
  list.Add(2);

  std::println("Original List: {}. The size is: {}", list.toString(),
               list.Count());
  std::println("the 3'rd element is: {}", list.Get(3));
  list.Remove();
  std::println("modified List: {}. The size is: {}", list.toString(),
               list.Count());

  list.printTail();
  singleLinkedList<std::string> newList;
  newList.Add("Hello");
  newList.Add("World");
  newList.Add("!");
  std::println("{}.", newList.toString());
  newList.Clear();
  newList.Add("this");
  newList.Add("is");
  newList.Add("a");
  newList.Add("new");
  newList.Add("list");
  std::println("cleared list: {}.", newList.toString());

  singleLinkedList<int> bar;
  bar.Clear();
  std::println("bar: {}", bar.toString());

  return 0;
}
