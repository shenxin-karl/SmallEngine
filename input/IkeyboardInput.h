#pragma once
#include "IHandleWindowEvent.h"
#include <functional>

namespace input {

// 键盘事件的接口
INTERFACE IkeyboardInput : public IHandleWindowEvent {
public:
	enum KeyType {
		KEY_w, KEY_W,
		KEY_s, KEY_S,
		KEY_a, KEY_A,
		KEY_d, KEY_D,
		KEY_ESC, KEY_SPACE,
		KEY_ENTER,
	};

	virtual void onKeyDown(const std::function<void(KeyType)> &callback) = 0;
	virtual void onKeyUp(const std::function<void(KeyType)> &callback) = 0;
	virtual bool isKeyDown(KeyType key) const = 0;
	virtual ~IkeyboardInput() = default;
};

}