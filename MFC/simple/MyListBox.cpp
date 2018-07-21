// MyListBox.cpp : 实现文件
//

#include "stdafx.h"
#include "simple.h"
#include "MyListBox.h"


// CMyListBox

IMPLEMENT_DYNAMIC(CMyListBox, CListBox)

CMyListBox::CMyListBox() : CListBox()
{

}

CMyListBox::~CMyListBox()
{
}

BEGIN_MESSAGE_MAP(CMyListBox, CListBox)
	ON_MESSAGE(WM_RBUTTONDOWN, &CMyListBox::OnRbuttondown)
	ON_WM_LBUTTONDBLCLK()
	//	ON_WM_DRAWITEM()
END_MESSAGE_MAP()



// CMyListBox 消息处理程序


afx_msg LRESULT CMyListBox::OnRbuttondown(WPARAM wParam, LPARAM lParam)
{
	POINT pt;
	GetCursorPos(&pt);
	int nCount = GetCount();
	ScreenToClient(&pt);
	for (int i = 0; i < nCount; i++){
		CRect rc;
		GetItemRect(i, &rc);
		if (rc.PtInRect(pt)){
			SetCurSel(i);
			CMenu temp, *ptr;
			temp.LoadMenu(IDR_RIGHTMENU);
			ptr = temp.GetSubMenu(0);
			ClientToScreen(&pt);
			ptr->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, pt.x, pt.y, GetParent());
			break;
		}
	}
	return 0;
}


void CMyListBox::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	//CListBox::OnLButtonDblClk(nFlags, point);
	MessageBox(_T("hee"));
}



void CMyListBox::DrawItem(LPDRAWITEMSTRUCT lpDIS)
{

	// TODO:  添加您的代码以绘制指定项
	CDC dc;
	dc.Attach(lpDIS->hDC);
	CRect rectFull = lpDIS->rcItem;

	CBrush brush(RGB(255, 255, 255));
	dc.FillRect(rectFull, &brush);
	CString str;
	GetText(lpDIS->itemID, str);
	if (ODA_SELECT == lpDIS->itemAction){
		CBrush b(RGB(0, 0, 0));
		ScreenToClient(rectFull);
		dc.FillRect(rectFull, &b);

		dc.SetBkMode(TRANSPARENT);
		CPen pen(PS_SOLID, 1, RGB(255, 255, 255));
		dc.SelectObject(pen);
		//ClientToScreen(rectFull);
	}
	dc.DrawText(str, rectFull, DT_LEFT);
	dc.Detach();
}
