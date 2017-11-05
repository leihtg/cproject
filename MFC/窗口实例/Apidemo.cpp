#include <windows.h>

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow){
	WNDCLASS	wndclass;
	HWND hwnd;
	MSG msg;

	wndclass.style=CS_HREDRAW|CS_VREDRAW;

	wndclass.cbClsExtra=0;
	wndclass.cbWndExtra=0;
	wndclass.hInstance=hInstance;
	wndclass.hIcon=LoadIcon(NULL,IDI_APPLICATION);
	wndclass.hCursor=LoadCursor(NULL,IDC_ARROW);
	wndclass.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName=NULL;
	wndclass.lpszClassName="window窗口创建";
	wndclass.lpfnWndProc=WndProc;
	if(!RegisterClass(&wndclass))return FALSE;

	hwnd=CreateWindow("window窗口创建","window窗口创建",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,
		CW_USEDEFAULT,CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);
	
	ShowWindow(hwnd,SW_SHOWNORMAL);
	UpdateWindow(hwnd);

	while(GetMessage(&msg,NULL,0,0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam){
	switch(message){
	case WM_PAINT:
		HDC hdc;
		PAINTSTRUCT ps;
		hdc=BeginPaint(hwnd,&ps);
		TextOut(hdc,10,20,"哈哈,windows编程创建的窗口！",28);
		EndPaint(hwnd,&ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd,message,wParam,lParam);
}