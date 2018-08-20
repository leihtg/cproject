#pragma once
#define INP_BUFFER_SIZE 4096
#define BUF_LEN 5

static HWAVEIN hWaveIn;//录音设备句柄
static HWAVEOUT hWaveOut;//播放设备句柄

class CSoundRecord
{
private:
	WAVEFORMATEX waveForm;//用于打开音频设备的结构

	PBYTE pBufferIn[BUF_LEN];//用于接收和播放的两块缓冲区
	PBYTE pBufferOut[BUF_LEN];//用于发送和录音的两块绥中区

	PWAVEHDR pWaveHdrIn[BUF_LEN];//用于录音的pwavehdr结构数组
	PWAVEHDR pWaveHdrOut[BUF_LEN];//用于播放的结构数组

	char nIn = 0;
public:
	CSoundRecord();
	virtual ~CSoundRecord();
	void initAudio();
	void beginRecord();
	void soundPlay();
	void saveSound(LPSTR buf, int size);
	UINT_PTR IfWaveIn();
	UINT_PTR IfWaveOut();

};

/* wav音频头部格式 */
typedef struct WAVEPCMHDR
{
	char            riff[4];                    // = "RIFF"
	UINT32          size_8;                     // = FileSize - 8
	char            wave[4];                    // = "WAVE"
	char            fmt[4];                     // = "fmt "
	UINT32          fmt_size;                   // = PCMWAVEFORMAT的大小 : 
	//PCMWAVEFORMAT
	UINT16          format_tag;                 // = PCM : 1
	UINT16          channels;                   // = 通道数 : 1
	UINT32          samples_per_sec;            // = 采样率 : 8000 | 6000 | 11025 | 16000
	UINT32          avg_bytes_per_sec;          // = 每秒平均字节数 : samples_per_sec * bits_per_sample / 8
	UINT16          block_align;                // = 每采样点字节数 : wBitsPerSample / 8
	UINT16          bits_per_sample;            // = 量化精度: 8 | 16
	char            data[4];                    // = "data";
	//DATA
	UINT32          data_size;                  // = 裸数据长度 
} WAVEPCMHDR;

/*
============mci操作==============
//　　设置位深：
mciSendString ("set wave bitpersample 8", "", 0, 0);
//　　设置采样率：
mciSendString ("set wave samplespersec 16000", "", 0, 0);
//　　设置声道数：
mciSendString ("set wave channels 1", "", 0, 0);
//　　设置WAVEPCM：
mciSendString ("set wave format tag pcm","", 0, 0);
//　　打开设备：
mciSendString ("open new type WAVEAudio alias WREC",0&,0,0); // 我见很多人写alias movie，这里就是alias个代号
//　　开始录音：
mciSendString ("record WREC",0&,0,0);
//　　停止录音：
mciSendString ("stop WREC",0&,0,0);
//　　保存录音
mciSendString ("save WREC C:\\test.wav",0&,0,0); // 绝对路径
//　　关闭设备：
mciSendString ("close WREC",0&,0,0);
*/