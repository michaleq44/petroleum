#include <window.hpp>

Window::Window(const WNDCLASSEX &wex, const HINSTANCE hInst, const WORD menu, const int w, const int h) {
    RegisterClassEx(&wex);
    width = w+16;
    height = h+59;
    initialized = false;
    hwnd = CreateWindowEx(0, wex.lpszClassName, wex.lpszClassName, WS_VISIBLE | WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, width, height,
        nullptr, LoadMenu(hInst, MAKEINTRESOURCE(menu)), hInst, nullptr);
}

void Window::init(const int nCmdShow) {
    ShowWindow(hwnd, nCmdShow);
    initialized = true;
}

void Window::run() {
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}