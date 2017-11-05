; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLoginDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "dialog1.h"

ClassCount=4
Class1=CDialog1App
Class2=CDialog1Dlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DIALOG1_DIALOG
Class4=CLoginDlg
Resource4=IDD_DIALOG1

[CLS:CDialog1App]
Type=0
HeaderFile=dialog1.h
ImplementationFile=dialog1.cpp
Filter=N

[CLS:CDialog1Dlg]
Type=0
HeaderFile=dialog1Dlg.h
ImplementationFile=dialog1Dlg.cpp
Filter=D
LastObject=CDialog1Dlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=dialog1Dlg.h
ImplementationFile=dialog1Dlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DIALOG1_DIALOG]
Type=1
Class=CDialog1Dlg
ControlCount=2
Control1=IDC_BUTTON1,button,1342242816
Control2=IDC_BUTTON2,button,1342242816

[DLG:IDD_DIALOG1]
Type=1
Class=CLoginDlg
ControlCount=6
Control1=IDC_STATIC,static,1342308354
Control2=IDC_STATIC,static,1342308354
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_EDIT2,edit,1350631552
Control5=IDC_BUTTON1,button,1342242816
Control6=IDC_BUTTON2,button,1342242816

[CLS:CLoginDlg]
Type=0
HeaderFile=LoginDlg.h
ImplementationFile=LoginDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CLoginDlg
VirtualFilter=dWC

