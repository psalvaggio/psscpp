/** Unit test for algorithm.h
 *
 *  \file test/algorithm_test.h
 *  \author Dr. Philip Salvaggio (salvaggio.philip@gmail.com)
 *  \date 09 Sep 2019
 */

#include "psscpp/algorithm.h"

#include <unordered_map>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("map_filter test") {
  std::unordered_map<int, int> f{{0, 0}, {1, 2}, {2, 4}, {3, 6}, {4, 8}};

  SUBCASE("Filtering when some (but not all) elements get filtered") {
    pss::map_filter(
        f, [](const std::pair<int, int>& p) { return p.first % 2 == 0; });

    REQUIRE_EQ(f.size(), 3);
    REQUIRE_GT(f.count(0), 0);
    REQUIRE_EQ(f[0], 0);
    REQUIRE_EQ(f[2], 4);
    REQUIRE_EQ(f[4], 8);
  }

  SUBCASE("Filtering when no elements get filtered") {
    pss::map_filter(f, [](const std::pair<int, int>& p) { return true; });
    REQUIRE_EQ(f.size(), 5);
    REQUIRE_GT(f.count(0), 0);
    REQUIRE_EQ(f[0], 0);
    REQUIRE_EQ(f[1], 2);
    REQUIRE_EQ(f[2], 4);
    REQUIRE_EQ(f[3], 6);
    REQUIRE_EQ(f[4], 8);
  }

  SUBCASE("Filtering when all elements get filtered") {
    pss::map_filter(f, [](const std::pair<int, int>& p) { return false; });
    REQUIRE(f.empty());
  }

  SUBCASE("Filtering an empty map") {
    f.clear();
    pss::map_filter(f, [](const std::pair<int, int>& p) { return true; });
    REQUIRE(f.empty());
  }
}
