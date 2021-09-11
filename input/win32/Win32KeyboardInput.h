#pragma once
#include <unordered_map>
#include "utility/CommonDeclare.h"
#include "input/IkeyboardInput.h"

namespace input {

SEngine_INTERFACE IWindow;
SEngine_INTERFACE IWindwoEventArgs;

class Win32KeyboardInput : public IkeyboardInput {
	std::unordered_map<KeyType, bool>	keyStatus_;
	std::function<void(KeyType)>	keyDownCallback_;
	std::function<void(KeyType)>	keyUpCallback_;
public:
	virtual void handleWindowMessage(IWindow *window, std::shared_ptr<IWindwoEventArgs> windowEvent) override;
	virtual void onKeyDown(const std::function<void(KeyType)> &callback) override;
	virtual void onKeyUp(const std::function<void(KeyType)> &callback) override;
	virtual bool isKeyDown(KeyType key) const override;
	virtual ~Win32KeyboardInput() override = default;
};

}