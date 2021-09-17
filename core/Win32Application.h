#pragma once
#include "utility/CommonDeclare.h"
#include "IApplication.h"

namespace core {

class SENGINE_API Win32Application : public IApplication {
	bool isQuit_ = false;
public:
	Win32Application() = default;
	virtual void initialize() override;
	virtual void tick() override;
	virtual void destroy() override;
	virtual bool isQuit() const override;
	virtual ~Win32Application() = default;
};

}