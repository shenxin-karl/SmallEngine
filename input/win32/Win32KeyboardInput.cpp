#include "Win32KeyboardInput.h"
#include "Win32WindowEventArgs.h"

namespace input {

void Win32KeyboardInput::handleWindowMessage(IWindow *window, std::shared_ptr<IWindwoEventArgs> windowEvent) {
	if (window == nullptr || windowEvent == nullptr)
		return;

	Win32WindowEventArgs *eventPtr = dynamic_cast<Win32WindowEventArgs *>(windowEvent.get());
	if (eventPtr == nullptr)
		return;

	HWND hwnd = eventPtr->hwnd_;
	UINT msg = eventPtr->msg_;
	WPARAM wParam = eventPtr->wParam_;
	LPARAM lParam = eventPtr->lParam_;
	// todo
}

void Win32KeyboardInput::onKeyDown(const std::function<void(KeyType)> &callback) {
	keyDownCallback_ = callback;
}

void Win32KeyboardInput::onKeyUp(const std::function<void(KeyType)> &callback) {
	keyUpCallback_ = callback;
}

bool Win32KeyboardInput::isKeyDown(KeyType key) const {
	return keyStatus_.find(key) != keyStatus_.end();
}

}