#include "Log.h"
#ifdef WIN32 
#include "Windows.h"
#include "Time.h"
#endif

namespace utility {

std::unique_ptr<utility::Log> Log::initSingleton() {
	return std::make_unique<Log>("test_file");
}

Log::Log(std::string fileName) 
: file_(fileName, std::ios::app | std::ios::out)
, fileName_(fileName), lastType_(LogType::Normal) {
	SEngineAssert(static_cast<bool>(file_.is_open()));
}

void Log::setColor(Log::LogType type) const {
#ifdef WIN32
	constexpr static int colors[] = {
		BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
		BACKGROUND_INTENSITY | BACKGROUND_RED,
		BACKGROUND_INTENSITY | BACKGROUND_BLUE,
		BACKGROUND_INTENSITY | BACKGROUND_GREEN,
	};
	auto color = colors[type];
	auto handle = GetStdHandle((type == Error ? STD_ERROR_HANDLE : STD_OUTPUT_HANDLE));
	SetConsoleTextAttribute(handle, static_cast<WORD>(color));
#else
	static const char *colors[] = {
		"\033[22;39m",
		"\033[22;32m",
		"\033[22;35m",
		"\033[22;33m",
	};
	(type == Error ? std::cerr : std::cout) << colors[static_cast<int>(type)];
#endif // WIN32
}

}
