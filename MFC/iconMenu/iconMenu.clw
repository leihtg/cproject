; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMenuIcon
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "iconMenu.h"

ClassCount=4
Class1=CIconMenuApp
Class2=CIconMenuDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CMenuIcon
Resource3=IDD_ICONMENU_DIALOG

[CLS:CIconMenuApp]
Type=0
HeaderFile=iconMenu.h
ImplementationFile=iconMenu.cpp
Filter=N

[CLS:CIconMenuDlg]
Type=0
HeaderFile=iconMenuDlg.h
ImplementationFile=iconMenuDlg.cpp
Filter=D
LastObject=CIconMenuDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=iconMenuDlg.h
ImplementationFile=iconMenuDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_ICONMENU_DIALOG]
Type=1
Class=CIconMenuDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

[CLS:CMenuIcon]
Type=0
HeaderFile=MenuIcon.h
ImplementationFile=MenuIcon.cpp
BaseClass=CDialog
Filter=D
LastObject=CMenuIcon

