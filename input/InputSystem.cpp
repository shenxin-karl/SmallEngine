#include "InputSystem.h"

namespace input {

IInputSystemFactory::IInputSystemFactory(int width, int height, const std::string &title)
: width_(width), height_(height), title_(title_) {}


InputSystem::InputSystem(const IInputSystemFactory &factor)
: window_(factor.createWindow()), keyboard_(factor.createKeyboard())
, mouse_(factor.createMouse()) {

	SEngineAssert(window_ != nullptr);
	SEngineAssert(keyboard_ != nullptr);
	SEngineAssert(mouse_ != nullptr);
	window_->registerMessage(keyboard_.get());
	window_->registerMessage(mouse_.get());
}


void InputSystem::initialize() {

}

void InputSystem::destroy() {

}

void InputSystem::tick() {
	window_->pollEvent();
}

sstd::shared_ptr<input::IWindow> InputSystem::getWindow() const {
	return window_;
}

sstd::shared_ptr<input::IkeyboardInput> InputSystem::getkeyboardInput() const {
	return keyboard_;
}

sstd::shared_ptr<input::IMouseInput> InputSystem::getMouseInput() const {
	return mouse_;
}

}