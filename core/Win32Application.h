#pragma once
#include "utility/CommonDeclare.h"
#include "IApplication.h"
#include "container/sstd.hpp"


namespace input {
SEngine_INTERFACE InputSystem;
}

namespace core {

class SEngine_API Win32Application : public IApplication {
	bool isQuit_ = false;
	sstd::shared_ptr<input::InputSystem> inputSystem_;
public:
	Win32Application() = default;
	virtual void initialize() override;
	virtual void tick() override;
	virtual void destroy() override;
	virtual bool isQuit() const override;
	virtual ~Win32Application() = default;
	static void initializeGlobalVar();
};

}