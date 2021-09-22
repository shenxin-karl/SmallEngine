#pragma once
#include <Windows.h>
#include "utility/CommonDeclare.h"
#include "input/IkeyboardInput.h"
#include "container/sstd.hpp"
namespace input {

SEngine_INTERFACE IWindow;
SEngine_INTERFACE IWindowEventArgs;

class Win32KeyboardInput : public IkeyboardInput {
	sstd::unordered_map<KeyType, bool>	keyStatus_;
	std::function<void(IkeyboardInput *, KeyType)>		allKeyDownCallback_;
	std::function<void(IkeyboardInput *, KeyType)>		allKeyUpCallback_;
	sstd::unordered_map<KeyType, sstd::unordered_map<std::string, std::function<void(void)>>> keyCallback_;
public:
	virtual void handleWindowMessage(IWindow *window, std::shared_ptr<IWindowEventArgs> windowEvent) override;
	virtual void onKeyDown(const std::function<void(IkeyboardInput *, KeyType)> &callback) override;
	virtual void onKeyUp(const std::function<void(IkeyboardInput *, KeyType)> &callback) override;
	virtual bool isKeyDown(KeyType key) const override;
	virtual void bindKey(KeyType key, const std::string &name, const std::function<void(void)> &callback) override;
	virtual ~Win32KeyboardInput() override = default;
	static KeyType getKeyTypeByWinVirtualKeyCode(WPARAM wParam);
};

}