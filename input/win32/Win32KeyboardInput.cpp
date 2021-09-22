#include "Win32KeyboardInput.h"
#include "Win32WindowEventArgs.h"

namespace input {

void Win32KeyboardInput::handleWindowMessage(IWindow *window, std::shared_ptr<IWindowEventArgs> windowEvent) {
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
	case WM_KEYUP:
	{
		if (allKeyUpCallback_ != nullptr)
			allKeyUpCallback_(this, getKeyTypeByWinVirtualKeyCode(wParam));
		break;
	}
	case WM_KEYDOWN:
	{
		auto keyType = getKeyTypeByWinVirtualKeyCode(wParam);
		if (allKeyDownCallback_ != nullptr)
			allKeyDownCallback_(this, keyType);
		if (auto iter = keyCallback_.find(keyType); iter != keyCallback_.end()) {
			for (auto &&[name, callback] : iter->second)
				callback();
		}
		break;
	}
	}
}

void Win32KeyboardInput::onKeyDown(const std::function<void(IkeyboardInput *, KeyType)> &callback) {
	allKeyDownCallback_ = callback;
}

void Win32KeyboardInput::onKeyUp(const std::function<void(IkeyboardInput *, KeyType)> &callback) {
	allKeyUpCallback_ = callback;
}

bool Win32KeyboardInput::isKeyDown(KeyType key) const {
	return keyStatus_.find(key) != keyStatus_.end();
}

void Win32KeyboardInput::bindKey(KeyType key, const std::string &name, const std::function<void(void)> &callback) {
	auto &map = keyCallback_[key];
	map[name] = callback;
}

IkeyboardInput::KeyType Win32KeyboardInput::getKeyTypeByWinVirtualKeyCode(WPARAM wParam) {
	// TODO
	return KeyType::KEY_UNKNOW;
}

}