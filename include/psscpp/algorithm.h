/** Additional algorithms beyond those in the <algorithm> header
 *
 *  \file psscpp/algorithm.h
 *  \author Dr. Philip Salvaggio (salvaggio.philip@gmail.com)
 *  \date 09 Sep 2019
 */

#pragma once

#include <algorithm>
#include <iterator>

namespace pss {

/** Filters out elements from a map container
 *
 *  \param map     The map to filter
 *  \param filter  Callable that takes an element of the map and returns true if
 *                 it should remain in the map and false if it should be
 *                 filtered.
 */
template <class Map, class Callable>
void map_filter(Map& map, Callable&& filter) {
  for (auto it = std::begin(map); it != std::end(map);) {
    if (!filter(*it)) {
      it = map.erase(it);
    } else {
      ++it;
    }
  }
}
}
