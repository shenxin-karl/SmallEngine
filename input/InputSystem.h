#pragma once
#include "utility/CommonDeclare.h"
#include "core/IRuntimeMoudle.h"
#include "container/sstd.hpp"
#include "input/IWindow.h"
#include "input/IkeyboardInput.h"
#include "input/IMouseInput.h"

namespace input {

SEngine_INTERFACE IInputSystemFactory {
public:
	int			width_;
	int			height_;
	std::string	title_;
public:
	IInputSystemFactory(int width, int height, const std::string &title);
	virtual sstd::shared_ptr<IWindow> createWindow() const = 0;
	virtual sstd::shared_ptr<IkeyboardInput> createKeyboard() const = 0;
	virtual sstd::shared_ptr<IMouseInput> createMouse() const = 0;
	virtual ~IInputSystemFactory() = default;
};

// InputSystem 封装了窗口键盘和鼠标
class SEngine_API InputSystem : public core::IRuntimeMoudle {
	sstd::shared_ptr<IWindow>		 window_;
	sstd::shared_ptr<IkeyboardInput> keyboard_;
	sstd::shared_ptr<IMouseInput>	 mouse_;
public:	// IRuntimeMoudle
	InputSystem(const IInputSystemFactory &factor);
	void initialize() override;
	void destroy() override;
	void tick() override;
public:
	sstd::shared_ptr<IWindow> getWindow() const;
	sstd::shared_ptr<IkeyboardInput> getkeyboardInput() const;
	sstd::shared_ptr<IMouseInput> getMouseInput() const;
	~InputSystem() = default;
};


}