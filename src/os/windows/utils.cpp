#include <Windows.h>
#include <string>

std::wstring local_codepage_to_utf16(std::string input) {
    size_t       need = MultiByteToWideChar(CP_ACP, 0, input.c_str(), input.size(), 0, 0);
    wchar_t     *wstr = static_cast<wchar_t *>(malloc(need + sizeof(wchar_t)));
    size_t       used = MultiByteToWideChar(CP_ACP, 0, input.c_str(), input.size(), wstr, need);
    std::wstring result(wstr, used);
    free(wstr);
    return result;
}

std::string utf16_to_local_codepage(wchar_t * data, size_t len) {
    BOOL ignore;

    size_t      need = WideCharToMultiByte(CP_ACP, 0, data, len, 0, 0, "?", &ignore);
    char       *cstr = static_cast<char *>(malloc(need + 1));
    size_t      used = WideCharToMultiByte(CP_ACP, 0, data, len, cstr, need, "?", &ignore);
    std::string result(cstr, used);
    free(cstr);
    return result;
}