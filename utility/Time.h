#pragma once
#include <chrono>
#include <string_view>
#include "CommonDeclare.h"
#include "Singleton.hpp"

namespace utility {

class SENGINE_API Time : public Singleton<Time> {
public:
	float getGamePlayTime() const;
	int getFps() const;
	void updateFps();
	std::time_t getTime() const;
	std::string getTimeString(const std::string_view &fmt = "%F %T") const;
	static std::string timestampToString(std::time_t t, const std::string_view &fmt = "%F %T");
	static std::unique_ptr<Time> initSingleton();
private:
	std::chrono::steady_clock::time_point startTime_  = std::chrono::steady_clock::now();
	int lastFps_									  = 0;
	int fps_										  = 0;
	float lastTime_								      = 0.f;
};

}