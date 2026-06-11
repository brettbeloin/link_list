#include "../external/doctest/doctest/doctest.h"
#include "singleLinkedList.h"
#include <stdexcept>

TEST_CASE("Testing The Add method") {
  SUBCASE("Testing a single element") {
    singleLinkedList<int> list;

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

TEST_CASE("Testing The Get method") {
  singleLinkedList<int> list;

  list.Add(1);
  list.Add(3);
  list.Add(7);
  list.Add(6);
  list.Add(2);

  SUBCASE("Test get proper value") {
    int correct_number = list.Get(3);
    CHECK(correct_number == 6);
  }

  SUBCASE("Test get out of bounds err") {
    CHECK_THROWS_AS(list.Get(5), std::out_of_range);

    CHECK_THROWS_AS(list.Get(-1), std::out_of_range);
  }
}

TEST_CASE("Testing the toString method") {
  singleLinkedList<int> list;
  SUBCASE("Test empty list") { CHECK(list.toString() == ""); }

  SUBCASE("Test full list") {
    list.Add(1);
    list.Add(3);
    list.Add(7);
    list.Add(6);
    list.Add(2);

    CHECK(list.toString() == "1, 3, 7, 6, 2");
  }
}

TEST_CASE("Testing the Remove method") {
  singleLinkedList<int> list;
  SUBCASE("Happy Path") {
    list.Add(1);
    list.Add(3);
    list.Add(7);
    list.Add(6);
    list.Add(2);

    list.Remove();

    CHECK(list.toString() == "3, 7, 6, 2");
  }

  SUBCASE("Test Empty list") {
    CHECK_THROWS_AS(list.Remove(), std::out_of_range);
  }

  SUBCASE("Test tail edge case") {
    list.Add(3);
    list.Remove();

    CHECK(list.toString() == "");
  }
}

TEST_CASE("Testing the Clear method") {
  singleLinkedList<int> list;

  SUBCASE("Clear full list") {
    list.Add(1);
    list.Add(3);
    list.Add(7);
    list.Add(6);
    list.Add(2);
    list.Clear();

    CHECK(list.Count() == 0);
  }

  SUBCASE("Clear empty list") {
    list.Clear();

    CHECK(list.Count() == 0);
  }
}
