#pragma once
#include "CommonDeclare.h"
#include <memory>

namespace utility {

template<typename T>
concept SingletonConcept = requires {
	std::unique_ptr<T>{ T::initSingleton() };
};

//If T defines an initSingleton function, use it to initialize, otherwise nullptr
template<typename T>
class SEngine_API Singleton {
public:
	Singleton() = default;
	Singleton(const Singleton &) = delete;
	Singleton &operator=(const Singleton &) = delete;
	static T *instance() {
		return singletonPtr_.get();
	}

	template<typename... Args>
	static void instanceEmplace(Args&&... args) {
		singletonPtr_ = std::make_unique<T>(std::forward<Args>(args)...);
	}

	static void instanceRelease() {
		singletonPtr_.release();
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