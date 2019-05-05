#include <windows.h>
#include <tchar.h>
#include <crtdbg.h>

#include <cstdio>
#include <cstdlib>

#include "../Wnd/Wnd.h"
#include "../Device/DirectXDevices/DirectXDevices.h"

#include "../GameBaseMaker/GameBaseMaker.h"

using namespace window;
using namespace device;
using namespace gamebasemaker;

class test:public singleton::Singleton<test>
{
public:
	friend class singleton::Singleton<test>;

	test()
	{
		TextureUV uv(D3DXVECTOR2(0.f, 0.f),
			D3DXVECTOR2(2048.f, 2048.f), D3DXVECTOR2(250.f, 300.f));
		verticies = new Vertices(uv);
	}

	void Update()
	{	
		rGameBaseMaker.CreateTex(_T("back"), _T("2Dtexture/Sheep_Stand-by.png"));	
	}

	void Render()
	{
		D3DXVECTOR2 pos = verticies->GetDisplaySize();
		verticies->SetPos(D3DXVECTOR3(pos.x/2.f, pos.y/2.f, 0.0f));
		verticies->Animation(30, 4);
		rGameBaseMaker.Render(*verticies, rGameBaseMaker.GetTex(_T("back")));
	}

private:
	GameBaseMaker& rGameBaseMaker = gamebasemaker::GameBaseMaker::GetInstance();
	Vertices* verticies = nullptr;
};

void RunMain()
{
	test& ts = test::GetInstance();
	ts.Update();
	ts.Render();
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

