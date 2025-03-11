#include <main.hpp>

HBRUSH bgbrush;
WNDCLASSEX wc;
Window win(wc, nullptr, IDR_MENU1, 0, 0);

int main(int argc, char** argv) {
    return wWinMain(GetModuleHandle(nullptr), nullptr, GetCommandLine(), SW_SHOWNORMAL);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd) {
    bgbrush = CreateSolidBrush(RGB(20, 0, 90));

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = static_cast<HICON>(LoadImage(hInstance, MAKEINTRESOURCE(ICON1), IMAGE_ICON, 32, 32, 0));
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.hbrBackground = bgbrush;
    wc.lpszMenuName = nullptr;
    wc.lpszClassName = L"Petroleum";
    wc.hIconSm = wc.hIcon;


    win = Window(wc, hInstance, IDR_MENU1, 800, 600);
    win.init(nShowCmd);

    win.run();

    return 0;
}

LRESULT WINAPI WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            ExitProcess(0);
        case WM_SIZE:
            win.width = LOWORD(lParam);
            win.height = HIWORD(lParam);
            cout << win.width << " " << win.height << endl;
        break;

        default: return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}