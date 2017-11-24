#include <windows.h>
#include <stdio.h>

LRESULT CALLBACK WinSunProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow){
	WNDCLASS wndcls;
	
	wndcls.cbClsExtra=0;
	wndcls.cbWndExtra=0;
	wndcls.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
	wndcls.hCursor=LoadCursor(NULL,IDC_CROSS);
	wndcls.hIcon=LoadIcon(NULL,IDI_ERROR);
	wndcls.hInstance=hInstance;
	wndcls.lpfnWndProc=WinSunProc;
	wndcls.lpszClassName="KeyMessageDemo";
	wndcls.lpszMenuName=NULL;
	wndcls.style=CS_HREDRAW|CS_VREDRAW;
	
	RegisterClass(&wndcls);

	HWND hwnd;

	hwnd=CreateWindow("KeyMessageDemo","KeyMessageDemo",WS_OVERLAPPEDWINDOW,200,200,600,400,NULL,NULL,hInstance,NULL);

	ShowWindow(hwnd,SW_SHOWNORMAL);
	UpdateWindow(hwnd);

	MSG msg;
	while(GetMessage(&msg,NULL,0,0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

LRESULT CALLBACK WinSunProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam){
	char szStr[64]={0};
	HDC hdc;
	switch(uMsg){
	case WM_KEYUP:
		hdc=GetDC(hwnd);
		sprintf(szStr,"%c按键被释放\r",wParam);
		TextOut(hdc,100,50,szStr,strlen(szStr));
		ReleaseDC(hwnd,hdc);
		break;
	case WM_KEYDOWN:
		hdc=GetDC(hwnd);
		sprintf(szStr,"%c按键被按下\r",wParam);
		TextOut(hdc,100,0,szStr,strlen(szStr));
		ReleaseDC(hwnd,hdc);
		break;
	case WM_CLOSE:
		if(IDYES==MessageBox(hwnd,"是否真的结束？","友情提示",MB_YESNO)){
			DestroyWindow(hwnd);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd,uMsg,wParam,lParam);

	}
	return 0;
}