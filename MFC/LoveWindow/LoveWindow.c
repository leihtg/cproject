/***************************************************************************************
*                                                                                      *
*                                                                                      *
*	实现功能:                                                                          *
*	1.	一个主窗口包含三个子窗口，分别完成：播放音乐和显示诗歌                         *
*	、显示动画位图、显示动态变换位图                                                   *
*	2.  鼠标左键点击左边的长方形子窗口，可以显示播放音乐的控件，                       *
*	在这里，你可以选择自己本地上的音乐文件，支持基本上所有的格式                       *
*	3.	此程序是我第二次为自己的女朋友编写的，在这里分享给大家，希望能给大家带来灵感   *
*                                                                                      *
*                                                                                      *
*                                                                                      *
*------------------------------------源文件名：LoveWindow.c                            *
*---------------------------------------编码者：黎小华                                 *
*--------------------------------------时间：2013/08/19                                *
****************************************************************************************/

#include<windows.h>
#include<stdio.h>
#include <vfw.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"resource.h"

#pragma comment(lib,"vfw32.lib")

//定时器ID
#define ID_TIMER_POEM		0
#define ID_TIMER_LOVE		1
#define ID_TIMER_BMP		2
//窗口的个数
#define NUM					3

//为了避免函数的参数设定太多，显得冗余，因此设定一下变量为全局
FILE	*fp = NULL;//文件指针
TCHAR	word[2];//字符数组 , 保存读取的一个字
int		row, col;//标记行号和列号
int		cxChar, cyChar;//系统字符的size  分别是字符的平均宽度、字符的高度


LRESULT CALLBACK WndProc	(HWND, UINT, WPARAM, LPARAM);//主窗口回调函数
LRESULT CALLBACK PoemChild	(HWND, UINT, WPARAM, LPARAM);//诗歌子窗口回调函数
LRESULT CALLBACK LoveChild	(HWND, UINT, WPARAM, LPARAM);//动画位图子窗口回调函数
LRESULT CALLBACK BmpChild	(HWND, UINT, WPARAM, LPARAM);//动态变换位图子窗口回调函数
int ShowWord(HDC);//显示一个字


