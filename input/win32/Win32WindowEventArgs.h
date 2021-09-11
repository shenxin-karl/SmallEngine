#pragma once
#include <Windows.h>
#include "utility/CommonDeclare.h"
#include "input/IWindowEventArgs.h"

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

}