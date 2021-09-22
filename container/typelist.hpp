#pragma once
#include <type_traits>

namespace container { namespace tl { 


template<typename...>
struct typelist {};

template<typename T>
struct empty : public std::false_type {
};

template<typename... Args>
struct empty<typelist<Args...>> : public std::true_type {
};

template<typename T>
constexpr bool empty_t = empty<T>::value;

template<typename T, typename U, int N = 0>
struct indexof {
	static constexpr int value = -1;
};

template<typename Head, typename... Tail, typename U, int N>
struct indexof<typelist<Head, Tail...>, U, N> {
	static constexpr int value = std::is_same_v<Head, U> ? N : indexof<typelist<Tail...>, U, N+1>::value;
};

template<typename T>
struct count;

template<typename... Args>
struct count<typelist<Args...>> {
	static constexpr int value = sizeof...(Args);
};

template<typename T>
constexpr int count_t = count<T>::value;

template<typename T, typename Arg>
struct push_back;

template<typename... Args, typename Arg>
struct push_back<typelist<Args...>, Arg> {
	using type = typelist<Args..., Args>;
};

template<typename TL, typename Arg>
using push_back_t = typename push_back<TL, Arg>::type;

}
}