; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFontDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Font.h"

ClassCount=3
Class1=CFontApp
Class2=CFontDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_FONT_DIALOG

[CLS:CFontApp]
Type=0
HeaderFile=Font.h
ImplementationFile=Font.cpp
Filter=N

[CLS:CFontDlg]
Type=0
HeaderFile=FontDlg.h
ImplementationFile=FontDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_font

[CLS:CAboutDlg]
Type=0
HeaderFile=FontDlg.h
ImplementationFile=FontDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_FONT_DIALOG]
Type=1
Class=CFontDlg
ControlCount=2
Control1=IDC_text,edit,1353781380
Control2=IDC_font,button,1342242816

