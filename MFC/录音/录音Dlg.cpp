// 录音Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "录音.h"
#include "mmsystem.h"     // 音频相关函数所需头文件
#include "录音Dlg.h"
#pragma comment(lib,"winmm.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

int                 nIn=2;       // pBufferIn[2]中，当前播放缓冲区号
int                 nOut=2;      // pBufferOut[2]中，当前录音缓冲区号

static HWAVEIN      hWaveIn ;        // 录音设备句柄
static HWAVEOUT     hWaveOut ;       // 播放设备句柄
static PBYTE        pBufferIn[2];    // 用于接收和播放的两块缓冲区
static PBYTE        pBufferOut[2];   // 用于发送和录音的两块缓冲区

static PWAVEHDR     pWaveHdrIn[2];   // 用于录音的PWAVEHDR结构数组
static PWAVEHDR     pWaveHdrOut[2];  // 用于播放的PWAVEHDR结构数组
static WAVEFORMATEX waveform ;       // 用于打开音频设备的WAVEFORMATEX结构

#define INP_BUFFER_SIZE 4096   // 缓冲区大小
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
	
	// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA
	
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	
	// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
//{{AFX_MSG_MAP(CAboutDlg)
// No message handlers
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
	// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
//{{AFX_MSG_MAP(CMyDlg)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_BN_CLICKED(IDC_BUTTON1, OnLuyin)

	ON_MESSAGE(MM_WIM_OPEN,ON_MM_WIM_OPEN)
	ON_MESSAGE(MM_WIM_DATA,ON_MM_WIM_DATA)
	ON_MESSAGE(MM_WIM_CLOSE,ON_MM_WIM_CLOSE)
	ON_MESSAGE(MM_WOM_OPEN,ON_MM_WOM_OPEN)

ON_BN_CLICKED(IDC_BUTTON2, OnPlay)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// Add "About..." menu item to system menu.
	
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	InitAudioDevice();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
		
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
		
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


