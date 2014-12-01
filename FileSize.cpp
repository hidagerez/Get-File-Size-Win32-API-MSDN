#include <windows.h>

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow){
	
	DWORD read;
	HANDLE hfile, hfile2;
	DWORD FileSize = 0;
	char c_FileSize[30] = { 0 };
	char buffer[4096] = { 0 };
	int counter = 0;
	
	hfile = CreateFile(lpCmdLine, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	hfile2 = CreateFile(("output.txt"), GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
	FileSize = GetFileSize(hfile, NULL);
	_itoa_s(FileSize, c_FileSize, 10);
	MessageBox(NULL, c_FileSize, "Size of File", NULL);
	ReadFile(hfile, buffer, FileSize, &read, NULL);
	
	for each (char c in buffer) {
		c = char((int)c + 1);
		buffer[counter] = c;
		counter += 1;	
	}

	WriteFile(hfile2, buffer,FileSize, &read, NULL); 
	CloseHandle(hfile);

	 return(0);

  }