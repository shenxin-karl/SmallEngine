#include "Win32Application.h"
#include "container/sstd.hpp"
#include "utility/Time.h"
#include "utility/Log.h"

namespace core {
using namespace utility;
void Win32Application::initialize() {
	Time::instanceEmplace();
	std::string timeStr = Time::instance()->getTimeString("%F_%T_log");
	for (auto &c : timeStr) {
		if (c == '-' || c == ':')
			c = '_';
	}
	Log::instanceEmplace(timeStr);
}

void Win32Application::tick() {
	return;
}

void Win32Application::destroy() {
	Log::instanceRelease();
	Time::instanceRelease();
}

bool Win32Application::isQuit() const {
	return isQuit_;
}

}