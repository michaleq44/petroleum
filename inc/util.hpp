#ifndef UTIL_HPP
#define UTIL_HPP
#include <main.hpp>
#include <locale>
#include <codecvt>

wstring to_wstring(const string& str);
string to_utf8(const wstring& str);

#endif
