#include "Time.h"
#include <sstream>

namespace tool {

float Time::getGamePlayTime() const {
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<float> diff = end - startTime_;
	return diff.count();
}

int Time::getFps() const {
	return lastFps_;
}

void Time::updateFps() {
	++fps_;
	int time = static_cast<int>(getGamePlayTime());
	if (time > lastTime_) {
		lastFps_ = fps_;
		fps_ = 0;
	}
}

std::time_t Time::getTime() const {
	auto now = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch());
	return now.count();
}

std::string Time::getTimeString(const std::string_view &fmt) const {
	auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	return timestampToString(t);
}

std::string Time::timestampToString(std::time_t t, const std::string_view &fmt) {
	std::stringstream sbuf;
	sbuf << std::put_time(std::localtime(&t), fmt.data());
	return sbuf.str();
}

std::unique_ptr<Time> Time::initSingleton() {
	return std::make_unique<Time>();
}

}