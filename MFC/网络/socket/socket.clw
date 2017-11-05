; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSocketDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "socket.h"

ClassCount=3
Class1=CSocketApp
Class2=CSocketDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SOCKET_DIALOG

[CLS:CSocketApp]
Type=0
HeaderFile=socket.h
ImplementationFile=socket.cpp
Filter=N

[CLS:CSocketDlg]
Type=0
HeaderFile=socketDlg.h
ImplementationFile=socketDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CSocketDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=socketDlg.h
ImplementationFile=socketDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SOCKET_DIALOG]
Type=1
Class=CSocketDlg
ControlCount=2
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_BUTTON1,button,1342242816

