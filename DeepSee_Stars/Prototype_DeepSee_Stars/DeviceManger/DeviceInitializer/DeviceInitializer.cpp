#include "DeviceInitializer.h"

#include <tchar.h>

#include "../../Wnd/Wnd.h"
#include "DeviceFactory/DeviceFactory.h"

namespace device
{
	DeviceInitializer::DeviceInitializer(LPDIRECT3D9* ppD3D, LPDIRECTINPUT8* ppDXInput, DirectXGraphicDevice* pDXGraphicDev)
		:hWnd(window::Wnd::GetHWND())
	{
		DeviceFactory::Create(ppD3D);
		DeviceFactory::Create(ppDXInput);
		DeviceFactory::Create(pDXGraphicDev);
	}

	void DeviceInitializer::InitializeDevices()
	{
		InitializeDXDevice();
		InitializeInputDevice();
		InitializeGraphicDevice();
	}

	void DeviceInitializer::InitializeDXDevice()
	{
		if (*m_ppD3D = Direct3DCreate9(D3D_SDK_VERSION))
		{
			return;
		}

		MessageBox(
			0,
			_T("Direct3Dの作成に失敗しました"),
			NULL,
			MB_OK);
	}

	void DeviceInitializer::InitializeInputDevice()
	{
		DirectInput8Create(
			GetModuleHandle(NULL),
			DIRECTINPUT_VERSION, IID_IDirectInput8,
			(VOID**)&m_ppDXInput,
			NULL);
	}

	void DeviceInitializer::InitializeGraphicDevice()
	{
		D3DPRESENT_PARAMETERS D3DPP = m_pDXGraphicDev->m_pD3Dpp->GetD3DPRESENT_PARAMETERS();

		if (SUCCEEDED((*m_ppD3D)->CreateDevice(	//描画をハードウェアに依存させる 軽い
			D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL,
			hWnd,
			D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_MULTITHREADED,
			&D3DPP,
			&m_pDXGraphicDev->m_pDXGraphicDevice)))
		{
			return;
		}

		MessageBox(
			0,
			_T("HALモードでDIRECT3Dデバイスを作成できません/nREFモードで再試行します"),
			NULL,
			MB_OK);

		if (SUCCEEDED((*m_ppD3D)->CreateDevice(	//描画をソフトウェアに依存させる 重い
			D3DADAPTER_DEFAULT, D3DDEVTYPE_REF,
			hWnd,
			D3DCREATE_MIXED_VERTEXPROCESSING | D3DCREATE_MULTITHREADED,
			&D3DPP,
			&m_pDXGraphicDev->m_pDXGraphicDevice)))
		{
			return;
		}

		MessageBox(
			0,
			_T("DIRECT3Dデバイスの作成に失敗しました"),
			NULL,
			MB_OK);

		DestroyWindow(hWnd);	//WM_DESTROYをWndProcに投げる
	}
}
