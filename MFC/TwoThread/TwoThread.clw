; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTwoThreadView
LastTemplate=CWinThread
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TwoThread.h"
LastPage=0

ClassCount=7
Class1=CTwoThreadApp
Class2=CTwoThreadDoc
Class3=CTwoThreadView
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CUIDlg
Class7=CUIThread
Resource3=IDD_DIALOG1

[CLS:CTwoThreadApp]
Type=0
HeaderFile=TwoThread.h
ImplementationFile=TwoThread.cpp
Filter=N

[CLS:CTwoThreadDoc]
Type=0
HeaderFile=TwoThreadDoc.h
ImplementationFile=TwoThreadDoc.cpp
Filter=N

[CLS:CTwoThreadView]
Type=0
HeaderFile=TwoThreadView.h
ImplementationFile=TwoThreadView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=a


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=a




[CLS:CAboutDlg]
Type=0
HeaderFile=TwoThread.cpp
ImplementationFile=TwoThread.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
Command17=a
CommandCount=17

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_DIALOG1]
Type=1
Class=CUIDlg
ControlCount=3
Control1=IDC_PROGRESS1,msctls_progress32,1350565889
Control2=IDC_BUTTON1,button,1342242816
Control3=IDC_BUTTON2,button,1342242816

[CLS:CUIDlg]
Type=0
HeaderFile=UIDlg.h
ImplementationFile=UIDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CUIDlg
VirtualFilter=dWC

[CLS:CUIThread]
Type=0
HeaderFile=UIThread.h
ImplementationFile=UIThread.cpp
BaseClass=CWinThread
Filter=N

