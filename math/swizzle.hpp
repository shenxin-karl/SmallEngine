#pragma once
#include <iostream>
#include <format>
#include <type_traits>
#include <cassert>
#include "VecConcept.hpp"

namespace math {

template<typename T, bool EnableAssign, size_t... I>
struct FORCE_EBCO Swizzle : public _VecBaseImpl<T, sizeof...(I)> {
	using PaddingType = T;
	static constexpr size_t paddingSize_ = sizeof...(I);
	static constexpr size_t indexSeq[paddingSize_] = { I... };
public:
	template<typename = void> requires(paddingSize_ == 1)
	operator T&() noexcept {
		return (reinterpret_cast<PaddingType*>(this)[I], ...);
	}

	template<typename = void> requires(paddingSize_ == 1)
	operator T() const noexcept {
		return (reinterpret_cast<const PaddingType *>(this)[I], ...);
	}

	template<typename = void> requires(paddingSize_ > 1)
	operator vec<T, paddingSize_>() const noexcept {
		return { reinterpret_cast<const PaddingType*>(this)[I]... };
	}

	template<typename = void> requires(EnableAssign)
	vec<T, paddingSize_> &operator=(const vec<T, paddingSize_> &other) {
		SEngineAssert((void *)(&other) != (void *)(this));
		assignment(
			reinterpret_cast<PaddingType*>(this), 
			reinterpret_cast<const PaddingType*>(&other),
			std::make_index_sequence<paddingSize_>()
		);
		return *reinterpret_cast<vec<T, paddingSize_> *>(this);
	}

	template<typename = void> requires(EnableAssign)
	float &operator[](size_t idx) {
		SEngineAssert(idx < paddingSize_);
		return reinterpret_cast<float *>(this)[indexSeq[idx]];
	}

	float operator[](size_t idx) const {
		SEngineAssert(idx < paddingSize_);
		return reinterpret_cast<const float *>(this)[indexSeq[idx]];
	}

private:
	template<size_t... I>
	void assignment(PaddingType *dst, const PaddingType *src, std::index_sequence<I...>) {
		((dst[I] = src[indexSeq[I]]), ...);
	}
};

template<typename T, bool EnableAssign, size_t... I>
std::ostream &operator<<(std::ostream &os, const Swizzle<T, EnableAssign, I...> &sw) {
	if constexpr (sizeof...(I) == 1)
		os << static_cast<float>(sw);
	else
		os << static_cast<vec<T, sizeof...(I)>>(sw);
	return os;
}

}