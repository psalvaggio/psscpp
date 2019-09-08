/** Extensions to the standard type_traits header
 *
 *  \file include/psscpp/type_traits.h
 *  \author Dr. Philip Salvaggio (salvaggio.philip@gmail.com)
 *  \date 06 Sep 2019
 */

#pragma once

#include <type_traits>

#include "psscpp/macros.h"

namespace pss {

/// Tests if the decayed types of the two arguments are the same
template <class T, class U>
struct decay_equiv
    : std::is_same<typename std::decay<T>::type, typename std::decay<U>::type> {
};
#if __cplusplus >= 201402L
template <class T, class U>
#if __cplusplus >= 201703L
inline
#endif
    constexpr bool decay_equiv_v = decay_equiv<T, U>::value;
#endif

// Bring some C++17 traits back to C++11

#if __cplusplus < 201703L

template <bool B>
using bool_constant = std::integral_constant<bool, B>;

/// Conjunction is a logical AND of all of the template parameters
template <class...>
struct conjunction : std::true_type {};
template <class B1>
struct conjunction<B1> : B1 {};
template <class B1, class... Bn>
struct conjunction<B1, Bn...>
    : std::conditional<bool(B1::value), conjunction<Bn...>, B1>::type {};

/// Disjunction is a logcial OR of all of the template parameters
template <class...>
struct disjunction : std::false_type {};
template <class B1>
struct disjunction<B1> : B1 {};
template <class B1, class... Bn>
struct disjunction<B1, Bn...>
    : std::conditional<bool(B1::value), B1, disjunction<Bn...>>::type {};

/// Logical not of all of the template parameters
template <class B>
struct negation : bool_constant<!bool(B::value)> {};

#if __cplusplus >= 201402L

template <class... B>
constexpr bool conjunction_v = conjunction<B...>::value;

template <class... B>
constexpr bool disjunction_v = disjunction<B...>::value;

template <class B>
constexpr bool negation_v = negation<B>::value;

#endif

#else

template <bool B>
using bool_constant = std::bool_constant<B>;

template <class... B>
using conjunction = std::conjunction<B...>;

template <class... B>
inline constexpr bool conjunction_v = std::conjunction_v<B...>;

template <class... B>
using disjunction = std::disjunction<B...>;

template <class... B>
inline constexpr bool disjunction_v = std::disjunction_v<B...>;

template <class B>
using negation = std::negation<B>;

template <class B>
inline constexpr bool negation_v = negation<B>::value;

#endif

#if __cplusplus < 201402L

template <class T>
struct is_null_pointer
    : std::is_same<std::nullptr_t, typename std::remove_cv<T>::type> {};

#else

template <class T>
using is_null_pointer = std::is_null_pointer<T>;

template <class T>
#if __cplusplus >= 201703L
inline
#endif
    constexpr bool is_null_pointer_v = is_null_pointer_v<T>;
#endif

/// Tests whether all of the types are decay-equivalent
template <class T, class... Ts>
struct all_decay_equiv : conjunction<decay_equiv<T, Ts>...> {};

#if __cplusplus >= 201402L
template <class T, class... Ts>
#if __cplusplus >= 201703L
inline
#endif
    constexpr bool all_decay_equiv_v = conjunction_v<decay_equiv<T, Ts>...>;
#endif

}
