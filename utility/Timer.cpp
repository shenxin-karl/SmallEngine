#include "Timer.h"

namespace tool {

float Timer::getGamePlayTime() const {
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<float> diff = end - startTime_;
	return diff.count();
}

int Timer::getFps() const {
	return lastFps_;
}

void Timer::updateFps() {
	++fps_;
	int time = static_cast<int>(getGamePlayTime());
	if (time > lastTime_) {
		lastFps_ = fps_;
		fps_ = 0;
	}
}

}