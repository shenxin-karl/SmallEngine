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

	static std::unique_ptr<Log> initSingleton();

	template<typename... Args>
	Log &format(const std::string_view &fmt, Args&&... args) {
		return format(Normal, fmt, std::forward<Args>(args)...);
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

	friend Log &operator<<(Log &log, std::ostream &(*f)(std::ostream &)) {
		log.file_ << f;
		log.setColor(log.lastType_);
		(log.lastType_ == Error ? std::cerr : std::cout) << f;
		return log;
	}

	Log(std::string fileName);
private:
	void setColor(LogType type) const;
private:
	std::fstream	file_;
	std::string		fileName_;
	LogType			lastType_;
};

// 为这个全局的 Log 对象分配一个别名
inline Log &loginfo = *Log::instance();		

}


