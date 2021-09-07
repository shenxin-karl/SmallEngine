#pragma once
#include "CommonDeclare.h"
#include "Singleton.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <format>

namespace tool {

class SENGINE_API Log : public Singleton<Log> {

public:
	enum LogType {
		Normal,
		Error,
		Warning,
		Tips,
	};

	std::unique_ptr<Log> initSingleton() {

	}

	template<typename... Args>
	Log &format(const std::string &fmt, Args&&... args) {
		return format(Normal, fmt, std::forward<Args>(args)...);
	}

	template<typename... Args>
	Log &format(const std::string_view &fmt, Args&&... args) {
		return format(Normal, fmt, std::forward<Args>(args)...);
	}

	template<typename... Args>
	Log &format(LogType type, const std::string &fmt, Args&&... args) {
		setColor(type);
		std::string msg = std::format(fmt, std::forward<Args>(args)...);
		(type == Error ? std::cerr : std::cout) << msg;
		file_ << msg;
		lastType_ = type;
		return *this;
	}

	template<typename... Args>
	Log &format(LogType type, const std::string_view &fmt, Args&&... args) {
		setColor(type);
		std::string msg = std::format(fmt, std::forward<Args>(args)...);
		(type == Error ? std::cerr : std::cout) << msg;
		file_ << msg;
		lastType_ = type;
		return *this;
	}
private:
	void setColor(LogType type) const;
	std::fstream	file_;
	std::string		fileName_;
	LogType			lastType_;
};
	
}

}
