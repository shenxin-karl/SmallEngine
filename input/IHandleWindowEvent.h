#pragma once
#include <memory>
#include "utility/CommonDeclare.h"

namespace input {
SEngine_INTERFACE IWindow;
SEngine_INTERFACE IWindwoEventArgs;

// �ܹ�������Ϣ������Ϣ����
SEngine_INTERFACE IHandleWindowEvent {
public:
	virtual void handleWindowMessage(IWindow *window, std::shared_ptr<IWindwoEventArgs> windowEvent) = 0;
	virtual ~IHandleWindowEvent() = default;
};

}
