; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFileDialogDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "fileDialog.h"

ClassCount=3
Class1=CFileDialogApp
Class2=CFileDialogDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_FILEDIALOG_DIALOG

[CLS:CFileDialogApp]
Type=0
HeaderFile=fileDialog.h
ImplementationFile=fileDialog.cpp
Filter=N

[CLS:CFileDialogDlg]
Type=0
HeaderFile=fileDialogDlg.h
ImplementationFile=fileDialogDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_OPENPATH

[CLS:CAboutDlg]
Type=0
HeaderFile=fileDialogDlg.h
ImplementationFile=fileDialogDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_FILEDIALOG_DIALOG]
Type=1
Class=CFileDialogDlg
ControlCount=5
Control1=IDC_OPEN,button,1342242816
Control2=IDC_SAVE,button,1342242816
Control3=IDC_OPENPATH,static,1342308352
Control4=IDC_SAVEPATH,static,1342308352
Control5=IDC_FILEEDIT,edit,1350631556

