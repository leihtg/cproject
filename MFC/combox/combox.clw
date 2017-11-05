; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CComboxDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "combox.h"

ClassCount=3
Class1=CComboxApp
Class2=CComboxDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_COMBOX_DIALOG

[CLS:CComboxApp]
Type=0
HeaderFile=combox.h
ImplementationFile=combox.cpp
Filter=N

[CLS:CComboxDlg]
Type=0
HeaderFile=comboxDlg.h
ImplementationFile=comboxDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_COMBO1

[CLS:CAboutDlg]
Type=0
HeaderFile=comboxDlg.h
ImplementationFile=comboxDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_COMBOX_DIALOG]
Type=1
Class=CComboxDlg
ControlCount=1
Control1=IDC_COMBO1,combobox,1344340226

