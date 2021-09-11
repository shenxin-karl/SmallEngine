#include "Win32WindowEventArgs.h"

namespace input {

Win32WindowEventArgs::Win32WindowEventArgs(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
: hwnd_(hwnd), msg_(msg), wParam_(wParam), lParam_(lParam) {
}

}