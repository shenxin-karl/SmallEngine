#pragma once
#include <type_traits>

namespace container {

struct InsrusiveNode {
	InsrusiveNode	*prev_;
	InsrusiveNode	*next_;
};

template<typename T> requires(std::is_base_of_v<InsrusiveNode, T>)
class InsrusiveList {
	InsrusiveNode	*head_;
	int				 size_;
public:
	InsrusiveList() = default;

	~InsrusiveList() = default;
};

}

