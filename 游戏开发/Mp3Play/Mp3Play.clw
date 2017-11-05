; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMp3PlayDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Mp3Play.h"

ClassCount=3
Class1=CMp3PlayApp
Class2=CMp3PlayDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MP3PLAY_DIALOG

[CLS:CMp3PlayApp]
Type=0
HeaderFile=Mp3Play.h
ImplementationFile=Mp3Play.cpp
Filter=N

[CLS:CMp3PlayDlg]
Type=0
HeaderFile=Mp3PlayDlg.h
ImplementationFile=Mp3PlayDlg.cpp
Filter=D
LastObject=CMp3PlayDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=Mp3PlayDlg.h
ImplementationFile=Mp3PlayDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MP3PLAY_DIALOG]
Type=1
Class=CMp3PlayDlg
ControlCount=5
Control1=IDC_OPEN_BTN,button,1342242816
Control2=IDC_PLAY_BTN,button,1342242816
Control3=IDC_PAUSE_BTN,button,1342242816
Control4=IDC_STOP_BTN,button,1342242816
Control5=IDC_PROCESS,msctls_trackbar32,1342242840

