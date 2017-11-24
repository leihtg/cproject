; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPlaySoundDemoDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "PlaySoundDemo.h"

ClassCount=4
Class1=CPlaySoundDemoApp
Class2=CPlaySoundDemoDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_PLAYSOUNDDEMO_DIALOG

[CLS:CPlaySoundDemoApp]
Type=0
HeaderFile=PlaySoundDemo.h
ImplementationFile=PlaySoundDemo.cpp
Filter=N

[CLS:CPlaySoundDemoDlg]
Type=0
HeaderFile=PlaySoundDemoDlg.h
ImplementationFile=PlaySoundDemoDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=PlaySoundDemoDlg.h
ImplementationFile=PlaySoundDemoDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_PLAYSOUNDDEMO_DIALOG]
Type=1
Class=CPlaySoundDemoDlg
ControlCount=2
Control1=IDC_PLAY_SOUND,button,1342242816
Control2=IDC_PLAY_MUSIC,button,1342242816

