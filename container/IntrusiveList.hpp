#pragma once
#include <type_traits>
#include <concepts>

namespace container {

struct InsrusiveNode;
template<typename T>
concept InsrusiveConcept = std::is_base_of_v<InsrusiveNode, T>;

struct InsrusiveNode {
	InsrusiveNode	*prev_;
	InsrusiveNode	*next_;
};

template<InsrusiveConcept T>
class InsrusiveList : public {
public:
	InsrusiveList();
	~InsrusiveList();
private:
	InsrusiveNode		head_;
	std::size_t			size_;
};


}

