#pragma once
#include <memory>
#include "utility/CommonDeclare.h"

namespace input {
SEngine_INTERFACE IWindow;
SEngine_INTERFACE IWindowEventArgs;

// 能处理创建事件的基类
SEngine_INTERFACE IHandleWindowEvent {
public:
	virtual void handleWindowMessage(IWindow *window, std::shared_ptr<IWindowEventArgs> windowEvent) {}
	virtual ~IHandleWindowEvent() = default;
};

}
