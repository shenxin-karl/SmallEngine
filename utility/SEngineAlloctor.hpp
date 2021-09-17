#pragma once
#include <memory>
#include "CommonDeclare.h"
#include "MemoryStatistics.hpp"

namespace utility {

template<typename T, bool Enable = std::is_class_v<T>>
class SENGINE_API SEngineAllocator : public std::allocator<T> {
	using BaseType = std::allocator<T>;
public:
	using typename BaseType::value_type;
	using typename BaseType::size_type;

	template<typename U>
	struct rebind {
		using other = SEngineAllocator<U>;
	};

	T *allocate(std::size_t n) {
		if constexpr (Enable)
			MemoryStatistics<T>::increment(n * sizeof(T));
		return BaseType::allocate(n);
	}

	void deallocate(T *ptr, std::size_t n) {
		if constexpr (Enable)
			MemoryStatistics<T>::decrement(n * sizeof(T));
		return BaseType::deallocate(ptr, n);
	}
};

}