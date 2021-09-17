#include "Win32Application.h"
#include "container/sstd.hpp"

int main() {
	std::unique_ptr<core::IApplication> application = sstd::make_unique<core::Win32Application>();
	try {
		application->initialize();
	} catch (std::string msg) {
		std::cerr << msg << std::endl;
	} catch (...) {
		std::cerr << "unknow error!" << std::endl;
	}

	while (!application->isQuit()) {
		application->tick();
	}
	application->destroy();
}
