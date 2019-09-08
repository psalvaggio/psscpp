/** Test for type traits header
 *
 *  \file test/type_traits_test.cpp
 *  \author Dr. Philip Salvaggio (salvaggio.philip@gmail.com)
 *  \date 06 Sep 2019
 */

#include "psscpp/type_traits.h"

static_assert(pss::decay_equiv<int, int>::value,
              "decay_equiv<int, int> failed");
static_assert(pss::decay_equiv<int, int&>::value,
              "decay_equiv<int, int&> failed");
static_assert(pss::decay_equiv<int, const int&>::value,
              "decay_equiv<int, const int&> failed");
static_assert(pss::decay_equiv<volatile int, const int&>::value,
              "decay_equiv<volatile int, const int&> failed");
static_assert(!pss::decay_equiv<double, int>::value,
              "decay_equiv<double, int> failed");

static_assert(
    pss::all_decay_equiv<int, int&, const int&, volatile int>::value,
    "all_decay_equiv_v<int, int&, const int&, volatile int> failed");
static_assert(pss::all_decay_equiv<int&, int&, const int&, volatile int>::value,
              "all_decay_equiv<int&, int&, const int&, volatile int> failed");
static_assert(
    !pss::all_decay_equiv<int, int&, const double&, volatile int>::value,
    "!all_decay_equiv<int, int&, const double&, volatile int> failed");

static_assert(pss::conjunction<std::true_type>::value,
              "conjunction_v<T> failed");
static_assert(pss::conjunction<std::true_type, std::true_type>::value,
              "pss::conjunction_v<T, T> failed");
static_assert(
    pss::conjunction<std::true_type, std::true_type, std::true_type>::value,
    "pss::conjunction_v<T, T, T> failed");
static_assert(
    !pss::conjunction<std::true_type, std::true_type, std::false_type>::value,
    "pss::conjunction_v<T, T, F> failed");

static_assert(pss::disjunction<std::true_type>::value,
              "disjunction_v<T> failed");
static_assert(pss::disjunction<std::true_type, std::true_type>::value,
              "pss::disjunction_v<T, T> failed");
static_assert(
    pss::disjunction<std::true_type, std::true_type, std::true_type>::value,
    "pss::disjunction_v<T, T, T> failed");
static_assert(
    pss::disjunction<std::true_type, std::true_type, std::false_type>::value,
    "pss::disjunction_v<T, T, F> failed");
static_assert(
    !pss::disjunction<std::false_type, std::false_type, std::false_type>::value,
    "pss::disjunction_v<F, F, F> failed");

static_assert(pss::negation<std::false_type>::value,
              "pss::negation_v<F> failed");
static_assert(!pss::negation<std::true_type>::value,
              "pss::negation_v<T> failed");

static_assert(pss::is_null_pointer<std::nullptr_t>::value,
              "pss::is_nullptr_v<nullptr_t> failed");
static_assert(!pss::is_null_pointer<int>::value,
              "pss::is_nullptr_v<int> failed");

int main() { return 0; }
