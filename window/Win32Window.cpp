#include "Win32Window.h"

namespace window {

Win32Window::Win32Window(int width, int height, const std::string &title)
: hwnd_(nullptr), hdc_(nullptr), shouldClose_(false), pause_(false)
, width_(width), height_(height), title_(title), resizeCallback_(nullptr)
{
	HINSTANCE hins = GetModuleHandle(nullptr);
	WNDCLASSEX wc;
	wc.cbSize = sizeof(wc);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hins;	
	wc.hIcon = nullptr;
	wc.hIconSm = nullptr;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = nullptr;
	wc.lpfnWndProc = wndProc;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = "LYSM_class";

	if (!RegisterClassEx(&wc)) {
		//std::cerr << "RegisterClassEx error: " << GetLastError() << std::endl;
		return;
	}

	hwnd_ = CreateWindowEx(
		WS_EX_TOPMOST,
		"LYSM_class",
		title.c_str(),
		WS_OVERLAPPEDWINDOW,
		0,
		0,
		width,
		height,
		0,
		0,
		hins,
		0
	);

	if (hwnd_ == nullptr) {
		//std::cerr << "CreateWindowEx error:" << GetLastError() << std::endl;
		return;
	}
	UpdateWindow(hwnd_);
	ShowWindow(hwnd_, SW_SHOW);
	hdc_ = GetDC(hwnd_);
	SEngineAssert(hdc_ != nullptr);
}

bool Win32Window::shouldClose() const {
	return shouldClose_;
}

void Win32Window::resize(int width, int height) {
	RECT rect;
	GetWindowRect(hwnd_, &rect);
	SetWindowPos(hwnd_, HWND_TOP, rect.left, rect.top, width, height, SWP_NOZORDER);
	width_ = width;
	height_ = height;
}

void Win32Window::getSize(int &width, int &height) const {
	width = width_;
	height = height_;
}

Win32Window::ResizeCallBackType 
Win32Window::handleResize(const ResizeCallBackType &callback) {
	auto res = resizeCallback_;
	resizeCallback_ = callback;
	return res;
}

bool Win32Window::isPause() const {
	return pause_;
}

void Win32Window::pause(bool flag) {
	pause_ = flag;
}

void Win32Window::setTitle(const std::string &title) {
	title_ = title_;
	SetWindowText(hwnd_, title.c_str());
}

std::string Win32Window::getTitle() const {
	return title_;
}

void Win32Window::pollEvent() const {
	if (isPause())
		return;

	MSG msg;
	while (PeekMessage(&msg, hwnd_, 0, 0, PM_REMOVE))
		DispatchMessage(&msg);
}

void Win32Window::close() {
	shouldClose_ = true;
	CloseWindow(hwnd_);
}

Win32Window::~Win32Window() {
	if (hwnd_ == nullptr)
		return;
	DestroyWindow(hwnd_);
}

LRESULT CALLBACK Win32Window::wndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {

}

// TODO ´ý²âÊÔ
}