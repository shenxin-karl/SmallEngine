#pragma once
#include <Windows.h>
#include <vector>
#include <unordered_map>
#include "utility/CommonDeclare.h"
#include "input/IWindow.h"
#include "container/sstd.hpp"

namespace input {

SEngine_INTERFACE IHandleWindowEvent;
class Win32Window : public IWindow {
	bool				shouldClose_;
	bool				pause_;
	HWND				hwnd_;
	HDC					hdc_;
	int					width_;
	int					height_;
	std::string			title_;
	ResizeCallBackType  resizeCallback_;
	sstd::vector<IHandleWindowEvent *> handleMessage_;
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
	virtual void registerMessage(IHandleWindowEvent *ptr) override;
	virtual ~Win32Window() override;
	void events(std::shared_ptr<IWindowEventArgs> eventArgs);
private:
	static inline std::unordered_map<HWND, Win32Window *> hwnd2Window_;
	static LRESULT CALLBACK wndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
};

}