; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMsgBoxDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MsgBox.h"

ClassCount=3
Class1=CMsgBoxApp
Class2=CMsgBoxDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MSGBOX_DIALOG

[CLS:CMsgBoxApp]
Type=0
HeaderFile=MsgBox.h
ImplementationFile=MsgBox.cpp
Filter=N

[CLS:CMsgBoxDlg]
Type=0
HeaderFile=MsgBoxDlg.h
ImplementationFile=MsgBoxDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_EDIT1

[CLS:CAboutDlg]
Type=0
HeaderFile=MsgBoxDlg.h
ImplementationFile=MsgBoxDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MSGBOX_DIALOG]
Type=1
Class=CMsgBoxDlg
ControlCount=5
Control1=IDOK,button,1342242816
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_BUTTON2,button,1342242816
Control5=IDC_BUTTON3,button,1342242816

