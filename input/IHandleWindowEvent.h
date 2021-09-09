#pragma once
#include <memory>
#include "utility/CommonDeclare.h"

namespace input {
class IWindow;
class IWindwoEventArgs;

// 能够处理消息窗口消息的类
INTERFACE IHandleWindowEvent {
public:
	virtual void handleWindowMessage(IWindow *window, std::shared_ptr<IWindwoEventArgs> windowEvent) = 0;
	virtual ~IHandleWindowEvent() = default;
};

}
