#include "doubleLinkedList.hpp"
#include <../external/doctest/doctest/doctest.h>
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

TEST_CASE("Testing the ToString method") {
  singleLinkedList<int> list;

  SUBCASE("Test empty list") { CHECK(list.ToString() == ""); }

  SUBCASE("Test full list") {
    list.Add(1);
    list.Add(3);
    list.Add(7);
    list.Add(6);
    list.Add(2);

    CHECK(list.ToString() == "1, 3, 7, 6, 2");
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

    CHECK(list.Count() == 4);
  }

  SUBCASE("Test Empty list") {
    CHECK_THROWS_AS(list.Remove(), std::out_of_range);
  }

  SUBCASE("Test tail edge case") {
    list.Add(3);
    list.Remove();

    CHECK(list.Count() == 0);
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

TEST_CASE("Testing the RemoveLast method") {
  singleLinkedList<int> list;

  SUBCASE("Test Happy") {
    list.Add(1);
    list.Add(3);
    list.Add(7);
    list.Add(6);
    list.RemoveLast();

    CHECK(list.Count() == 3);
    CHECK((list.Get(list.Count() - 1)) == 7);
  }

  SUBCASE("Test a single element list") {
    list.Add(5);
    list.RemoveLast();

    CHECK(list.Count() == 0);
  }

  SUBCASE("Test empty list") {
    CHECK_THROWS_AS(list.RemoveLast(), std::out_of_range);
  }
}

TEST_CASE("Testing the Search Method") {
  singleLinkedList<int> list;

  SUBCASE("Test Happy path") {
    list.Add(1);
    list.Add(3);
    list.Add(7);
    list.Add(6);
    int idx = list.Search(7);

    CHECK(idx == 2);
  }

  SUBCASE("Test empty list") {
    CHECK_THROWS_AS(list.Search(5), std::out_of_range);
  }

  SUBCASE("Test Element not found") {
    list.Add(1);
    list.Add(3);
    list.Add(7);
    list.Add(6);
    CHECK(list.Search(5) == -1);
  }
}

TEST_CASE("Testing the Insert Method") {
  singleLinkedList<int> list;

  SUBCASE("Test Happy") {
    list.Add(1);
    list.Add(3);
    list.Add(7);
    list.Add(6);
    list.Insert(5, 3);

    CHECK(list.Count() == 5);
    CHECK(list.Get(3) == 5);
  }

  SUBCASE("Test empty") {
    list.Add(6);
    list.Insert(5, 0);
    CHECK(list.Count() == 2);
    CHECK(list.Get(0) == 5);
  }

  SUBCASE("Test Tail logic") {
    list.Add(1);
    list.Add(3);
    list.Add(7);
    list.Add(6);
    list.Insert(5, 3);
    CHECK(list.Count() == 5);
    CHECK((list.Get(list.Count() - 1)) == 6);
  }

  SUBCASE("Test out_of_range") {
    list.Add(1);
    list.Add(3);
    list.Add(7);
    list.Add(6);

    CHECK_THROWS_AS(list.Insert(5, -1), std::out_of_range);
    CHECK_THROWS_AS(list.Insert(5, list.Count() + 1), std::out_of_range);
    SUBCASE("test out_of_range on empty list") {
      list.Clear();
      CHECK_THROWS_AS(list.Insert(5, 0), std::out_of_range);
    }
  }
}

TEST_CASE("Testing RemoveAt method") {
  singleLinkedList<int> list;

  SUBCASE("Test Happy Path") {
    list.Add(1);
    list.Add(3);
    list.Add(7);
    list.Add(6);
    int removed_number = list.RemoveAt(2);

    CHECK(list.Count() == 3);
    CHECK(removed_number == 7);
  }

  SUBCASE("Test out_of_range") {
    list.Add(1);
    list.Add(3);
    list.Add(7);
    list.Add(6);

    CHECK_THROWS_AS(list.RemoveAt(-1), std::out_of_range);
    CHECK_THROWS_AS(list.RemoveAt(list.Count() + 1), std::out_of_range);
    SUBCASE("test out_of_range on empty list") {
      list.Clear();
      CHECK_THROWS_AS(list.RemoveAt(0), std::out_of_range);
    }
  }
}
