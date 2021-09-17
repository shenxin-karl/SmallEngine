#pragma once
#include "VecConcept.hpp"

namespace math {

template<typename T, size_t N>
using identity_t = T;

template<typename T, typename Seq1, typename Seq2>
struct FORCE_EBCO VecConstructImpl;

template<typename T, size_t... I1, size_t... I2>
struct FORCE_EBCO VecConstructImpl<T, std::index_sequence<I1...>, std::index_sequence<I2...>> {
	static constexpr size_t scalarSize_ = sizeof...(I1);
	static constexpr size_t dimensionVector_ = sizeof...(I2);
	static constexpr size_t N = scalarSize_ + dimensionVector_;
	VecConstructImpl() = default;

	template<typename VT> 
	requires(scalarSize_ > 0 && dimensionVector_ > 0 && VecSizeConcept<VT, T, dimensionVector_>)
	FORCE_INLINE VecConstructImpl(identity_t<T, I1>... f, const VT &v) {
		new (reinterpret_cast<vec<T, N> *>(this)->_data) T[N]{
			f..., v[I2]...,
		};
	}

	template<typename VT>
	requires(scalarSize_ > 0 && dimensionVector_ > 0 && VecSizeConcept<VT, T, dimensionVector_>)
	FORCE_INLINE VecConstructImpl(const VT &v, identity_t<T, I1>... f) {
		new (reinterpret_cast<vec<T, N> *>(this)->_data) T[N]{
			v[I2]..., f...,
		};
	}

	template<typename VT1, typename VT2>
	requires(scalarSize_ > 1 && dimensionVector_ > 1 && 
			VecSizeConcept<VT1, T, scalarSize_> && 
			VecSizeConcept<VT2, T, dimensionVector_>)
	FORCE_INLINE VecConstructImpl(const VT1 &v1, const VT2 &v2) {
		new (reinterpret_cast<vec<T, N> *>(this)->_data) T[N]{
			v1[I1]..., v2[I2]...,
		};
	}

};

template<typename T, typename Seq>
struct FORCE_EBCO VecConstructor;

template<typename T, size_t ...I>
struct FORCE_EBCO VecConstructor<T, std::index_sequence<I...>>
: public VecConstructImpl<T, std::make_index_sequence<I>, std::make_index_sequence<(sizeof...(I) - I)>>... {

	using VecConstructImpl<T, std::make_index_sequence<I>, std::make_index_sequence<(sizeof...(I) - I)>>::VecConstructImpl...;
};

}