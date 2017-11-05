; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTimeCtrl
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "time.h"
CDK=Y

ClassCount=2
Class1=CTimeCtrl
Class2=CTimePropPage

ResourceCount=2
Resource1=IDD_ABOUTBOX_TIME
LastPage=0
Resource2=IDD_PROPPAGE_TIME

[CLS:CTimeCtrl]
Type=0
HeaderFile=TimeCtl.h
ImplementationFile=TimeCtl.cpp
Filter=W
BaseClass=COleControl
VirtualFilter=wWC
LastObject=CTimeCtrl

[CLS:CTimePropPage]
Type=0
HeaderFile=TimePpg.h
ImplementationFile=TimePpg.cpp
Filter=D
BaseClass=COlePropertyPage
VirtualFilter=idWC
LastObject=IDC_EDIT_INTERVAL

[DLG:IDD_ABOUTBOX_TIME]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_PROPPAGE_TIME]
Type=1
Class=CTimePropPage
ControlCount=3
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_INTERVAL,edit,1350631552
Control3=IDC_EDIT1,edit,1350631552

