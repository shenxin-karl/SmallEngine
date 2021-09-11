#pragma once
#include <cassert>
#define SENGINE_API
#define SEngineAssert(...) (assert(__VA_ARGS__))

#ifdef SEngine_INTERFACE
#undef SEngine_INTERFACE
#endif // SEngine_INTERFACE
#define SEngine_INTERFACE class


