#ifndef WINDOW_HPP
#define WINDOW_HPP
#include <main.hpp>

class Window {
    public:
    Window(const WNDCLASSEX &, HINSTANCE, WORD, int, int);

    void init(int);

    static void run();

    HWND hwnd;
    int width;
    int height;
    bool initialized;

    private:
};
#endif
