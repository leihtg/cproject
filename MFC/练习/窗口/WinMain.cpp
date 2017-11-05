#include <windows.h>
#include <stdio.h>
LRESULT CALLBACK WndProc(
						 HWND hwnd,      // handle to window
						 UINT uMsg,      // message identifier
						 WPARAM wParam,  // first message parameter
						 LPARAM lParam   // second message parameter
						 );
int WINAPI WinMain(
				   HINSTANCE hInstance,  // handle to current instance
				   HINSTANCE hPrevInstance,  // handle to previous instance
				   LPSTR lpCmdLine,      // pointer to command line
				   int nCmdShow          // show state of window
				   ){
	WNDCLASS wnd;
	wnd.cbClsExtra=0;
	wnd.cbWndExtra=0;
	wnd.hbrBackground=(HBRUSH)GetStockObject(BLACK_BRUSH);
	wnd.hCursor=LoadCursor(NULL,IDC_ARROW);
	wnd.hIcon=LoadIcon(NULL,IDI_APPLICATION);
	wnd.hInstance=hInstance;
	wnd.lpfnWndProc=WndProc;
	wnd.lpszClassName="窗口";
	wnd.lpszMenuName=NULL;
	wnd.style=CS_HREDRAW|CS_VREDRAW;
	
	RegisterClass(&wnd);
	
	HWND hwnd;
	hwnd=CreateWindow("窗口","要窗口",WS_OVERLAPPEDWINDOW,0,0,600,600,NULL,NULL,hInstance,NULL);
	ShowWindow(hwnd,SW_SHOWNORMAL);
	UpdateWindow(hwnd);
	MSG msg;
	while(GetMessage(&msg,hwnd,0,0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
LRESULT CALLBACK WndProc(
						 HWND hwnd,      // handle to window
						 UINT uMsg,      // message identifier
						 WPARAM wParam,  // first message parameter
						 LPARAM lParam   // second message parameter
						 ){
	int x,y;
		HDC hdc;
		x=LOWORD(lParam);
		
		y=HIWORD(lParam);
	switch(uMsg){
	case WM_CHAR:
		char sz[20];
		sprintf(sz,"char is %d",wParam);
		MessageBox(hwnd,sz,"hehe",MB_YESNO);
		break;
	case WM_LBUTTONDOWN:
	
		hdc=GetDC(hwnd);
		
		
		TextOut(hdc,x,y,"哈哈……",sizeof("哈哈……"));
		ReleaseDC(hwnd,hdc);
		break;
	case WM_PAINT:
		PAINTSTRUCT ps;
		hdc=BeginPaint(hwnd,&ps);
		TextOut(hdc,x,y,"你真好",sizeof("你真好"));
		EndPaint(hwnd,&ps);
		break;
	case WM_CLOSE:
		if(IDYES==MessageBox(hwnd,"你在干啥呢？","友情提示",MB_YESNO)){
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