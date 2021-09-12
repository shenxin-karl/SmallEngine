#include <iostream>
#include "utility/Log.h"
#include "utility/Time.h"

int main() {
	using namespace utility;
	std::cout << "gamePlayTime: " << Time::instance()->getGamePlayTime() << std::endl;
	std::cout << "time: " << Time::instance()->getTime() << std::endl;
	std::cout << "timeString: " << Time::instance()->getTimeString() << std::endl;
	//loginfo.format("hello world") << std::endl;
	return 0;
}