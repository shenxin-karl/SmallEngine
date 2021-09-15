#pragma once
#include <cassert>
#define SENGINE_API
#define SEngineAssert(...) (assert(__VA_ARGS__))

#ifdef SEngine_INTERFACE
#undef SEngine_INTERFACE
#endif // SEngine_INTERFACE
#define SEngine_INTERFACE class


#ifdef _MSC_VER
#define FORCE_INLINE	__forceinline
#define FORCE_EBCO		__declspec(empty_bases) 
#else
#define FORCE_INLINE	inline
#define force_EBCO		 
#endif // _MSC_VER
