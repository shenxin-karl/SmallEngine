#pragma once
#include <type_traits>
#include <format>
#include "utility/CommonDeclare.h"
#include "swizzle.hpp"
#include "VecConcept.hpp"

namespace math {

template<typename T>
struct vec<T, 2> : public _VecBaseImpl<T, 2> {
	vec() = default;
	vec(const vec &) = default;
	vec(T x, T y) : _data{ x, y } {}
	vec &operator=(const vec &) = default;
	T &operator[](size_t idx) { return _data[idx]; }
	T operator[](size_t idx) const { return _data[idx]; }
public:
	union {
#include "vec2Member.txt"
		T _data[2];
	};
};

template<typename T>
struct vec<T, 3> : public _VecBaseImpl<T, 3> {
	vec() = default;
	vec(const vec &) = default;
	vec(T x, T y, T z) : _data{ x, y, z } {}
	vec &operator=(const vec &) = default;
	T &operator[](size_t idx) { return _data[idx]; }
	T operator[](size_t idx) const { return _data[idx]; }
public:
	union {
#include "vec3Member.txt"
		T _data[3];
	};
};

template<typename T>
struct vec<T, 4> : public _VecBaseImpl<T, 4> {
	vec() = default;
	vec(const vec &) = default;
	vec(float x, float y, float z, float w) : _data{ x, y, z, w } {}
	vec &operator=(const vec &) = default;
	T &operator[](size_t idx) { return _data[idx]; }
	T operator[](size_t idx) const { return _data[idx]; }
public:
	union {
#include "vec4Member.txt"
		T _data[4];
	};
};


using vec2 = vec<float, 2>;
using vec3 = vec<float, 3>;
using vec4 = vec<float, 4>;
using vec2i = vec<int, 2>;
using vec3i = vec<int, 3>;
using vec4i = vec<int, 4>;

template<typename T1, typename T2> requires VecConcept<T1, T2>
FORCE_INLINE float dot(const T1 &lhs, const T2 &rhs) {
	float res = 0.f;
	for (size_t i = 0; i < T1::size(); ++i)
		res += lhs[i] * rhs[i];
	return res;
}

template<InheritVecBase T>
FORCE_INLINE float length_square(const T &v) {
	return dot(v, v);
}

template<InheritVecBase T>
FORCE_INLINE float length(const T &v) {
	return std::sqrt(length_square(v));
}

template<InheritVecBase T>
FORCE_INLINE void normalize(T &v) {
	float len2 = length_square(v);
	if (len2 != 0.f)
		v /= std::sqrt(len2);
}

template<typename T1, typename T2> requires VecConcept<T1, T2>
FORCE_INLINE auto operator+(T1 &&t1, T2 &&t2) {
	vec<typename T1::type, T1::size()> res;
	for (size_t i = 0; i < T1::size(); ++i)
		res[i] = t1[i] + t2[i];
	return res;
}
template<typename T1, typename T2> requires VecConcept<T1, T2>
FORCE_INLINE auto operator-(T1 &&t1, T2 &&t2) {
	vec<typename T1::type, T1::size()> res;
	for (size_t i = 0; i < T1::size(); ++i)
		res[i] = t1[i] - t2[i];
	return res;
}
template<typename T1, typename T2> requires VecConcept<T1, T2>
FORCE_INLINE auto operator*(T1 &&t1, T2 &&t2) {
	vec<typename T1::type, T1::size()> res;
	for (size_t i = 0; i < T1::size(); ++i)
		res[i] = t1[i] * t2[i];
	return res;
}
template<typename T1, typename T2> requires VecConcept<T1, T2>
FORCE_INLINE auto operator/(T1 &&t1, T2 &&t2) {
	vec<typename T1::type, T1::size()> res;
	for (size_t i = 0; i < T1::size(); ++i)
		res[i] = t1[i] / t2[i];
	return res;
}

template<typename T1, typename T2> requires VecConcept<T1, T2> && VecEnableAssign<T1>
FORCE_INLINE auto &operator+=(T1 &t1, const T2 &t2) {
	for (size_t i = 0; i < T1::size(); ++i)
		t1[i] += t2[i];
	return t1;
}
template<typename T1, typename T2> requires VecConcept<T1, T2> && VecEnableAssign<T1>
FORCE_INLINE auto &operator-=(T1 &&t1, const T2 &t2) {
	for (size_t i = 0; i < T1::size(); ++i)
		t1[i] -= t2[i];
	return t1;
}
template<typename T1, typename T2> requires VecConcept<T1, T2> && VecEnableAssign<T1>
FORCE_INLINE auto &operator*=(T1 &t1, const T2 &t2) {
	vec<typename T1::type, T1::size()> res;
	for (size_t i = 0; i < T1::size(); ++i)
		t1[i] *= t2[i];
	return t1;
}
template<typename T1, typename T2> requires VecConcept<T1, T2> && VecEnableAssign<T1>
FORCE_INLINE auto &operator/=(T1 &t1, const T2 &t2) {
	for (size_t i = 0; i < T1::size(); ++i)
		t1[i] /= t2[i];
	return t1;
}

template<InheritVecBase T>
FORCE_INLINE auto operator+(const T &v, float f) {
	vec<typename T::type, T::size()> res = v;
	for (size_t i = 0; i < T::size(); ++i)
		res[i] += f;
	return res;
}
template<InheritVecBase T>
FORCE_INLINE auto operator-(const T &v, float f) {
	vec<typename T::type, T::size()> res = v;
	for (size_t i = 0; i < T::size(); ++i)
		res[i] -= f;
	return res;
}
template<InheritVecBase T>
FORCE_INLINE auto operator*(const T &v, float f) {
	vec<typename T::type, T::size()> res = v;
	for (size_t i = 0; i < T::size(); ++i)
		res[i] *= f;
	return res;
}
template<InheritVecBase T>
FORCE_INLINE auto operator/(const T &v, float f) {
	vec<typename T::type, T::size()> res = v;
	for (size_t i = 0; i < T::size(); ++i)
		res[i] /= f;
	return res;
}


template<InheritVecBase T> requires VecEnableAssign<T>
FORCE_INLINE auto &operator-=(T &v, typename T::type f) {
	for (size_t i = 0; i < T::size(); ++i)
		v -= f;
	return v;
}
template<InheritVecBase T> requires VecEnableAssign<T>
FORCE_INLINE auto &operator+=(T &v, typename T::type f) {
	for (size_t i = 0; i < T::size(); ++i)
		v += f;
	return v;
}
template<InheritVecBase T> requires VecEnableAssign<T>
FORCE_INLINE auto &operator*=(T &v, typename T::type f) {
	for (size_t i = 0; i < T::size(); ++i)
		v *= f;
	return v;
}
template<InheritVecBase T> requires VecEnableAssign<T>
FORCE_INLINE auto &operator/(T &v, typename T::type f) {
	for (size_t i = 0; i < T::size(); ++i)
		v /= f;
	return v;
}


template<InheritVecBase T>
FORCE_INLINE auto operator+(float f, const T &v) {
	return math::operator+(v, f);
}
template<InheritVecBase T>
FORCE_INLINE auto operator-(float f, const T &v) {
	return math::operator-(v, f);
}
template<InheritVecBase T>
FORCE_INLINE auto operator*(float f, const T &v) {
	return math::operator*(v, f);
}
template<InheritVecBase T>
FORCE_INLINE auto operator/(float f, const T &v) {
	return math::operator/(v, f);
}

template<typename T, size_t N>
FORCE_INLINE std::ostream &operator<<(std::ostream& os, const vec<T, N>& v) {
	os << std::format("vec{}(", N);
	for (int i = 0; i < N-1; ++i)
		os << v[i] << ", ";
	os << std::format("{})", v[N-1]);
	return os;
}
}