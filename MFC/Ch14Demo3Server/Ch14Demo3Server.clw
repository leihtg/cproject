; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CListenSocket
LastTemplate=CAsyncSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Ch14Demo3Server.h"

ClassCount=5
Class1=CCh14Demo3ServerApp
Class2=CCh14Demo3ServerDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CNewSocket
Class5=CListenSocket
Resource3=IDD_CH14DEMO3SERVER_DIALOG

[CLS:CCh14Demo3ServerApp]
Type=0
HeaderFile=Ch14Demo3Server.h
ImplementationFile=Ch14Demo3Server.cpp
Filter=N

[CLS:CCh14Demo3ServerDlg]
Type=0
HeaderFile=Ch14Demo3ServerDlg.h
ImplementationFile=Ch14Demo3ServerDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CCh14Demo3ServerDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=Ch14Demo3ServerDlg.h
ImplementationFile=Ch14Demo3ServerDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CH14DEMO3SERVER_DIALOG]
Type=1
Class=CCh14Demo3ServerDlg
ControlCount=1
Control1=IDC_BUTTON1,button,1342242816

[CLS:CNewSocket]
Type=0
HeaderFile=NewSocket.h
ImplementationFile=NewSocket.cpp
BaseClass=CAsyncSocket
Filter=N
VirtualFilter=q
LastObject=CNewSocket

[CLS:CListenSocket]
Type=0
HeaderFile=ListenSocket.h
ImplementationFile=ListenSocket.cpp
BaseClass=CAsyncSocket
Filter=N
VirtualFilter=q
LastObject=CListenSocket

