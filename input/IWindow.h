#pragma once
#include <string>
#include <functional>
#include "utility/CommonDeclare.h"

namespace input {

SEngine_INTERFACE IWindowEventArgs;
SEngine_INTERFACE IHandleWindowEvent;
SEngine_INTERFACE IWindow;

SEngine_INTERFACE IWindow {
public:
	using ResizeCallBackType = std::function<void(IWindow *, int, int)>;
	virtual bool shouldClose() const = 0;
	virtual void resize(int width, int height) = 0;
	virtual void getSize(int &width, int &height) const = 0;
	virtual ResizeCallBackType handleResize(const ResizeCallBackType &callback) = 0;
	virtual bool isPause() const = 0;
	virtual void pause(bool flag) = 0;
	virtual void setTitle(const std::string &title) = 0;
	virtual std::string getTitle() const = 0;
	virtual void pollEvent() const = 0;
	virtual void close() = 0;
	virtual void registerMessage(IHandleWindowEvent *ptr) = 0;
	virtual ~IWindow() = default;
};




}