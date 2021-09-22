#include "Win32Application.h"
#include "container/sstd.hpp"
#include "utility/Time.h"
#include "utility/Log.h"
#include "input/InputSystem.h"
#include "input/win32/Win32InputSystemFactory.h"

namespace core {
using namespace utility;

void Win32Application::initialize() {
	initializeGlobalVar();
	inputSystem_ = sstd::make_shared<input::InputSystem>(input::Win32InputSystemFactory(800, 600, "SEngine"));
	SEngineAssert(inputSystem_ != nullptr);
}

void Win32Application::tick() {
	inputSystem_->tick();
	return;
}

void Win32Application::destroy() {
	Log::instanceRelease();
	Time::instanceRelease();
}

bool Win32Application::isQuit() const {
	return isQuit_;
}

void Win32Application::initializeGlobalVar() {
	Time::instanceEmplace();
	std::string timeStr = Time::instance()->getTimeString("%F_%T_log");
	for (auto &c : timeStr) {
		if (c == '-' || c == ':')
			c = '_';
	}
	Log::instanceEmplace(timeStr);
}

}