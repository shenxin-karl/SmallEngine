#pragma once
#include "utility/CommonDeclare.h"

namespace input {

// 窗口消息的传递
SEngine_INTERFACE IWindwoEventArgs {
public:
	virtual ~IWindwoEventArgs() = default;
};

}