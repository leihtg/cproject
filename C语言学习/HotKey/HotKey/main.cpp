#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <tchar.h>
#include <Windows.h>

typedef HWND(WINAPI *PROCGETCONSOLEWINDOW)(void);
PROCGETCONSOLEWINDOW consoleWindow;

int main(int argc, char *argv[])
{
	HMODULE hKernel32;
	HWND hCmd;

	//	hKernel32 = GetModuleHandle(_T("kernel32"));
	//	GetConsoleWindow = (PROCGETCONSOLEWINDOW_)GetProcAddress(hKernel32, "GetConsoleWindow");
	//	hCmd = GetConsoleWindow(); //获取到当前cmd窗口句柄
	printf("%d\n", GetConsoleWindow());
	//这里为当前cmd窗口注册热键Ctrl+M
	RegisterHotKey(NULL, 1, MOD_CONTROL | MOD_NOREPEAT, 'M');


	//请问在哪里相应cmd窗口的WM_HOTKEY消息呢？？？

	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0)){
		if (WM_HOTKEY == msg.message){
			HWND hnd = WindowFromPoint(msg.pt);
			SetWindowText(hnd, L"HELLO");
			SetFocus(hnd);
			if (hnd){
				RECT rect ;
				GetWindowRect(hnd, &rect);
				POINT p;
				printf("hello,world--%d,%d\n", rect.top, rect.left);
			}
		}
	}

	return 0;

}