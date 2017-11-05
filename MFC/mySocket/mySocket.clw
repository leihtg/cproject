; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CServer
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "mySocket.h"

ClassCount=5
Class1=CMySocketApp
Class2=CMySocketDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_MYSOCKET_DIALOG
Resource2=IDR_MAINFRAME
Resource3=idd_client
Resource4=IDD_ABOUTBOX
Class4=CClient
Class5=CServer
Resource5=idd_server

[CLS:CMySocketApp]
Type=0
HeaderFile=mySocket.h
ImplementationFile=mySocket.cpp
Filter=N

[CLS:CMySocketDlg]
Type=0
HeaderFile=mySocketDlg.h
ImplementationFile=mySocketDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CMySocketDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=mySocketDlg.h
ImplementationFile=mySocketDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MYSOCKET_DIALOG]
Type=1
Class=CMySocketDlg
ControlCount=1
Control1=IDC_TAB1,SysTabControl32,1342177280

[DLG:idd_client]
Type=1
Class=CClient
ControlCount=9
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308354
Control3=IDC_EDIT2,edit,1350631552
Control4=IDC_open,button,1342242816
Control5=IDC_close,button,1342242816
Control6=IDC_EDIT3,edit,1350631552
Control7=IDC_send,button,1342242816
Control8=IDC_LIST1,listbox,1353777411
Control9=IDC_IPADDRESS1,SysIPAddress32,1342242816

[DLG:idd_server]
Type=1
Class=CServer
ControlCount=7
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_listen,button,1342242816
Control4=IDC_close,button,1342242816
Control5=IDC_EDIT2,edit,1350631552
Control6=IDC_send,button,1342242816
Control7=IDC_LIST1,listbox,1352728835

[CLS:CClient]
Type=0
HeaderFile=Client.h
ImplementationFile=Client.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT3
VirtualFilter=dWC

[CLS:CServer]
Type=0
HeaderFile=Server.h
ImplementationFile=Server.cpp
BaseClass=CDialog
Filter=D
LastObject=CServer
VirtualFilter=dWC

