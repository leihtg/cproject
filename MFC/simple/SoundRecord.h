#pragma once
#define INP_BUFFER_SIZE 4096

static HWAVEIN hWaveIn;//录音设备句柄
static HWAVEOUT hWaveOut;//播放设备句柄

class CSoundRecord
{
private:
	HWND hwnd;
	WAVEFORMATEX waveForm;//用于打开音频设备的结构

	PBYTE pBufferIn[2];//用于接收和播放的两块缓冲区
	PBYTE pBufferOut[2];//用于发送和录音的两块绥中区

	PWAVEHDR pWaveHdrIn[2];//用于录音的pwavehdr结构数组
	PWAVEHDR pWaveHdrOut[2];//用于播放的结构数组

public:
	CSoundRecord(HWND hwnd);
	virtual ~CSoundRecord();
	void beginRecord();
	void soundPlay();
	UINT_PTR IfWaveIn();
	UINT_PTR IfWaveOut();
	
};

