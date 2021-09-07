#pragma once
#include <chrono>
#include "CommonDeclare.h"
#include "Singleton.hpp"

namespace tool {

class SENGINE_API Timer : public Singleton<Timer> {
public:
	float getGamePlayTime() const;
	int getFps() const;
	void updateFps();
private:
	std::chrono::steady_clock::time_point startTime_  = std::chrono::steady_clock::now();
	int lastFps_									  = 0;
	int fps_										  = 0;
	float lastTime_								      = 0.f;
};

}