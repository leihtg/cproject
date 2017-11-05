; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CRadioDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "radio.h"

ClassCount=3
Class1=CRadioApp
Class2=CRadioDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_RADIO_DIALOG

[CLS:CRadioApp]
Type=0
HeaderFile=radio.h
ImplementationFile=radio.cpp
Filter=N

[CLS:CRadioDlg]
Type=0
HeaderFile=radioDlg.h
ImplementationFile=radioDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=radioDlg.h
ImplementationFile=radioDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_RADIO_DIALOG]
Type=1
Class=CRadioDlg
ControlCount=7
Control1=IDC_RADIO1,button,1342308361
Control2=IDC_RADIO2,button,1342177289
Control3=IDC_STATIC,button,1342308359
Control4=IDC_STATIC,button,1342308359
Control5=IDC_RADIO3,button,1342308361
Control6=IDC_RADIO4,button,1342177289
Control7=IDC_BUTTON1,button,1342242816

