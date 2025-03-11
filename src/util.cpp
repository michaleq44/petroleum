#include <util.hpp>

wstring to_wstring(const string& str) {
    wstring_convert<codecvt_utf8_utf16<wchar_t>> conv;
    return conv.from_bytes(str);
}

string to_utf8(const wstring& str) {
    wstring_convert<codecvt_utf8_utf16<wchar_t>> conv;
    return conv.to_bytes(str);
}