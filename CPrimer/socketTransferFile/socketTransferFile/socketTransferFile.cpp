// socketTransferFile.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <io.h>
#include "FileUtil.h"

#pragma comment(lib,"ws2_32.lib")
using namespace std;

DWORD WINAPI recvDataThread(LPVOID);
void socketServer();
void socketClient(char* host, USHORT port);
void sendFile(SOCKET);
void listFiles(char* filename, SOCKET s);

string fname;
int pre;
string baseDir;

int _tmain(int argc, _TCHAR* argv[]){

	WORD ver = MAKEWORD(2, 2);
	WSADATA data;
	int err = WSAStartup(ver, &data);
	if (err != 0) {
		return 1;
	}

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

	_finddata_t fileData;
	intptr_t handle = _findfirst(filename.c_str(), &fileData);
	_findclose(handle);
	cout << "发送文件：" << filename << endl;
	FileTime ft = FileUtil::getFileTime(filename);
	ft.attrib = fileData.attrib;
	ft.size = fileData.size;

	int len = filename.size() - pre;

	send(s, (char*)&len, sizeof(len), 0);
	send(s, filename.c_str() + pre, len, 0);
	send(s, (char*)&ft, sizeof(ft), 0);
	if (_A_SUBDIR&fileData.attrib){
		return;
	}
	//等待对方回复
	char ch;
	int r = recv(s, &ch, sizeof(ch), 0);
	if (r == -1){
		cout << "服务端套接字已关闭" << endl;
		return;
	}
	if (ch == 0x11){//需要传送
		send(s, &ch, sizeof(ch), 0);

		FILE* f = _fsopen(filename.c_str(), "rb", _SH_DENYWR);
		if (f == 0){
			cout << "读取文件失败:" << filename << "\t errNo:" << GetLastError() << endl;
			return;
		}
		len = 4096;
		char* buf = (char*)malloc(len);
		size_t rt;
		while ((rt = fread(buf, 1, len, f)) != 0){
			send(s, buf, rt, 0);
		}
		free(buf);
		::fclose(f);
	}
	else if (ch == 0x00){
		return;
	}
	else
	{
		cout << "确认传送文件失败:" << filename << "\t" << ch << endl;
		return;
	}

}
void listFiles(string filename, SOCKET s){
	string dir = filename + "\\*.*";
	_finddata_t  fileData;
	intptr_t handle = _findfirst(dir.c_str(), &fileData);

	if (handle == -1){
		cout << "Failed to find first file!" << endl;
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
	pre = fname.rfind("\\");
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

DWORD WINAPI recvDataThread(LPVOID lpParam){

	SOCKET s = *(SOCKET*)lpParam;
	int ret, len = 4096;
	char *buf = new char[len];

	while (true){
		ret = readBuf(s, buf, sizeof(int));
		if (ret <= 0){
			cout << "对方连接已关闭" << endl;
			break;
		}
		int pLen = buf[3] << 24 | buf[2] << 16 | buf[1] << 8 | *buf;
		ret = readBuf(s, buf, pLen);
		buf[ret] = '\0';
		FileTime fileData;
		ret = readBuf(s, (char*)&fileData, sizeof(fileData));

		cout << buf << "\tsize:" << fileData.size / (1024 * 1024.0) << " MB" << endl;
		string filename = baseDir + buf;
		if (fileData.attrib&_A_SUBDIR){
			FileUtil::createDirs(filename + "\\");
			FileUtil::setFileTime(filename, fileData);
			continue;
		}
		char ch = 0x00;
		FILE* fp;
		if (FileUtil::exists(filename)){
			errno_t err = fopen_s(&fp, filename.c_str(), "rb");
			if (err != 0){
				cout << "打开文件失败:" << filename << endl;
				send(s, &ch, sizeof(ch), 0);//文件创建失败不接收
				continue;
			}
			else
			{
				fseek(fp, 0, SEEK_END);
				if (fileData.size == ftell(fp)){//不需要再传
					send(s, &ch, sizeof(ch), 0);
					continue;
				}
			}
		}
		ch = 0x11;
		FileUtil::createDirs(filename);
		int total = fileData.size;

		errno_t err = fopen_s(&fp, filename.c_str(), "wb");
		if (err != 0){
			cout << "创建文件失败:" << filename << endl;
			ch = 0x00;
			send(s, &ch, sizeof(ch), 0);
			continue;
		}
		send(s, &ch, sizeof(ch), 0);
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
		::fclose(fp);
		FileUtil::setFileTime(filename, fileData);
	}
	delete[]buf;
	closesocket(s);

	return 0;
}