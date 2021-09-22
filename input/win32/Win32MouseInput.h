#pragma once
#include "utility/CommonDeclare.h"
#include "input/IMouseInput.h"
#include <functional>

namespace input {

SEngine_INTERFACE IWindow;
SEngine_INTERFACE IWindowEventArgs;

class SEngine_API Win32MouseInput : public IMouseInput {
	std::function<void(IMouseInput *)>	leftBtnDownCallback_;
	std::function<void(IMouseInput *)>  rightBtnDownCallback_;
	std::function<void(IMouseInput *)>  leftBtnUpCallback_;
	std::function<void(IMouseInput *)>  rightBtnUpCallback_;
	std::function<void(IMouseInput *, int, int)> mouseMoveCallback_;
	std::function<void(IMouseInput *, int)>	mouseScrollCallback_;
	int	x_;
	int	y_;
public:
	Win32MouseInput();
	virtual void handleWindowMessage(IWindow *window, std::shared_ptr<IWindowEventArgs> windowEvent) override;
	virtual void onMouseLeftButtonDown(const std::function<void(IMouseInput *)> &callback) override;
	virtual void onMouseRightButtonDown(const std::function<void(IMouseInput *)> &callback) override;
	virtual void onMouseLeftButtonUp(const std::function<void(IMouseInput *)> &callback) override;
	virtual void onMouseRightButtonUp(const std::function<void(IMouseInput *)> &callback) override;
	virtual void onMouseMove(const std::function<void(IMouseInput *, int, int)> &callback) override;
	virtual void onMouseScroll(const std::function<void(IMouseInput *, int)> &callback) override;
	virtual void getMousePosition(int &x, int &y) const override;
	virtual ~Win32MouseInput() = default;
};

}