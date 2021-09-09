#pragma once
#include "utility/CommonDeclare.h"
#include "IWindow.h"
#include <Windows.h>

namespace input {

class Win32WindowEventArgs : public IWindwoEventArgs {
public:
	Win32WindowEventArgs(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
public:
	HWND	hwnd_;
	UINT	msg_;
	WPARAM	wParam_;
	LPARAM  lParam_;
};

class Win32Window : public IWindow {
	bool				shouldClose_;
	bool				pause_;
	HWND				hwnd_;
	HDC					hdc_;
	int					width_;
	int					height_;
	std::string			title_;
	ResizeCallBackType  resizeCallback_;
	std::vector<IHandleWindowEvent *> handleMessage_;
public:
	Win32Window(int width, int height, const std::string &title);
	Win32Window(const Win32Window &) = delete;
	Win32Window &operator=(const Win32Window &) = delete;
	virtual bool shouldClose() const override;
	virtual void resize(int width, int height) override ;
	virtual void getSize(int &width, int &height) const override;
	virtual ResizeCallBackType handleResize(const ResizeCallBackType &callback) override;
	virtual bool isPause() const override;
	virtual void pause(bool flag) override;
	virtual void setTitle(const std::string &title) override;
	virtual std::string getTitle() const override;
	virtual void pollEvent() const override;
	virtual void close() override;
	virtual void registerMessage(IHandleWindowEvent *ptr) const override;
	virtual ~Win32Window() override;
private:
	static LRESULT CALLBACK wndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
};

}