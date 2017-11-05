; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CChecklistDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "checklist.h"

ClassCount=3
Class1=CChecklistApp
Class2=CChecklistDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_CHECKLIST_DIALOG

[CLS:CChecklistApp]
Type=0
HeaderFile=checklist.h
ImplementationFile=checklist.cpp
Filter=N

[CLS:CChecklistDlg]
Type=0
HeaderFile=checklistDlg.h
ImplementationFile=checklistDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_LIST1

[CLS:CAboutDlg]
Type=0
HeaderFile=checklistDlg.h
ImplementationFile=checklistDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CHECKLIST_DIALOG]
Type=1
Class=CChecklistDlg
ControlCount=2
Control1=IDC_LIST1,listbox,1352729363
Control2=IDC_BUTTON1,button,1342242816

