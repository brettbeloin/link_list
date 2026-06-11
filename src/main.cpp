#include "singleLinkedList.h"
#include <print>

void SingleLinkedList() {
  std::println("These are all of the single Link list functions");

  singleLinkedList<int> foo;
  foo.Add(10);
  std::println("Original Foo: {}. The size is: {}", foo.ToString(),
               foo.Count());

  foo.Remove();
  std::println("modified Foo: {}. The size is: {}", foo.ToString(),
               foo.Count());

  singleLinkedList<int> list;

  list.Add(1);
  list.Add(3);
  list.Add(7);
  list.Add(6);
  list.Add(2);

  std::println("Original List: {}. The size is: {}", list.ToString(),
               list.Count());
  std::println("the 3'rd element is: {}", list.Get(3));
  list.Remove();
  std::println("modified List: {}. The size is: {}", list.ToString(),
               list.Count());

  singleLinkedList<std::string> new_list;
  new_list.Add("Hello");
  new_list.Add("World");
  new_list.Add("!");
  std::println("{}.", new_list.ToString());

  new_list.Clear();
  new_list.Add("this");
  new_list.Add("is");
  new_list.Add("a");
  new_list.Add("new");
  new_list.Add("list");
  std::println("cleared list: {}.", new_list.ToString());

  singleLinkedList<int> bar;
  std::println("we are in bar territory");
  bar.Clear();
  std::println("bar: {}", bar.ToString());
}

void DoubleLinkList() {
  std::println("These are all of the single Link list functions");
}

int main() {
  SingleLinkedList();
  DoubleLinkList();

  return 0;
}
