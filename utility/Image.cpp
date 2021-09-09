#include "Image.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include "VariantVisitor.h"

namespace tool {

int getChannelSizeByType(ImageChannelType mode) {
	return static_cast<int>(mode);
}

ImageChannelType channelSizeConvertType(int size) {
	if (size == 0 || size >= static_cast<int>(ImageChannelType::MAX_COUNT)) {
		assert(false, "channelSizeConvertType invalid size");
		return ImageChannelType::NONE;
	}
	return static_cast<ImageChannelType>(size);
}

Image::Image()
: dataPtr_(static_cast<float *>(nullptr)), channelType_(ImageChannelType::NONE)
, width_(0), heiht_(0) {
}

Image::Image(Image &&other) noexcept : Image() {
	*this = std::move(other);
}

Image::Image(const std::string &path) : Image() {
	loadFromFile(path);
}

Image::Image(const char *buffer, int height, int widgth) : Image() {
	loadFromMemory(buffer, height, widgth);
}

void Image::loadFromFile(const std::string &path, ImageChannelType mode) {
	release();
	int channel;
	int expect = getChannelSizeByType(mode);
	if (path.find_last_of(".hdr") != std::string::npos)
		dataPtr_ = stbi_load(path.c_str(), &width_, &heiht_, &channel, expect);
	else
		dataPtr_ = stbi_loadf(path.c_str(), &width_, &heiht_, &channel, expect);
}

void Image::loadFromMemory(const char *buffer, int height, int widgth) {
	//stbi_load_from_memory
	// TODO
}

void Image::release() {
	std::visit(
		[](auto *ptr) {
			stbi_image_free(static_cast<void *>(ptr));
		},
		dataPtr_
			);
	dataPtr_ = static_cast<float *>(nullptr);
	channelType_ = ImageChannelType::NONE;
}

Image::~Image() {
	release();
}

Image &Image::operator=(Image &&other) noexcept {
	if (this == &other)
		return *this;

	dataPtr_ = std::exchange(other.dataPtr_, static_cast<float *>(nullptr));
	channelType_ = std::exchange(other.channelType_, ImageChannelType::NONE);
	return *this;
}

}