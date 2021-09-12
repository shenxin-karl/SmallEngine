#pragma once
#include "CommonDeclare.h"
#include <variant>
#include <string>

namespace utility {

enum class ImageChannelType {
	NONE			= 0,
	ALPHA			= 1,
	LUMINANCE_ALPHA = 2,
	RGB				= 3,
	RGBA			= 4,
	MAX_COUNT,
};

int getChannelSizeByType(ImageChannelType mode);
ImageChannelType channelSizeConvertType(int size);

class SENGINE_API Image {
	std::variant<unsigned char*, float*> dataPtr_;
	ImageChannelType					 channelType_;
	int									 width_;
	int									 heiht_;
public:
	Image();
	~Image();
	Image(Image &&other) noexcept;
	Image &operator=(const Image&) = delete;
	Image &operator=(Image &&other) noexcept;
	Image(const std::string &path);
	Image(const char *buffer, int height, int widgth);
	void loadFromFile(const std::string &path, ImageChannelType mode = ImageChannelType::NONE);
	void loadFromMemory(const char *buffer, int height, int widgth);
	void release();

	template<typename T> requires(std::is_same_v<T, unsigned char *> || std::is_same_v<T, float *>)
	T getData() const {
		return std::get_if<T>(dataPtr_);
	}
};

}