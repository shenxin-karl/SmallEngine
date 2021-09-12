#pragma once
#include <atomic>
#include "CommonDeclare.h"

namespace utility {

template<typename T>
class SENGINE_API MemoryStatistics {
public:
	static void increment(std::size_t size) noexcept {
		size_.fetch_add(size);
	}

	static void decrement(std::size_t size) noexcept {
		size_.fetch_sub(size);
	}

	static std::size_t getSize() noexcept {
		return size_;
	}

	static std::size_t getCount() noexcept {
		return getSize() / sizeof(T);
	}
public:
	static inline std::atomic<std::size_t> size_ = 0;
};

inline std::size_t memorySize(void *ptr) {
#ifdef _MSC_VER
	return ::_msize(ptr);
#else
	return ::malloc_usable_size(ptr);
#endif // _MSC_VER

}

template<typename T>
inline void sharedPtrDefaultDeleter(T *ptr) {
	utility::MemoryStatistics<T>::decrement(memorySize(ptr));
	return ::operator delete(ptr);
}

template<typename T, typename... Args>
auto make_shared(Args&&... args) {
	utility::MemoryStatistics<T>::increment(sizeof(T));
	auto ptr = static_cast<T *>(::operator new(sizeof(T)));
	::new(ptr) T(std::forward<Args>(args)...);
	return std::shared_ptr<T>(ptr, &sharedPtrDefaultDeleter<T>);
}
using std::make_unique;

#define DeclareMemoryStatistics(T) \
static inline MemoryStatistics<T> __memoryStatistics__;\
static void *operator new(std::size_t size) { \
	utility::MemoryStatistics<T>::increment(size); \
	return ::operator new(size); \
} \
static void *operator new(std::size_t size, const std::nothrow_t &nt) noexcept { \
	utility::MemoryStatistics<T>::increment(size); \
	return ::operator new(size, nt); \
} \
static void *operator new[](std::size_t size) { \
	utility::MemoryStatistics<T>::increment(size); \
	return ::operator new[](size); \
} \
static void *operator new[](std::size_t size, const std::nothrow_t &nt) noexcept { \
	utility::MemoryStatistics<T>::increment(size); \
	return ::operator new[](size, nt); \
} \
static void operator delete(void *ptr, std::size_t size) noexcept { \
	utility::MemoryStatistics<T>::decrement(size); \
	return ::operator delete(ptr); \
} \
static void operator delete[](void *ptr) noexcept { \
	std::size_t size = utility::memorySize(ptr); \
	utility::MemoryStatistics<T>::decrement(size); \
	return ::operator delete[](ptr); \
} 


}