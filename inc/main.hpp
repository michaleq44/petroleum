#ifndef MAIN_HPP
#define MAIN_HPP

#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <iostream>
using namespace std;

#include <res.h>
#include <util.hpp>
#include <window.hpp>

LRESULT WINAPI WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

#endif
