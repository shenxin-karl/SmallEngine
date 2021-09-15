#pragma once
#include <type_traits>
#include <concepts>

namespace math {

template<typename T, bool EnableAssign, size_t... I>
struct FORCE_EBCO Swizzle;

template<typename T, size_t N>
struct vec;

struct FORCE_EBCO _VecBase {
};

template<typename T, size_t N>
struct FORCE_EBCO _VecBaseImpl : public _VecBase {
	using type = T;
	static constexpr size_t size() noexcept {
		return N;
	}
};

template<typename T>
concept InheritVecBase = std::is_base_of_v<_VecBase, T>;

template<typename T, typename Origin, size_t N>
concept VecSizeConcept = std::is_base_of_v<_VecBaseImpl<Origin, N>, T>;

template<typename T1, typename T2>
concept VecConcept = requires {
	std::enable_if_t<
		InheritVecBase<T1> && InheritVecBase<T2> &&
		std::is_same_v<typename T1::type, typename T2::type> &&
		T1::size() == T2::size()
	>();
};


template<typename T>
struct _VecEnableAssign : public std::false_type {
};

template<typename T, size_t N>
struct _VecEnableAssign<vec<T, N>> : public std::true_type {
};

template<typename T, size_t... I>
struct _VecEnableAssign<Swizzle<T, true, I...>> : std::true_type {
};

template<typename T>
concept VecEnableAssign = _VecEnableAssign<T>::value;


}