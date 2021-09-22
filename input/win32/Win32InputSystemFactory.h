#pragma once
#include "utility/CommonDeclare.h"
#include "input/InputSystem.h"

namespace input {

class SEngine_API Win32InputSystemFactory : public IInputSystemFactory {
public:
	Win32InputSystemFactory(int width, int height, const std::string &title);
	virtual sstd::shared_ptr<IWindow> createWindow() const override;
	virtual sstd::shared_ptr<IkeyboardInput> createKeyboard() const override;
	virtual sstd::shared_ptr<IMouseInput> createMouse() const override;
	virtual ~Win32InputSystemFactory() = default;
};

}

