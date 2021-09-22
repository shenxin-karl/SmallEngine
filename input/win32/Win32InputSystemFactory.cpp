#include "Win32InputSystemFactory.h"
#include "Win32Window.h"
#include "Win32KeyboardInput.h"
#include "Win32MouseInput.h"

namespace input {

Win32InputSystemFactory::Win32InputSystemFactory(int width, int height, const std::string &title)
: IInputSystemFactory(width, height, title) {
}

sstd::shared_ptr<IWindow> Win32InputSystemFactory::createWindow() const {
	return sstd::make_shared<Win32Window>(width_, height_, title_);
}

sstd::shared_ptr<IkeyboardInput> Win32InputSystemFactory::createKeyboard() const {
	return sstd::make_shared<Win32KeyboardInput>();
}

sstd::shared_ptr<input::IMouseInput> Win32InputSystemFactory::createMouse() const {
	return sstd::make_shared<Win32MouseInput>();
}

}
