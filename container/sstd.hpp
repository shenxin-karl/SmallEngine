#pragma once
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <memory>
#include "utility/MemoryStatistics.hpp"
#include "utility/SEngineAlloctor.hpp"


namespace sstd {

template<typename T, typename Allocator = utility::SEngineAllocator<T>>
using vector = std::vector<T, Allocator>;

template<typename T, typename Allocator = utility::SEngineAllocator<T>>
using list = std::list<T, Allocator>;

template<typename T, typename Allocator = utility::SEngineAllocator<T>>
using deque = std::deque<T, Allocator>;

template<typename T, typename Container = deque<T>>
using quque = std::queue<T, Container>;

template<typename T, typename Container = deque<T>>
using stack = std::stack<T, Container>;

template<typename Key, typename Pr = std::less<Key>, typename Allocator = utility::SEngineAllocator<Key>>
using set = std::set<Key, Pr, Allocator>;

template<typename Key, typename Value,
	typename Pr = std::less<Key>,
	typename Allocator = utility::SEngineAllocator<std::pair<const Key, Value>> >
using map = std::map<Key, Value, Pr, Allocator>;

template<typename Key, typename Hasher = std::hash<Key>,
	typename Keyeq = std::equal_to<Key>,
	typename Allocator = utility::SEngineAllocator<Key>>
using unordered_set = std::unordered_set<Key, Hasher, Keyeq, Allocator>;

template<typename Key, typename Hasher = std::hash<Key>,
	typename Keyeq = std::equal_to<Key>,
	typename Allocator = utility::SEngineAllocator<Key>>
using unordered_multiset = std::unordered_multiset<Key, Hasher, Keyeq, Allocator>;

template<typename Key, typename Value,
	typename Hasher = std::hash<Key>,
	typename Keyeq = std::equal_to<Key>,
	typename Allocator = utility::SEngineAllocator<std::pair<const Key, Value>>>
using unordered_map = std::unordered_map<Key, Value, Hasher, Keyeq, Allocator>;

template<typename Key, typename Value,
	typename Hasher = std::hash<Key>,
	typename Keyeq = std::equal_to<Key>,
	typename Allocator = utility::SEngineAllocator<std::pair<const Key, Value>>>
using unordered_multimap = std::unordered_multimap<Key, Value, Hasher, Keyeq, Allocator>;


template<typename T, typename ...Args>
auto make_shared(Args&&... args) {
	utility::MemoryStatistics<T>::increment(sizeof(T));
	auto ptr = ::new T(std::forward<Args>(args)...);
	return std::shared_ptr<T>(ptr, &utility::sharedPtrDefaultDeleter<T>);
}

using std::make_unique;
using std::shared_ptr;
using std::unique_ptr;

}

