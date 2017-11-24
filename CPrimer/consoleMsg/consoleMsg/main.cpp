#include <Windows.h>
#include <iostream>

using namespace std;

int maina(){
	RegisterHotKey(NULL, 1, NULL, 'M');
	RegisterHotKey(NULL, 2, NULL, 'C');
	MSG msg;
	while (GetMessage(&msg, NULL, NULL, NULL)){
		HWND hnd = WindowFromPoint(msg.pt);
		char buf[100];
		GetClassName(hnd, buf, 100);
		cout << buf << endl;
		cout << hnd << endl;
		if (msg.wParam == 2){
			//PostMessage(hnd,WM_CLOSE,NULL,NULL);
		}
	}

	system("pause");
	return 0;
}

HANDLE hOut;
HANDLE hIn;

void main()
{
	INPUT_RECORD mouseRec;
	DWORD state = 0, res;
	COORD pos;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE); // 获取标准输出设备句柄
	hIn = GetStdHandle(STD_INPUT_HANDLE); // 获取标准输入设备句柄
	while (1)
	{

		//printf("123");	
		ReadConsoleInput(hIn, &mouseRec, 1, &res);
		if (mouseRec.EventType == MOUSE_EVENT)
		{
			if (mouseRec.Event.MouseEvent.dwEventFlags == MOUSE_MOVED)
			{
				pos = mouseRec.Event.MouseEvent.dwMousePosition;
				printf("(%d,%d)\n", pos.X, pos.Y);
			}
			//SetCursorPos(
		}
	}
}
