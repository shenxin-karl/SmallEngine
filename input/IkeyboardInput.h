#pragma once
#include <functional>
#include "IHandleWindowEvent.h"

namespace input {

// 对键盘输入的抽象接口
SEngine_INTERFACE IkeyboardInput : public IHandleWindowEvent {
public:
	enum class KeyType {
		KEY_UNKNOW,
		KEY_w, KEY_W,
		KEY_s, KEY_S,
		KEY_a, KEY_A,
		KEY_d, KEY_D,
		KEY_ESC, KEY_SPACE,
		KEY_ENTER,
	};

	virtual void onKeyDown(const std::function<void(IkeyboardInput *, KeyType)> &callback) = 0;
	virtual void onKeyUp(const std::function<void(IkeyboardInput *, KeyType)> &callback) = 0;
	virtual bool isKeyDown(KeyType key) const = 0;
	virtual void bindKey(KeyType key, const std::string &name, const std::function<void(void)> &callback) = 0;
	virtual ~IkeyboardInput() = default;
};

}