; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CColorDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "color.h"

ClassCount=3
Class1=CColorApp
Class2=CColorDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_COLOR_DIALOG

[CLS:CColorApp]
Type=0
HeaderFile=color.h
ImplementationFile=color.cpp
Filter=N

[CLS:CColorDlg]
Type=0
HeaderFile=colorDlg.h
ImplementationFile=colorDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CColorDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=colorDlg.h
ImplementationFile=colorDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_COLOR_DIALOG]
Type=1
Class=CColorDlg
ControlCount=2
Control1=IDC_color,static,1342308352
Control2=IDC_BUTTON1,button,1342242816

