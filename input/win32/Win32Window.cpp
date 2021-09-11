#include "Win32Window.h"
#include "utility/Log.h"
#include "Win32WindowEventArgs.h"
#include "IHandleWindowEvent.h"

namespace input {

using namespace tool;

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
		loginfo.format(Log::Error, "RegisterClassEx error: {}\n", GetLastError());
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
		nullptr,
		nullptr,
		hins,
		nullptr
	);

	if (hwnd_ == nullptr) {
		loginfo.format(Log::Error, "CreateWindowEx error: {}\n", GetLastError());
		return;
	}
	UpdateWindow(hwnd_);
	ShowWindow(hwnd_, SW_SHOW);
	hdc_ = GetDC(hwnd_);
	hwnd2Window_.insert(std::make_pair(hwnd_, this));
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

void Win32Window::registerMessage(IHandleWindowEvent *ptr) const {
	handleMessage_.push_back(ptr);
}

Win32Window::~Win32Window() {
	if (hwnd_ == nullptr)
		return;
	hwnd2Window_.erase(hwnd_);
	DestroyWindow(hwnd_);
}

void Win32Window::events(std::shared_ptr<IWindwoEventArgs> eventArgs) {
	for (IHandleWindowEvent *objPtr : handleMessage_)
		objPtr->handleWindowMessage(windowPtr, eventPtr);
}

LRESULT CALLBACK Win32Window::wndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	Win32Window *windowPtr = nullptr;
	if (auto iter = hwnd2Window_.find(hwnd); iter != hwnd2Window_.end())
		windowPtr = iter->second;
	else
		return;

	auto eventArgs = std::make_shared<Win32WindowEventArgs>(hwnd, msg, wParam, lParam);
	windowPtr->events(eventArgs) :
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

// TODO ´ý²âÊÔ
}