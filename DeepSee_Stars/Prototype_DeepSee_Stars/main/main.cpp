#include "main.h"

#include <windows.h>
#include <tchar.h>
#include <crtdbg.h>

#include <cstdio>
#include <cstdlib>

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR szStr, INT iCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	return 0;
}

