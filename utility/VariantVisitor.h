#pragma once
#include "CommonDeclare.h"
#include <type_traits>

namespace tool {

template<typename... Args>
struct SEngine_API _OverloadImpl : public std::decay_t<Args>... {
	template<typename... UArgs>
	_OverloadImpl(UArgs&& ...args) : std::decay_t<Args>(std::forward<UArgs>(args))... {}

	using std::decay_t<Args>::operator()...;
};

template<typename... Args>
auto overloaded(Args&& ...args) {
	return _OverloadImpl<Args...>(std::forward<Args>(args)...);
}

}