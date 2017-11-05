#include "StdAfx.h"
#include "RegularDll.h"
#include "ScoreDlg.h"
extern "C" void _declspec(dllexport)ShowDlg(double score1,double score2){
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CScoreDlg dlg;
	dlg.m_score1=score1;
	dlg.m_scroe2=score2;
	dlg.DoModal();
}