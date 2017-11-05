; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "list.h"

ClassCount=4
Class1=CListApp
Class2=CListDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_LIST_DIALOG
Class4=CDlg
Resource4=IDD_DIALOG1

[CLS:CListApp]
Type=0
HeaderFile=list.h
ImplementationFile=list.cpp
Filter=N

[CLS:CListDlg]
Type=0
HeaderFile=listDlg.h
ImplementationFile=listDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_LIST1

[CLS:CAboutDlg]
Type=0
HeaderFile=listDlg.h
ImplementationFile=listDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_LIST_DIALOG]
Type=1
Class=CListDlg
ControlCount=5
Control1=IDC_LIST1,listbox,1352728835
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_EDIT2,edit,1350631552
Control4=IDC_BUTTON1,button,1342242816
Control5=IDC_BUTTON2,button,1342242816

[DLG:IDD_DIALOG1]
Type=1
Class=CDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:CDlg]
Type=0
HeaderFile=Dlg.h
ImplementationFile=Dlg.cpp
BaseClass=CDialog
Filter=D

