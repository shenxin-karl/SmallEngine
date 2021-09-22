#pragma once
#include "utility/CommonDeclare.h"

namespace input {

// 窗口参数
SEngine_INTERFACE IWindowEventArgs {
public:
	virtual ~IWindowEventArgs() = default;
};

}