#include <windows.h>
#include <iostream.h>

DWORD WINAPI Fun1Proc(LPVOID lp);
DWORD WINAPI Fun2Proc(LPVOID lp);
int tickets=100;
HANDLE mutex;

int main(){
//	mutex=CreateMutex(NULL,FALSE,NULL);
	mutex=CreateMutex(NULL,FALSE,"tickets");

	HANDLE p1=CreateThread(NULL,0,Fun1Proc,NULL,0,NULL);
	HANDLE p2=CreateThread(NULL,0,Fun2Proc,NULL,0,NULL);
	CloseHandle(p1);
	CloseHandle(p2);
	if(mutex){
		if(ERROR_ALREADY_EXISTS==GetLastError()){
			cout<<"only instanse can run!"<<endl;
			return 0;
		}
	}
	Sleep(4000);
	return 0;
}
DWORD WINAPI Fun1Proc(LPVOID lp){
	while(true){
		WaitForSingleObject(mutex,INFINITE);
		if(tickets>0){
			Sleep(1);
			cout<<"´°¿Ú1ÂôÆ±£º"<<tickets--<<endl;
		}else{
			break;
		}
		ReleaseMutex(mutex);
	}
	return 0;
}
DWORD WINAPI Fun2Proc(LPVOID lp){
	while(true){
		WaitForSingleObject(mutex,INFINITE);
		if(tickets>0){
			Sleep(1);
			cout<<"´°¿Ú2ÂôÆ±£º____"<<tickets--<<endl;
		}else{
			break;
		}
		ReleaseMutex(mutex);
	}
	return 0;
}