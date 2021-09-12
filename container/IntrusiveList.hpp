#pragma once
#include <type_traits>
#include <concepts>

namespace container {

struct InsrusiveNode {
	InsrusiveNode	*prev_;
	InsrusiveNode	*next_;
};

template<typename T>
concept InsrusiveConcept = std::is_base_of_v<InsrusiveNode, T>;



}

