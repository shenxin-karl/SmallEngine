#pragma once
#include <functional>
#include "utility/CommonDeclare.h"
#include "IHandleWindowEvent.h"

namespace input {

// 鼠标事件的接口
SEngine_INTERFACE IMouseInput : public IHandleWindowEvent {
public:
	virtual void onMouseLeftButtonDown(const std::function<void(IMouseInput *)> &callback) = 0;
	virtual void onMouseRightButtonDown(const std::function<void(IMouseInput *)> &callback) = 0;
	virtual void onMouseLeftButtonUp(const std::function<void(IMouseInput *)> &callback) = 0;
	virtual void onMouseRightButtonUp(const std::function<void(IMouseInput *)> &callback) = 0;
	virtual void onMouseMove(const std::function<void(IMouseInput *, int, int)> &callback) = 0;
	virtual void onMouseScroll(const std::function<void(IMouseInput *, int)> &callback) = 0;
	virtual void getMousePosition(int &x, int &y) const = 0;
	virtual ~IMouseInput() = default;
};

}