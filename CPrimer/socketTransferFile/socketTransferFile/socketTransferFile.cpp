// socketTransferFile.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <cstdio>
#include <iostream>
#include <direct.h>
#include <io.h>
#include <WinSock2.h>

#pragma comment(lib,"ws2_32.lib")
using namespace std;

DWORD WINAPI recvDataThread(LPVOID);
void socketServer();
void socketClient(char* host, USHORT port);
void sendFile(SOCKET);
void listFiles(char* filename, SOCKET s);
struct FileTime
{
	FILETIME createTime, accessTime, writeTime;
	unsigned    attrib;
	_fsize_t    size;
};

string fname;
string baseDir;
int _tmain(int argc, _TCHAR* argv[])
{
	WORD ver = MAKEWORD(2, 2);
	WSADATA data;
	int err = WSAStartup(ver, &data);
	if (err != 0) {
		return 1;
	}
	/*
	string filename = "C:\\Users\\dell\\Desktop\\recv";
	FileTime fileData;
	HANDLE hd = CreateFileA("C:\\Users\\dell\\Desktop\\pdf.txt", GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_HIDDEN, NULL);
	GetFileTime(hd, &fileData.createTime, &fileData.accessTime, &fileData.writeTime);
	CloseHandle(hd);

	HANDLE hFile = CreateFileA(filename.c_str(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
	SetFileTime(hFile, &fileData.createTime, &fileData.accessTime, &fileData.writeTime);
	CloseHandle(hFile);
	*/
	//sendFile(0);
	//listFiles("C:\\Users\\leihtg\\Desktop\\Agora_Native_SDK_for_Windows_v2_3_2_FULL_1426",NULL);
	//return 1;

	cout << "请选择：\n1.服务器\n2.客户端\n";
	cin >> err;
	if (err == 1){
		cout << "输入要保存的路径:";
		char rl[200];
		cin.getline(rl, 200);
		cin.getline(rl, 200);
		baseDir = rl;
		socketServer();
	}
	else if (err == 2){
		char* host = (char*)malloc(20);
		memset(host, 0, 20);
		USHORT port;
		cout << "输入服务器地址：";
		cin >> host;
		cout << "输入端口号：";
		cin >> port;

		socketClient(host, port);
	}
	WSACleanup();

	return 0;
}
void sendF(string filename, SOCKET s){
	//cout << "发送文件:" << filename << endl;
	_finddata_t fileData;
	intptr_t handle = _findfirst(filename.c_str(), &fileData);
	_findclose(handle);

	HANDLE hFile = CreateFileA(filename.c_str(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
	FileTime ft;
	ft.attrib = fileData.attrib;
	ft.size = fileData.size;

	GetFileTime(hFile, &ft.createTime, &ft.accessTime, &ft.writeTime);
	CloseHandle(hFile);

	int pre = fname.rfind("\\");
	int len = strlen(filename.c_str()) - pre;
	if (_A_SUBDIR&fileData.attrib){
		send(s, (char*)&len, sizeof(len), 0);
		send(s, filename.c_str() + pre, len, 0);
		send(s, (char*)&ft, sizeof(ft), 0);
		return;
	}
	FILE* f;
	errno_t err = fopen_s(&f, filename.c_str(), "rb");
	if (err != 0){
		cout << "读取文件失败:" << filename << "errNo:" << err << endl;
		return;
	}
	send(s, (char*)&len, sizeof(len), 0);
	send(s, filename.c_str() + pre, len, 0);
	send(s, (char*)&ft, sizeof(ft), 0);
	len = 4096;
	char* buf = (char*)malloc(len);
	size_t rt;
	while ((rt = fread(buf, 1, len, f)) != 0){
		send(s, buf, rt, 0);
	}
	free(buf);
	fclose(f);

}
void listFiles(string filename, SOCKET s){
	string dir = filename + "\\*.*";
	_finddata_t  fileData;
	intptr_t handle = _findfirst(dir.c_str(), &fileData);

	if (handle == -1){
		cout << "Failed to find first file!\n";
		return;
	}
	do{
		string buf = filename + "\\" + fileData.name;

		if (_A_SUBDIR & fileData.attrib){
			if (strcmp(fileData.name, ".") == 0 || strcmp(fileData.name, "..") == 0){
				continue;
			}
			listFiles(buf, s);
			sendF(buf, s);
		}
		else{
			sendF(buf, s);
		}
	} while (_findnext(handle, &fileData) == 0);
	_findclose(handle);
}

void socketClient(char* host, USHORT port){
	SOCKET client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.S_un.S_addr = inet_addr(host);
	addr.sin_port = htons(port);
	int err = connect(client, (SOCKADDR*)&addr, sizeof(addr));
	if (err == SOCKET_ERROR){
		cout << "连接失败:" << GetLastError() << endl;
		return;
	}
	cout << "输入发送文件路径：";
	char buf[100];
	cin.getline(buf, 100);
	cin.getline(buf, 100);
	fname = buf;
	listFiles(fname, client);

	closesocket(client);
}

void socketServer(){

	SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (s == INVALID_SOCKET){
		return;
	}
	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(80);
	addr.sin_addr.S_un.S_addr = INADDR_ANY;
	int err = bind(s, (SOCKADDR*)&addr, sizeof(addr));
	if (err == SOCKET_ERROR){
		cout << "绑定socket失败:" << GetLastError() << endl;
		return;
	}
	err = listen(s, 5);

	SOCKADDR_IN cAddr;
	int addrLen = sizeof(cAddr);
	while (true){
		SOCKET* client = (SOCKET*)malloc(sizeof(SOCKET));
		*client = accept(s, (SOCKADDR*)&cAddr, &addrLen);
		CreateThread(NULL, 0, recvDataThread, (void*)client, 0, NULL);
	}
}
int readBuf(SOCKET s, char* buf, int len){
	return recv(s, buf, len, 0);
}
bool createDirs(string dir) {
	string sub;
	int pos = 0;
	int st;
	while ((st = dir.find("\\", pos)) != -1) {
		sub = dir.substr(0, st);
		pos = st + 1;
		int rt = _access(sub.c_str(), 0);
		if (rt == -1) {
			if (_mkdir(sub.c_str())) {
				return false;
			}
		}
	}
	return true;
}

DWORD WINAPI recvDataThread(LPVOID lpParam){

	SOCKET s = *(SOCKET*)lpParam;
	int ret, len = 4096;
	char *buf = new char[len];

	while (true){
		ret = readBuf(s, buf, sizeof(int));
		if (ret <= 0){
			break;
		}
		int pLen = (int)*buf;
		ret = readBuf(s, buf, pLen);
		buf[ret] = '\0';
		cout << buf << endl;
		FileTime fileData;
		ret = readBuf(s, (char*)&fileData, sizeof(fileData));
		string filename = baseDir + buf;
		if (fileData.attrib&_A_SUBDIR){
			createDirs(filename + "\\");
			HANDLE hFile = CreateFileA(filename.c_str(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
			SetFileTime(hFile, &fileData.createTime, &fileData.accessTime, &fileData.writeTime);
			CloseHandle(hFile);
			continue;
		}
		createDirs(filename);
		int total = fileData.size;
		FILE* fp;
		errno_t err = fopen_s(&fp, filename.c_str(), "wb");
		if (err != 0){
			cout << "创建文件失败:" << filename << endl;
		}
		ULONG rd = 0, rdLen = len;
		ULONG sum = fileData.size;
		if (sum < len){
			rdLen = sum;
		}
		do{
			ret = readBuf(s, buf, rdLen);
			if (ret <= 0){
				break;
			}
			fwrite(buf, ret, 1, fp);
			rd += ret;
			if (sum - rd < rdLen){
				rdLen = sum - rd;
			}
			else if (sum == rd){
				break;
			}

		} while (true);
		fclose(fp);
		HANDLE hFile = CreateFileA(filename.c_str(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
		SetFileTime(hFile, &fileData.createTime, &fileData.accessTime, &fileData.writeTime);
		CloseHandle(hFile);

	}
	delete[]buf;
	closesocket(s);

	return 0;
}