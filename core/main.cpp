#include <iostream>
#include "utility/Log.h"
#include "utility/Time.h"
#include "utility/MemoryStatistics.hpp"

struct Test {
	DeclareMemoryStatistics(Test)
};


int main() {
	using namespace utility;
	std::cout << "gamePlayTime: " << Time::instance()->getGamePlayTime() << std::endl;
	std::cout << "time: " << Time::instance()->getTime() << std::endl;
	std::cout << "timeString: " << Time::instance()->getTimeString() << std::endl;


	//auto ptr = new Test;
	auto ptr1 = utility::make_shared<Test>();
	auto ptr2 = utility::make_unique<Test>();
	std::cout << MemoryStatistics<Test>::getCount() << std::endl;
	std::cout << MemoryStatistics<Test>::getSize() << std::endl;

	return 0;
}

