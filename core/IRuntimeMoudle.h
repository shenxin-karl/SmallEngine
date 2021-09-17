#pragma once
#include "utility/CommonDeclare.h"

namespace core {

SEngine_INTERFACE IRuntimeMoudle {
public:
	IRuntimeMoudle() = default;
	virtual void initialize() = 0;
	virtual void tick() = 0;
	virtual void destroy() = 0;
	virtual ~IRuntimeMoudle() = default;
};

}