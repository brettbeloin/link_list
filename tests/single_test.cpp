#include "../external/doctest/doctest/doctest.h"
#include "singleLinkedList.h"

TEST_CASE("Testing The Add method") {
  singleLinkedList<int> list;

  SUBCASE("Testing a single element") {
    CHECK(list.Count() == 0);
    list.Add(75);
    CHECK(list.Count() == 1);
  }

  SUBCASE("Testing multiple elements with generics") {
    singleLinkedList<std::string> list;

    CHECK(list.Count() == 0);
    list.Add("Hello");
    list.Add("World");
    list.Add("!");
    CHECK(list.Count() == 3);
  }
}
