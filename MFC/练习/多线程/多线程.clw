; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "多线程.h"

ClassCount=3
Class1=CMyApp
Class2=CMyDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MY_DIALOG

[CLS:CMyApp]
Type=0
HeaderFile=多线程.h
ImplementationFile=多线程.cpp
Filter=N

[CLS:CMyDlg]
Type=0
HeaderFile=多线程Dlg.h
ImplementationFile=多线程Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_EDIT1

[CLS:CAboutDlg]
Type=0
HeaderFile=多线程Dlg.h
ImplementationFile=多线程Dlg.cpp
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
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT1,edit,1350635648
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_PROGRESS1,msctls_progress32,1350565889

