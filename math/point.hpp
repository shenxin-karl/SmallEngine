#pragma once
#include <iostream>
#include "utility/CommonDeclare.h"
#ifndef _MATH_VEC_HPP_
#include "vec.hpp"
#endif

namespace math {

template<typename T, size_t N>
struct point;

template<typename T>
struct point<T, 2> {
	T  x;
	T  y;
public:
	FORCE_INLINE point() = default;
	FORCE_INLINE point(T _x, T _y) : x(_x), y(_y) {}
	FORCE_INLINE explicit point(T v) : x(v), y(v) {}
	FORCE_INLINE explicit operator vec<T, 2> &() noexcept {
		return *reinterpret_cast<vec<T, 2> *>(this);
	}
	FORCE_INLINE explicit operator const vec<T, 2> &() const noexcept {
		return *reinterpret_cast<const vec<T, 2> *>(this);
	}
	FORCE_INLINE friend vec<T, 2> operator-(const point &lhs, const point &rhs) {
		return { lhs.x - rhs.x, lhs.y - rhs.y };
	}
	FORCE_INLINE friend std::ostream &operator<<(std::ostream &os, const point &p) {
		os << std::format("point2({}, {})", p.x, p.y);
		return os;
	}
};

template<typename T>
struct point<T, 3> {
	T  x;
	T  y;
	T  z;
public:
	FORCE_INLINE point() = default;
	FORCE_INLINE point(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}
	FORCE_INLINE explicit point(T v) : x(v), y(v), z(v) {}
	FORCE_INLINE explicit operator vec<T, 3> &() noexcept {
		return *reinterpret_cast<vec<T, 3> *>(this);
	}
	FORCE_INLINE explicit operator const vec<T, 3> &() const noexcept {
		return *reinterpret_cast<const vec<T, 3> *>(this);
	}
	FORCE_INLINE friend vec<T, 3> operator-(const point &lhs, const point &rhs) {
		return { lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z };
	}
	FORCE_INLINE friend std::ostream &operator<<(std::ostream &os, const point &p) {
		os << std::format("point3({}, {}, {})", p.x, p.y, p.z);
		return os;
	}
};

template<typename T>
struct point<T, 4> {
	T	x;
	T	y;
	T	z;
	T	w;
public:
	FORCE_INLINE point() = default;
	FORCE_INLINE point(T _x, T _y, T _z, T _w) : x(_x), y(_y), z(_z), w(_w) {}
	FORCE_INLINE explicit point(T v) : x(v), y(v), z(v), w(v) {}
	FORCE_INLINE explicit operator vec<T, 4> &() noexcept {
		return *reinterpret_cast<vec<T, 4> *>(this);
	}
	FORCE_INLINE explicit operator const vec<T, 4> &() const noexcept {
		return *reinterpret_cast<const vec<T, 4> *>(this);
	}
	FORCE_INLINE friend vec<T, 4> operator-(const point &lhs, const point &rhs) {
		return {
			lhs.x - rhs.x,
			lhs.y - rhs.y,
			lhs.z - rhs.z,
			lhs.w - rhs.w,
		};
	}
	FORCE_INLINE friend std::ostream &operator<<(std::ostream &os, const point &p) {
		os << std::format("point4({}, {}, {}, {})", p.x, p.y, p.z, p.w);
		return os;
	}
};

using float2 = point<float, 2>;
using float3 = point<float, 3>;
using float4 = point<float, 4>;
extern template struct point<float, 2>;
extern template struct point<float, 3>;
extern template struct point<float, 4>;

using int2 = point<int, 2>;
using int3 = point<int, 3>;
using int4 = point<int, 4>;
extern template struct point<int, 2>;
extern template struct point<int, 3>;
extern template struct point<int, 4>;

using short2 = point<short, 2>;
using short3 = point<short, 3>;
using short4 = point<short, 4>;
extern template struct point<short, 2>;
extern template struct point<short, 3>;
extern template struct point<short, 4>;



}