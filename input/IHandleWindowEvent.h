#pragma once
#include <memory>
#include "utility/CommonDeclare.h"

namespace input {
SEngine_INTERFACE IWindow;
SEngine_INTERFACE IWindwoEventArgs;

// 能够处理消息窗口消息的类
SEngine_INTERFACE IHandleWindowEvent {
public:
	virtual void handleWindowMessage(IWindow *window, std::shared_ptr<IWindwoEventArgs> windowEvent) = 0;
	virtual ~IHandleWindowEvent() = default;
};

}
