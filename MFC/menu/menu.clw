; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMenuDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "menu.h"

ClassCount=3
Class1=CMenuApp
Class2=CMenuDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_MENU_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Resource4=IDR_MENU1

[CLS:CMenuApp]
Type=0
HeaderFile=menu.h
ImplementationFile=menu.cpp
Filter=N

[CLS:CMenuDlg]
Type=0
HeaderFile=menuDlg.h
ImplementationFile=menuDlg.cpp
Filter=D
LastObject=ID_A2
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=menuDlg.h
ImplementationFile=menuDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MENU_DIALOG]
Type=1
Class=CMenuDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_A11
Command2=ID_A2
Command3=ID_A3
Command4=ID_B1
CommandCount=4