int WINAPI WinMain(HINSTANCE hInstance,
				   HINSTANCE hPrevInstance,
                   PSTR szCmdLine,
				   int iCmdShow)
{
	static	TCHAR	szAppName[] = TEXT("LoveWindow");
	HWND			hwnd;
	MSG				msg;
	WNDCLASS		wndclass;
	int				cxScreen, cyScreen;
	
	wndclass.style			= CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc	= WndProc;
	wndclass.cbClsExtra		= 0;
	wndclass.cbWndExtra		= 0;
	wndclass.hInstance		= hInstance;
	wndclass.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wndclass.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground	= (HBRUSH)GetStockObject(WHITE_BRUSH);//CreateSolidBrush(RGB(57, 138, 219));
	wndclass.lpszMenuName	= NULL;
	wndclass.lpszClassName	= szAppName;
	
	if(!RegisterClass(&wndclass))
	{
		MessageBox(NULL, TEXT("This program requires Windows NT!"),
			szAppName, MB_ICONERROR);
		return 0;
	}
	
	cxScreen = GetSystemMetrics(SM_CXSCREEN);
	cyScreen = GetSystemMetrics(SM_CYSCREEN);
	
	hwnd = CreateWindow(szAppName,
						TEXT("LoveWindow"),
						WS_POPUPWINDOW,//弹出式窗口(无边框和标题栏)
						cxScreen * 3 / 14,//居中显示
						cyScreen / 8,
						cxScreen * 4 / 7,
						cyScreen * 3 / 4,
						NULL,
						NULL,
						hInstance,
						NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	return msg.wParam;
}

//显示一个字
int ShowWord(HDC hdc)
{
	TCHAR c;

	if(fscanf(fp, "%c", &c) != EOF)
	{
		if(c == '\n')
		{
			row++;
			col = 0;

			/*
			如果遇到'\n',说明需要换行,换行后,下一行首字
			要和上一行首字对齐,因此要将列标col置零*/
		}

		else
		{
			word[0] = c;
			fscanf(fp, "%c", &c);
			word[1] = c;
			col++;

			/*
			这里修改了字体的大小，原理上和上次的相同
			*/

			TextOut(hdc, col * (23 * cxChar / 12 + 3) + 95, row * cyChar * 39 / 40 + 27, word, 2);
		}

		return 0;
	}

	return EOF;
}

//诗歌子窗口回调函数(动态显示诗歌、播放音乐(音乐可自行选择))
LRESULT CALLBACK PoemChild(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static	HBITMAP	hBmp;
	static	HFONT	hFont;
	static	int		cxBitmap, cyBitmap;
	static	HWND	hwndMci;
	BITMAP			bmp;
	LOGFONT			lf;
	HDC				hdc, hdcMem;
	PAINTSTRUCT		ps;
	TEXTMETRIC		tm;

	switch(message)
	{
	case WM_CREATE:
		//开始加载并播放音乐(使用MCI控件)
		hwndMci = MCIWndCreate(hwnd, ((LPCREATESTRUCT)lParam)->hInstance,
							MCIWNDF_SHOWNAME,TEXT("谁.mp3"));
		
		ShowWindow(hwndMci, SW_HIDE);
		MCIWndPlay(hwndMci);

		//加载位图
		hBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BMPPOEM));
		GetObject(hBmp, sizeof(BITMAP), &bmp);

		cxBitmap = bmp.bmWidth;
		cyBitmap = bmp.bmHeight;

		/**********************获取系统文本参数*************************/
		hdc = GetDC(hwnd);

		GetTextMetrics(hdc, &tm);
		cxChar = tm.tmAveCharWidth;
		cyChar = tm.tmHeight;

		ReleaseDC(hwnd, hdc);

		//设定计时器
		SetTimer(hwnd, ID_TIMER_POEM, 400, NULL);

		//创建字体
		ZeroMemory(&lf, sizeof(LOGFONT));

		lf.lfHeight		= -15;
		lf.lfUnderline	= 1;

		hFont = CreateFontIndirect(&lf);

		//打开诗歌文件
		if((fp = fopen("res\\Poem.txt", "r")) == NULL)
		{
			MessageBox(hwnd, TEXT("不好意思，我找不到优美的诗歌了o(╯□╰)o"), TEXT("提示"), MB_OK);
			exit(1);
		}
		row = col = 0;
		return 0 ;

	//绘制背景位图
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		hdcMem = CreateCompatibleDC(hdc);
		SelectObject(hdcMem, hBmp);

		BitBlt(hdc, 0, 0, cxBitmap, cyBitmap, hdcMem, 0, 0, SRCCOPY);

		DeleteDC(hdcMem);
		EndPaint(hwnd, &ps);
		return 0;

	//通过响应鼠标消息来控制MCI播放器的显示和隐藏
	case WM_LBUTTONDOWN:
		if(IsWindowVisible(hwndMci))
		{
			ShowWindow(hwndMci, SW_HIDE);
		}

		else
		{
			ShowWindow(hwndMci, SW_NORMAL);
		}
		return 0;

	//通过定时器来驱动诗歌的显示
	case WM_TIMER:
		hdc = GetDC(hwnd);

		//设定文本颜色
		SetTextColor(hdc, RGB(rand() % 255,
			rand() % 205, rand() % 255));
		SetBkMode(hdc,TRANSPARENT);//设定文本的背景透明

		SelectObject(hdc, hFont);

		//如果文件读取完了 , 计时器也应该关闭 , 免得浪费资源
		if(ShowWord(hdc) == EOF)
		{
			KillTimer(hwnd, ID_TIMER_POEM);
		}
		
		ReleaseDC(hwnd, hdc);
		return 0;

	case WM_DESTROY:
		MCIWndDestroy(hwndMci);
		DeleteObject(hFont);
		DeleteObject(hBmp);
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}

//动画位图子窗口回调函数
LRESULT CALLBACK LoveChild(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HBITMAP	hBmp[NUM];
	static POINT	bmpPos[NUM];
	static int		moveIndex[NUM] = {5, 5, 5};
	static WORD		bmpID[] = {IDB_BMPI, IDB_BMPLOVE, IDB_BMPYOU};
	static int		cxClient, cyClient, cxBitmap, cyBitmap;
	BITMAP			bmp;
	HDC				hdc, hdcMem;
	PAINTSTRUCT		ps;
	int				i;

	switch(message)
	{
	case WM_CREATE:
		//设置计时器
		SetTimer(hwnd, ID_TIMER_LOVE, 100, NULL);

		//加载位图
		for(i=0; i<NUM; i++)
		{
			hBmp[i] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, 
								MAKEINTRESOURCE(bmpID[i]));
			bmpPos[i].x = bmpPos[i].y = -10;
		}

		GetObject(hBmp[0], sizeof(BITMAP), &bmp);

		cxBitmap = bmp.bmWidth;
		cyBitmap = bmp.bmHeight;
		return 0;

	case WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);

		//修改位图位置
		for(i=0; i<NUM; i++)
		{	
			bmpPos[i].x = cxClient * i / 3;
			if(bmpPos[i].x == -10)
			{
				bmpPos[i].y = rand() % (cyClient - cyBitmap);
			}
		}
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		hdcMem = CreateCompatibleDC(hdc);

		for(i=0; i<NUM; i++)
		{
			//判断位图的位置  并作相应的运动方向的改变
			if(bmpPos[i].y < 0)//上边界
			{
				moveIndex[i] = rand() % 10 + 5;
			}

			if(bmpPos[i].y >= (cyClient - cyBitmap))//下边界
			{
				moveIndex[i] = - (rand() % 10 + 5);
			}

			bmpPos[i].y += moveIndex[i];

			SelectObject(hdcMem, hBmp[i]);

			BitBlt(hdc, bmpPos[i].x, bmpPos[i].y, 
				cxBitmap, cyBitmap, hdcMem, 0, 0, SRCCOPY);
		}

		DeleteDC(hdcMem);
		EndPaint(hwnd, &ps);
		return 0;

	case WM_TIMER:
		InvalidateRect(hwnd, NULL, FALSE);//设置无效区域  但是不重绘背景(FALSE)
		return 0;

	case WM_DESTROY:
		KillTimer(hwnd, ID_TIMER_LOVE);
		
		for(i=0; i<NUM; i++)
		{
			DeleteObject(hBmp[i]);
		}
		
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

