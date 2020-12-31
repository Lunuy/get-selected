
#include "pch.h";

using namespace std;

#define DllExport __declspec(dllexport)
#include <string>;

#ifdef __cplusplus
extern "C" {
#endif
DllExport const char* getSelected() {
    HWND hWnd = GetForegroundWindow();
    DWORD fromId = GetCurrentThreadId();
    DWORD pid = GetWindowThreadProcessId(hWnd, NULL);
    AttachThreadInput(fromId, pid, TRUE);
    HWND focus = GetFocus();

    DWORD start;
    DWORD end;
    SendMessage(focus, EM_GETSEL, (WPARAM)&start, (LPARAM)&end);

    int len = SendMessage(focus, WM_GETTEXTLENGTH, 0, 0);

    if (start >= end) return 0;

    TCHAR* text = new TCHAR[len + 1]();
    SendMessage(focus, WM_GETTEXT, len + 1, (LPARAM)text);

    CString cstr = text;
    string str = (string)CT2CA(cstr);

    string sub = str.substr(start, end - start);
    int cLen = strlen(sub.c_str());
    char* c = new char[cLen + 1]();
    strcpy_s(c, cLen + 1, sub.c_str());
    
    return c;
}
#ifdef __cplusplus
}
#endif