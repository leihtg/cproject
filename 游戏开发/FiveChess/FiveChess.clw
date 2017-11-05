; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CsetupDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "FiveChess.h"

ClassCount=4
Class1=CFiveChessApp
Class2=CFiveChessDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_FIVECHESS_DIALOG
Resource4=IDD_DIALOG1
Class4=CsetupDlg
Resource5=IDR_MAIN_MENU

[CLS:CFiveChessApp]
Type=0
HeaderFile=FiveChess.h
ImplementationFile=FiveChess.cpp
Filter=N

[CLS:CFiveChessDlg]
Type=0
HeaderFile=FiveChessDlg.h
ImplementationFile=FiveChessDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CFiveChessDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=FiveChessDlg.h
ImplementationFile=FiveChessDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_FIVECHESS_DIALOG]
Type=1
Class=CFiveChessDlg
ControlCount=0

[MNU:IDR_MAIN_MENU]
Type=1
Class=?
Command1=ID_NEW_GAME_MENU
Command2=ID_DRAW_GAME_MENU
Command3=ID_EXIT_GAME_MENU
CommandCount=3

[DLG:IDD_DIALOG1]
Type=1
Class=CsetupDlg
ControlCount=9
Control1=IDC_STATIC,button,1342177287
Control2=IDC_HOST_OPTION,button,1342177289
Control3=IDC_CLIENT_OPTION,button,1342177289
Control4=IDC_IP_ADDRESS_EDIT,SysIPAddress32,1342242816
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_NET_PORT_EDIT,edit,1350631552
Control8=IDOK,button,1342242816
Control9=IDCANCEL,button,1342242816

[CLS:CsetupDlg]
Type=0
HeaderFile=setupDlg.h
ImplementationFile=setupDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_CLIENT_OPTION
VirtualFilter=dWC

