#include <windows.h>
#include <tchar.h>
#include <crtdbg.h>

#include <cstdio>
#include <cstdlib>

#include "../Wnd/Wnd.h"
#include "../Device/DirectXDevices/DirectXDevices.h"

#include "../GameBaseMaker/GameBaseMaker.h"

#include "../SceneManager/SceneManager.h"

using namespace window;
using namespace device;
using namespace gamebasemaker;
using deepseestars::SceneManager;

void RunMain()
{
	SceneManager& rSceneManager = SceneManager::GetInstance();
	rSceneManager.Update();
	rSceneManager.Render();
}

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR szStr, INT iCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Wnd::Create(hInst, _T("DeepSee_Stars"));

	DirectXDevices::Create();

	gamebasemaker::GameBaseMaker& rGameBaseMaker = gamebasemaker::GameBaseMaker::GetInstance();

	rGameBaseMaker.Run(RunMain);

	DirectXDevices::Release();

	return 0;
}

