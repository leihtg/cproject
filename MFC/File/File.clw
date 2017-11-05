; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFileDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "File.h"

ClassCount=5
Class1=CFileApp
Class2=CFileDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_FILE_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_DIALOG2
Resource4=IDD_ABOUTBOX
Class4=CDlg1
Class5=CDlg2
Resource5=IDD_DIALOG1

[CLS:CFileApp]
Type=0
HeaderFile=File.h
ImplementationFile=File.cpp
Filter=N

[CLS:CFileDlg]
Type=0
HeaderFile=FileDlg.h
ImplementationFile=FileDlg.cpp
Filter=D
LastObject=CFileDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=FileDlg.h
ImplementationFile=FileDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_FILE_DIALOG]
Type=1
Class=CFileDlg
ControlCount=1
Control1=IDC_TAB2,SysTabControl32,1342177280

[DLG:IDD_DIALOG1]
Type=1
Class=CDlg1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG2]
Type=1
Class=CDlg2
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

[CLS:CDlg1]
Type=0
HeaderFile=Dlg1.h
ImplementationFile=Dlg1.cpp
BaseClass=CDialog
Filter=D

[CLS:CDlg2]
Type=0
HeaderFile=Dlg2.h
ImplementationFile=Dlg2.cpp
BaseClass=CDialog
Filter=D

