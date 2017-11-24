; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CShowThread
LastTemplate=CWinThread
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Chat.h"

ClassCount=5
Class1=CChatApp
Class2=CChatDlg
Class3=CAboutDlg

ResourceCount=6
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDR_MENU1
Resource4=IDD_DIALOG1
Resource5=IDD_CHAT_DIALOG
Class4=CProcessDlg
Class5=CShowThread
Resource6=IDR_ACCELERATOR1

[CLS:CChatApp]
Type=0
HeaderFile=Chat.h
ImplementationFile=Chat.cpp
Filter=N

[CLS:CChatDlg]
Type=0
HeaderFile=ChatDlg.h
ImplementationFile=ChatDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CChatDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=ChatDlg.h
ImplementationFile=ChatDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CHAT_DIALOG]
Type=1
Class=CChatDlg
ControlCount=6
Control1=IDC_STATIC,button,1342177287
Control2=IDC_EDIT_RECV,edit,1352730820
Control3=IDC_STATIC,button,1342177287
Control4=IDC_IPADDRESS1,SysIPAddress32,1342242816
Control5=IDC_EDIT_SEND,edit,1350631552
Control6=IDC_BTN_SEND,button,1342242817

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=id_sendfile
CommandCount=1

[ACL:IDR_ACCELERATOR1]
Type=1
Class=?
Command1=id_sendfile
CommandCount=1

[DLG:IDD_DIALOG1]
Type=1
Class=CProcessDlg
ControlCount=1
Control1=IDC_PROGRESS1,msctls_progress32,1342177281

[CLS:CProcessDlg]
Type=0
HeaderFile=ProcessDlg.h
ImplementationFile=ProcessDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CProcessDlg
VirtualFilter=dWC

[CLS:CShowThread]
Type=0
HeaderFile=ShowThread.h
ImplementationFile=ShowThread.cpp
BaseClass=CWinThread
Filter=N
LastObject=CShowThread