//动态变换位图子窗口回调函数
LRESULT CALLBACK BmpChild(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HBITMAP	hBmp[10];
	static WORD		bmpID[] = {IDB_BITMAP4, IDB_BITMAP5, IDB_BITMAP6, IDB_BITMAP7,
							   IDB_BITMAP8, IDB_BITMAP9, IDB_BITMAP10, IDB_BITMAP11,
							   IDB_BITMAP12, IDB_BITMAP13};
	static int		cxBitmap, cyBitmap, curBmpIndex;
	BITMAP			bmp;
	HDC				hdc, hdcMem;
	PAINTSTRUCT		ps;
	int				i;

	switch(message)
	{
	case WM_CREATE:
		//设置计时器
		SetTimer(hwnd, ID_TIMER_BMP, 5000, NULL);

		//加载位图
		for(i=0; i<10; i++)
		{
			hBmp[i] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, 
								MAKEINTRESOURCE(bmpID[i]));
		}

		GetObject(hBmp[0], sizeof(BITMAP), &bmp);

		cxBitmap = bmp.bmWidth;
		cyBitmap = bmp.bmHeight;
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		hdcMem = CreateCompatibleDC(hdc);

		SelectObject(hdcMem, hBmp[curBmpIndex]);

		BitBlt(hdc, 3, 8, cxBitmap, cyBitmap, hdcMem, 0, 0, SRCCOPY);

		curBmpIndex = (curBmpIndex + 1) % 10;

		DeleteDC(hdcMem);
		EndPaint(hwnd, &ps);
		return 0;

	case WM_TIMER:
		InvalidateRect(hwnd, NULL, TRUE);
		return 0;

	case WM_DESTROY:
		KillTimer(hwnd, ID_TIMER_BMP);

		for(i=0; i<10; i++)
		{
			DeleteObject(hBmp[i]);
		}

		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND		hwndChild[NUM];
	static TCHAR*	szChildClassName[] = {TEXT("PoemChild"), TEXT("LoveChild"), TEXT("BmpChild")};
	static WNDPROC	childProc[] = {PoemChild, LoveChild, BmpChild};
	HINSTANCE		hInstance;
	WNDCLASS		wndclass;
	int				i, cxClient, cyClient;
	
	switch(message)
	{
	case WM_CREATE:
		if(IDYES == MessageBox(hwnd, TEXT("准备好倾听我的心声了吗?"), TEXT("LoveWindow"), MB_YESNO))
		{
			Sleep(2000);
		}

		else
		{
			SendMessage(hwnd, WM_DESTROY, wParam, lParam);
		}

		//创建子窗口
		hInstance = ((LPCREATESTRUCT)lParam)->hInstance;

		wndclass.cbClsExtra		= 0;
		wndclass.cbWndExtra		= 0;
		wndclass.hbrBackground	= (HBRUSH)GetStockObject(WHITE_BRUSH);
		wndclass.hCursor		= LoadCursor(NULL, IDC_ARROW);
		wndclass.hIcon			= NULL;
		wndclass.hInstance		= hInstance;
		wndclass.lpszMenuName	= NULL;
		wndclass.style			= CS_HREDRAW | CS_VREDRAW;

		for(i=0; i<NUM; i++)
		{
			if(i == 2)
				wndclass.hbrBackground	= CreateSolidBrush(RGB(73, 229, 225));

			wndclass.lpfnWndProc	= childProc[i];
			wndclass.lpszClassName	= szChildClassName[i];

			RegisterClass(&wndclass);

			hwndChild[i] = CreateWindow(szChildClassName[i], NULL,
										WS_CHILD | WS_VISIBLE,
										0, 0, 0, 0,
										hwnd, NULL, hInstance,
										NULL);
		}
		return 0;

	case WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);

		MoveWindow(hwndChild[0], 0, 0, cxClient / 2, cyClient, TRUE);
		MoveWindow(hwndChild[1], cxClient / 2 + 3, 0, cxClient / 2, cyClient / 2, TRUE);
		MoveWindow(hwndChild[2], cxClient / 2 + 3, cyClient / 2 + 3, cxClient / 2 , cyClient / 2, TRUE);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}
