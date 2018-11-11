#include "stdafx.h"
#include "SoundRecord.h"

void prepareWaveHdr(PWAVEHDR &hdr, PBYTE &buf)
{
	buf = (PBYTE)malloc(INP_BUFFER_SIZE);
	if (!buf)
	{
		free(buf);
		AfxMessageBox(_T("内存分配失败"), MB_ICONINFORMATION | MB_OK, NULL);
	}
	hdr = new WAVEHDR;

	hdr->lpData = (char*)buf;
	hdr->dwBufferLength = INP_BUFFER_SIZE;
	hdr->dwBytesRecorded = 0;
	hdr->dwUser = 0;
	hdr->dwFlags = WHDR_BEGINLOOP | WHDR_ENDLOOP;
	hdr->dwLoops = 1;
	hdr->lpNext = NULL;
	hdr->reserved = 0;
}

/**
录音的回调函数
*/
void CALLBACK waveInProc(HWAVEIN hwi, UINT uMsg, DWORD dwInstance, DWORD dwParam1, DWORD dwParam2){
	CSoundRecord* r = (CSoundRecord*)dwInstance;
	WAVEHDR *wave = (WAVEHDR*)dwParam1;
	switch (uMsg)
	{
	case WIM_DATA:
		//缓冲区满
		if (r){
			if (wave->lpData)
			{
				r->saveSound(wave->lpData, wave->dwBytesRecorded);
			}
			if (wave->dwBytesRecorded){//=0时reset
			}
				r->beginRecord();
		}
		break;
	case WIM_CLOSE:
		AfxMessageBox(_T("close"));
		break;
	case WIM_OPEN:
		
		break;
	default:
		break;
	}
}
/*
播放的回调函数
*/
void CALLBACK waveOutProc(HWAVEOUT hwo, UINT uMsg, DWORD_PTR dwInstance, DWORD dwParam1, DWORD dwParam2){
	switch (uMsg)
	{
	case WOM_OPEN:
		
		break;
	case WOM_DONE:
		break;
	case WOM_CLOSE:
		AfxMessageBox(_T("out close"));
		break;
	default:
		break;
	}
}

CSoundRecord::CSoundRecord()
{
	initAudio();
}


CSoundRecord::~CSoundRecord()
{
}

void CSoundRecord::beginRecord(){
	//准备录音缓冲区
	waveInAddBuffer(hWaveIn, pWaveHdrIn[nIn], sizeof(WAVEHDR));
	nIn = ++nIn%BUF_LEN;
	//开始录音
	waveInStart(hWaveIn);
}

void CSoundRecord::soundPlay()
{
	waveInStop(hWaveIn);
	waveInReset(hWaveIn);
	for (int i = 0; i < BUF_LEN; i++){
		waveInUnprepareHeader(hWaveIn, pWaveHdrIn[i], sizeof(WAVEHDR));
	}

	waveInClose(hWaveIn);
	//waveOutWrite(hWaveOut, pWaveHdrIn[0], sizeof(WAVEHDR));
}


UINT_PTR CSoundRecord::IfWaveIn()
{
	MMRESULT mmresult = 0;
	UINT_PTR   m_iWaveInID = -1;
	mmresult = waveInGetNumDevs();
	if (mmresult == 0) return false;

	WAVEINCAPS waveincaps = { 0 };
	unsigned int i = 0;
	unsigned int num = mmresult;
	for (; i < num; i++)
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
	for (; i < num; i++)
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

void CSoundRecord::initAudio(){
	//采样方式
	waveForm.wFormatTag = WAVE_FORMAT_PCM;
	//双声道
	waveForm.nChannels = 2;
	//采样率 11.025 KHZ
	waveForm.nSamplesPerSec = 11025;
	//最小块单元, wBitsPerSamle x nChannels/8
	waveForm.nBlockAlign = 2;
	//数据率 11.025 KB/s
	waveForm.nAvgBytesPerSec = 11025*2;// waveForm.nSamplesPerSec * waveForm.nBlockAlign;
	//样本大小为8bit
	waveForm.wBitsPerSample = 8;
	//附加格式信息
	waveForm.cbSize = 0;

	//准备pWaveHdrIn 和 pWaveHdrOut
	for (int hdrNum = 0; hdrNum < BUF_LEN; hdrNum++)
	{
		prepareWaveHdr(pWaveHdrIn[hdrNum], pBufferIn[hdrNum]);
		prepareWaveHdr(pWaveHdrOut[hdrNum], pBufferOut[hdrNum]);
	}


	//打开播放波形设备
	MMRESULT result;
	UINT_PTR in = IfWaveIn();

	result = waveInOpen(&hWaveIn, in, &waveForm, (DWORD)waveInProc, (DWORD)this, CALLBACK_FUNCTION);

	if (result == MMSYSERR_NOERROR)
	{
		UINT_PTR out = IfWaveOut();
		result = waveOutOpen(&hWaveOut, out, &waveForm, (DWORD)waveOutProc, (DWORD)this, CALLBACK_FUNCTION);
	}
	//为播放和录音准备
	for (int prepare = 0; prepare < BUF_LEN; prepare++)
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
FILE* fp;
int a = fopen_s(&fp, "C:\\Users\\Public\\Desktop\\a.wav", "wb+");
BOOL init = FALSE;

void CSoundRecord::saveSound(LPSTR buf, int size){
	if (!init){
		/* 默认wav音频头部数据 */
		WAVEPCMHDR WavHeader =
		{
			{ 'R', 'I', 'F', 'F' },
			0,
			{ 'W', 'A', 'V', 'E' },
			{ 'f', 'm', 't', ' ' },
			sizeof(PCMWAVEFORMAT),
			WAVE_FORMAT_PCM,
			2,
			11025,
			11025 * (8 / 8),
			8 / 8,
			8,
			{ 'd', 'a', 't', 'a' },
			0
		};
		fwrite(&WavHeader, sizeof(WAVEPCMHDR), 1, fp);
		init = TRUE;
	}
	fseek(fp, 0, SEEK_SET);
	WAVEPCMHDR head;
	fread(&head, sizeof(head), 1, fp);
	head.data_size += size;
	fseek(fp, 0, SEEK_SET);
	fwrite(&head, sizeof(WAVEPCMHDR), 1, fp);
	fseek(fp, 0, SEEK_END);
	fwrite(buf, sizeof(unsigned char), size-1, fp);
	pWaveHdrOut[nIn-1]->lpData = buf;

	waveOutWrite(hWaveOut, pWaveHdrOut[nIn-1], sizeof(WAVEHDR));
}