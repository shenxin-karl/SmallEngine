#include <Windows.h>
#include "Win32MouseInput.h"
#include "Win32WindowEventArgs.h"

namespace input {

input::Win32MouseInput::Win32MouseInput() : x_(0), y_(0) {
}

void Win32MouseInput::handleWindowMessage(IWindow *window, std::shared_ptr<IWindowEventArgs> windowEvent) {
	if (window == nullptr || windowEvent == nullptr)
		return;

	Win32WindowEventArgs *eventPtr = dynamic_cast<Win32WindowEventArgs *>(windowEvent.get());
	if (eventPtr == nullptr)
		return;

	HWND hwnd = eventPtr->hwnd_;
	UINT msg = eventPtr->msg_;
	WPARAM wParam = eventPtr->wParam_;
	LPARAM lParam = eventPtr->lParam_;

	switch (msg) {
	case WM_MOUSEMOVE:	
	{
		x_ = LOWORD(lParam);	
		y_ = HIWORD(lParam);	
		if (mouseMoveCallback_ != nullptr)
			mouseMoveCallback_(this, x_, y_);
		break;
	}
	case WM_LBUTTONDOWN:
	{
		if (leftBtnDownCallback_ != nullptr)
			leftBtnDownCallback_(this);
		break;
	}
	case WM_LBUTTONUP:
	{
		if (leftBtnUpCallback_ != nullptr)
			leftBtnUpCallback_(this);
		break;
	}
	case WM_RBUTTONDOWN:
	{
		if (rightBtnDownCallback_ != nullptr)
			rightBtnDownCallback_(this);
		break;
	}
	case WM_RBUTTONUP:
	{
		if (rightBtnUpCallback_ != nullptr)
			rightBtnUpCallback_(this);
		break;
	}
	case WM_MOUSEWHEEL:
	{
		float offset = GET_WHEEL_DELTA_WPARAM(wParam) / (float)WHEEL_DELTA;
		if (mouseScrollCallback_ != nullptr)
			mouseScrollCallback_(this, offset);
		break;
	}
	default:
		break;
	}

}

void Win32MouseInput::onMouseLeftButtonDown(const std::function<void(IMouseInput *)> &callback) {
	leftBtnDownCallback_ = callback;
}

void Win32MouseInput::onMouseRightButtonDown(const std::function<void(IMouseInput *)> &callback) {
	rightBtnDownCallback_ = callback;
}

void Win32MouseInput::onMouseLeftButtonUp(const std::function<void(IMouseInput *)> &callback) {
	leftBtnUpCallback_ = callback;
}

void Win32MouseInput::onMouseRightButtonUp(const std::function<void(IMouseInput *)> &callback) {
	rightBtnUpCallback_ = callback;
}

void Win32MouseInput::onMouseMove(const std::function<void(IMouseInput *, int, int)> &callback) {
	mouseMoveCallback_ = callback;
}

void Win32MouseInput::onMouseScroll(const std::function<void(IMouseInput *, int)> &callback) {
	mouseScrollCallback_ = callback;
}

void Win32MouseInput::getMousePosition(int &x, int &y) const {
	x = x_;
	y = y_;
}

}