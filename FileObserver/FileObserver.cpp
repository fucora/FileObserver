// FileObserver.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <Windows.h>
#include <thread>


void ThreadRoute() {
	wchar_t filename[1024] = { 0 };
	MultiByteToWideChar(0, 0, "c:\\codes", strlen("c:\\codes"), filename, strlen("c:\\codes"));
	HANDLE file;
	file = FindFirstChangeNotification(filename, FALSE, FILE_NOTIFY_CHANGE_SIZE);
	WaitForSingleObject(file, INFINITE);

	FILE *fileO;
	char list[2] = { ' ', '\0' };
	fopen_s(&fileO, "c:/codes/test.txt", "a+");
	fread(list, 1, 1, fileO);
	fclose(fileO);
	printf("%s\n", list);
	FindCloseChangeNotification(file);

}

int _tmain(int argc, _TCHAR* argv[])
{
	std::thread t(ThreadRoute);
	t.join();
	printf("Firefox started\n");
	std::thread x(ThreadRoute);
	x.join();


	printf("Firefox terminated start copying");
	getchar();
	return 0;
}

