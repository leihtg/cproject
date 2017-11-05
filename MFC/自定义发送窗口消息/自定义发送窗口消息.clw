; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyDlg
LastTemplate=CListBox
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "自定义发送窗口消息.h"

ClassCount=4
Class1=CMyApp
Class2=CMyDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CMessageListBox
Resource3=IDD_MY_DIALOG

[CLS:CMyApp]
Type=0
HeaderFile=自定义发送窗口消息.h
ImplementationFile=自定义发送窗口消息.cpp
Filter=N

[CLS:CMyDlg]
Type=0
HeaderFile=自定义发送窗口消息Dlg.h
ImplementationFile=自定义发送窗口消息Dlg.cpp
Filter=D
LastObject=CMyDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=自定义发送窗口消息Dlg.h
ImplementationFile=自定义发送窗口消息Dlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MY_DIALOG]
Type=1
Class=CMyDlg
ControlCount=1
Control1=list,listbox,1352728835

[CLS:CMessageListBox]
Type=0
HeaderFile=MessageListBox.h
ImplementationFile=MessageListBox.cpp
BaseClass=CListBox
Filter=W
VirtualFilter=bWC
LastObject=CMessageListBox