BOOL CMyDlg::InitAudioDevice()
{
	// 初始化waveform
	waveform.wFormatTag      = WAVE_FORMAT_PCM ;  // 采样方式,PCM(脉冲编码调制)
    waveform.nChannels       = 2 ;                // 双声道
    waveform.nSamplesPerSec  = 11025 ;            // 采样率11.025KHz
    waveform.nAvgBytesPerSec = 11025;             // 数据率11.025KB/s
    waveform.nBlockAlign     = 2 ;   // 最小块单元，wBitsPerSample×nChannels/8
    waveform.wBitsPerSample  = 8 ;                // 样本大小为8bit
    waveform.cbSize          = 0 ;                // 附加格式信息
    
	// 准备pWaveHdrIn和pWaveHdrOut
	for(int HdrNum=0;HdrNum<=1;HdrNum++)
	{
        // 为缓冲区分配内存
		pBufferIn[HdrNum]  = (PBYTE)malloc (INP_BUFFER_SIZE) ;   
        pBufferOut[HdrNum] = (PBYTE)malloc (INP_BUFFER_SIZE) ;
		if (!pBufferIn[HdrNum] || !pBufferOut[HdrNum])
		{
			if (pBufferIn[HdrNum])
				free (pBufferIn[HdrNum]) ;
			if (pBufferOut[HdrNum])
				free (pBufferIn[HdrNum]) ;
			AfxMessageBox(_T("内存分配失败！"),MB_ICONINFORMATION|MB_OK,NULL);
        }
		
		pWaveHdrIn[HdrNum] =new WAVEHDR;
        pWaveHdrOut[HdrNum]=new WAVEHDR;
		
		pWaveHdrOut[HdrNum]->lpData          = (char *)pBufferIn[HdrNum];
        pWaveHdrOut[HdrNum]->dwBufferLength  = INP_BUFFER_SIZE ;
        pWaveHdrOut[HdrNum]->dwBytesRecorded = 0 ;
        pWaveHdrOut[HdrNum]->dwUser          = 0 ;
        pWaveHdrOut[HdrNum]->dwFlags         = WHDR_BEGINLOOP | WHDR_ENDLOOP ;
        pWaveHdrOut[HdrNum]->dwLoops         = 1;
        pWaveHdrOut[HdrNum]->lpNext          = NULL ;
        pWaveHdrOut[HdrNum]->reserved        = 0 ;
		
		pWaveHdrIn[HdrNum]->lpData           = (char *)pBufferOut[HdrNum] ;
		pWaveHdrIn[HdrNum]->dwBufferLength   = INP_BUFFER_SIZE ;
		pWaveHdrIn[HdrNum]->dwBytesRecorded  = 0 ;
		pWaveHdrIn[HdrNum]->dwUser           = 0 ;
		pWaveHdrIn[HdrNum]->dwFlags          = WHDR_BEGINLOOP | WHDR_ENDLOOP ;
		pWaveHdrIn[HdrNum]->dwLoops          = 1 ;
		pWaveHdrIn[HdrNum]->lpNext           = NULL ;
		pWaveHdrIn[HdrNum]->reserved         = 0 ;	
		
	}
	// 打开播放波形音频设备
	MMRESULT result;
	result=waveOutOpen (&hWaveOut, WAVE_MAPPER, &waveform, 
		(DWORD) this->m_hWnd, 0, CALLBACK_WINDOW);
    // 打开录制波形音频设备
	if(result==MMSYSERR_NOERROR)
		result=waveInOpen (&hWaveIn, WAVE_MAPPER, &waveform, 
		(DWORD) this->m_hWnd, 0, CALLBACK_WINDOW);
	// 为播放和录音准备
    for(int Prepare=0;Prepare<=1;Prepare++)		
	{
		if(result==MMSYSERR_NOERROR)
			result=waveOutPrepareHeader(hWaveOut, pWaveHdrOut[Prepare], 
			sizeof (WAVEHDR)) ;
		if(result==MMSYSERR_NOERROR)
			result=waveInPrepareHeader(hWaveIn, pWaveHdrIn[Prepare], 
			sizeof (WAVEHDR)) ;	
	} 
	// 设置音量为最大
	if(result==MMSYSERR_NOERROR)
		result=waveOutSetVolume(hWaveOut,65535);
	// 成功返回TRUE
	if(result==MMSYSERR_NOERROR)
    {      
		return TRUE;	
	}
	else
	{
		AfxMessageBox(_T("打开波形音频设备时发生错误！"),MB_ICONINFORMATION | MB_OK,NULL);
		return FALSE;
	}
}

void CMyDlg::RecordBegin()
{
    // 准备录音缓冲区
	waveInAddBuffer(hWaveIn, pWaveHdrIn[nOut], sizeof (WAVEHDR)) ;
	// 开始录音
	waveInStart(hWaveIn) ; 	
	
}
bool flag=true;
void CMyDlg::OnLuyin() 
{
	if(flag){
		RecordBegin();
		flag=false;
		GetDlgItem(IDC_BUTTON1)->SetWindowText("停止");
	}else{
		waveInClose(hWaveIn);
		flag=true;
		GetDlgItem(IDC_BUTTON1)->SetWindowText("录音");
		
	}
}

void CMyDlg::OnPlay() 
{
	waveOutWrite(hWaveOut, pWaveHdrOut[nIn], sizeof (WAVEHDR));
	
}
//MM_WIM_CLOSE消息处理函数，关闭录音设备时产生
void CMyDlg::ON_MM_WIM_CLOSE()
{       
	 waveInUnprepareHeader (hWaveIn, pWaveHdrIn[0], sizeof (WAVEHDR)) ;
	 waveInUnprepareHeader (hWaveIn, pWaveHdrIn[1], sizeof (WAVEHDR)) ;
	 waveInClose (hWaveIn); 	 
	 hWaveIn=NULL; //clear it   
}
void CMyDlg::ON_MM_WIM_DATA()
{
	MessageBox("aaa");
}

void CMyDlg::ON_MM_WIM_OPEN()
{
	//MessageBox("open");
}

void CMyDlg::ON_MM_WOM_OPEN()
{
	//MessageBox("open");
}