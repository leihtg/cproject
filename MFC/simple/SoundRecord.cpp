#include "stdafx.h"
#include "SoundRecord.h"


CSoundRecord::CSoundRecord(HWND hwnd) :hwnd(hwnd)
{
	//采样方式
	waveForm.wFormatTag = WAVE_FORMAT_PCM;
	//双声道
	waveForm.nChannels = 2;
	//采样率 11.025 KHZ
	waveForm.nSamplesPerSec = 11025;
	//最小块单元, wBitsPerSamle x nChannels/8
	waveForm.nBlockAlign = 2;
	//数据率 11.025 KB/s
	waveForm.nAvgBytesPerSec = 11025;// waveForm.nSamplesPerSec * waveForm.nBlockAlign;
	//样本大小为8bit
	waveForm.wBitsPerSample = 8;
	//附加格式信息
	waveForm.cbSize = 0;

	//准备pWaveHdrIn 和 pWaveHdrOut
	for (int hdrNum = 0; hdrNum < 2; hdrNum++)
	{
		//为缓冲区分配内存
		pBufferIn[hdrNum] = (PBYTE)malloc(INP_BUFFER_SIZE);
		pBufferOut[hdrNum] = (PBYTE)malloc(INP_BUFFER_SIZE);
		if (!pBufferIn[hdrNum] || !pBufferOut[hdrNum])
		{
			if (pBufferIn[hdrNum])
				free(pBufferIn[hdrNum]);
			if (pBufferOut[hdrNum])
				free(pBufferOut[hdrNum]);
			AfxMessageBox(_T("内存分配失败"), MB_ICONINFORMATION | MB_OK, NULL);
		}
		pWaveHdrIn[hdrNum] = new WAVEHDR;
		pWaveHdrOut[hdrNum] = new WAVEHDR;

		pWaveHdrOut[hdrNum]->lpData = (char*)pBufferIn[hdrNum];
		pWaveHdrOut[hdrNum]->dwBufferLength = INP_BUFFER_SIZE;
		pWaveHdrOut[hdrNum]->dwBytesRecorded = 0;
		pWaveHdrOut[hdrNum]->dwUser = 0;
		pWaveHdrOut[hdrNum]->dwFlags = WHDR_BEGINLOOP | WHDR_ENDLOOP;
		pWaveHdrOut[hdrNum]->dwLoops = 1;
		pWaveHdrOut[hdrNum]->lpNext = NULL;
		pWaveHdrOut[hdrNum]->reserved = 0;

		pWaveHdrIn[hdrNum]->lpData = (char*)pBufferOut[hdrNum];
		pWaveHdrIn[hdrNum]->dwBufferLength = INP_BUFFER_SIZE;
		pWaveHdrIn[hdrNum]->dwBytesRecorded = 0;
		pWaveHdrIn[hdrNum]->dwUser = 0;
		pWaveHdrIn[hdrNum]->dwFlags = WHDR_BEGINLOOP | WHDR_ENDLOOP;
		pWaveHdrIn[hdrNum]->dwLoops = 1;
		pWaveHdrIn[hdrNum]->lpNext = NULL;
		pWaveHdrIn[hdrNum]->reserved = 0;

	}

	
	//打开播放波形设备
	MMRESULT result;
	UINT_PTR in=IfWaveIn();
	
	result = waveInOpen(&hWaveIn, in, &waveForm, (DWORD)hwnd, 0, CALLBACK_WINDOW);
	
	if (result == MMSYSERR_NOERROR)
	{
		UINT_PTR out = IfWaveOut();
		result = waveOutOpen(&hWaveOut, out, &waveForm, (DWORD)hwnd, 0, CALLBACK_WINDOW);
	}
	//为播放和录音准备
	for (int prepare = 0; prepare <= 1; prepare++)
	{
		if (result == MMSYSERR_NOERROR)
			result = waveOutPrepareHeader(hWaveOut, pWaveHdrOut[prepare], sizeof(WAVEHDR));
		if (result == MMSYSERR_NOERROR)
			result = waveInPrepareHeader(hWaveIn, pWaveHdrIn[prepare], sizeof(WAVEHDR));
	}
	//设置音量为最大
	if (result == MMSYSERR_NOERROR)
	{
		result = waveOutSetVolume(hWaveOut, 65535);
	}
	if (result != MMSYSERR_NOERROR)
	{
		CString msg;
		msg.Format(_T("打开波形设备时出错,错误码[%d]"), result);
		AfxMessageBox(msg, MB_ICONINFORMATION | MB_OK, NULL);
	}
}


CSoundRecord::~CSoundRecord()
{
}

void CSoundRecord::beginRecord(){
	//准备录音缓冲区
	waveInAddBuffer(hWaveIn, pWaveHdrIn[0], sizeof(WAVEHDR));
	waveInReset(hWaveIn);
	//开始录音
	waveInStart(hWaveIn);
}

void CSoundRecord::soundPlay()
{
	waveOutWrite(hWaveOut, pWaveHdrIn[0], sizeof(WAVEHDR));
}


UINT_PTR CSoundRecord::IfWaveIn()
{
	MMRESULT mmresult = 0;
	UINT_PTR   m_iWaveInID=-1;
	mmresult = waveInGetNumDevs();
	if (mmresult == 0) return false;

	WAVEINCAPS waveincaps = { 0 };
	unsigned int i = 0;
	unsigned int num = mmresult;
	for (; i<num; i++)
	{
		mmresult = waveInGetDevCaps(i, &waveincaps, sizeof(WAVEINCAPS));
		if (mmresult != MMSYSERR_NOERROR)
			return m_iWaveInID;
		if ((waveincaps.dwFormats & WAVE_FORMAT_1M08) == 0)
			continue;
		else
		{
			m_iWaveInID = i;
			return m_iWaveInID;
		}
	}

	return m_iWaveInID;
}

UINT_PTR CSoundRecord::IfWaveOut()
{
	MMRESULT mmresult = 0;
	UINT_PTR   m_iWaveInID = -1;
	mmresult = waveOutGetNumDevs();

	if (mmresult == 0) return false;

	WAVEOUTCAPS waveincaps = { 0 };
	unsigned int i = 0;
	unsigned int num = mmresult;
	for (; i<num; i++)
	{
		mmresult = waveOutGetDevCaps(i, &waveincaps, sizeof(WAVEOUTCAPS));
		if (mmresult != MMSYSERR_NOERROR)
			return m_iWaveInID;
		if ((waveincaps.dwFormats & WAVE_FORMAT_1M08) == 0)
			continue;
		else
		{
			m_iWaveInID = i;
			return m_iWaveInID;
		}
	}

	return m_iWaveInID;
}