; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAddrDlg
LastTemplate=CAsyncSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Ch14Demo3Client.h"

ClassCount=5
Class1=CCh14Demo3ClientApp
Class2=CCh14Demo3ClientDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_DIALOG1
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CAddrDlg
Class5=CClientSocket
Resource4=IDD_CH14DEMO3CLIENT_DIALOG
Resource5=IDD_DIALOG2

[CLS:CCh14Demo3ClientApp]
Type=0
HeaderFile=Ch14Demo3Client.h
ImplementationFile=Ch14Demo3Client.cpp
Filter=N

[CLS:CCh14Demo3ClientDlg]
Type=0
HeaderFile=Ch14Demo3ClientDlg.h
ImplementationFile=Ch14Demo3ClientDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CCh14Demo3ClientDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=Ch14Demo3ClientDlg.h
ImplementationFile=Ch14Demo3ClientDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CH14DEMO3CLIENT_DIALOG]
Type=1
Class=CCh14Demo3ClientDlg
ControlCount=7
Control1=IDC_STATIC,static,1342308352
Control2=IDC_LIST1,listbox,1352728841
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350635652
Control5=IDC_BUTTON1,button,1342242816
Control6=IDC_BUTTON2,button,1342242816
Control7=IDC_BUTTON3,button,1342242816

[DLG:IDD_DIALOG1]
Type=1
Class=CAddrDlg
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_BUTTON2,button,1342242816

[CLS:CAddrDlg]
Type=0
HeaderFile=AddrDlg.h
ImplementationFile=AddrDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CAddrDlg

[CLS:CClientSocket]
Type=0
HeaderFile=ClientSocket.h
ImplementationFile=ClientSocket.cpp
BaseClass=CAsyncSocket
Filter=N
LastObject=CClientSocket
VirtualFilter=q

[DLG:IDD_DIALOG2]
Type=1
Class=?
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

