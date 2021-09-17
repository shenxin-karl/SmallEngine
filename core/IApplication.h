#include "utility/CommonDeclare.h"
#include "IRuntimeMoudle.h"

namespace core {
 
SEngine_INTERFACE IApplication : public IRuntimeMoudle {
public:
	virtual bool isQuit() const = 0;
	virtual ~IApplication() = default;
};

}