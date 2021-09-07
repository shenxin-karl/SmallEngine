#pragma once
#include "CommonDeclare.h"
#include <memory>

namespace tool {

template<typename T>
concept SingletonConcept = std::is_assignable_v<std::unique_ptr<T>, decltype(T::initSingleton())>;


//If T defines an initSingleton function, use it to initialize, otherwise nullptr
template<typename T>
class SENGINE_API Singleton {
public:
	Singleton() = default;
	Singleton(const Singleton &) = delete;
	Singleton &operator=(const Singleton &) = delete;
	static T *instance() {
		SEngineAssert(static_cast<bool>(singletonPtr_));
		return singletonPtr_.get();
	}

	template<typename... Args>
	void emplace(Args&&... args) {
		singletonPtr_ = std::make_shared<T>(std::forward<Args>(args));
	}

	static std::unique_ptr<T> init() {
		if constexpr (SingletonConcept<T>)
			return T::initSingleton();
		else
			return nullptr;
	}
private:
	static inline std::unique_ptr<T> singletonPtr_ = init();
};

}