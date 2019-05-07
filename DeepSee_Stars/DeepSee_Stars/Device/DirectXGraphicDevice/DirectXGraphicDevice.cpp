#include "DirectXGraphicDevice.h"

namespace device
{
	void DirectXGraphicDevice::Create(DirectXDevice* pDirectXDevice)
	{
		m_pPresentParam = new PresentParam(window::Wnd::GetHWND(), window::Wnd::GetWndSize());

		HWND hWnd = window::Wnd::GetHWND();
		LPDIRECT3D9 DXDevice = pDirectXDevice->GetDXDevice();
		D3DPRESENT_PARAMETERS presentParameters = m_pPresentParam->GetD3DPRESENT_PARAMETERS();

		if (SUCCEEDED(DXDevice->CreateDevice(	//描画をハードウェアに依存させる 軽い
			D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL,
			hWnd,
			D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_MULTITHREADED,
			&presentParameters,
			&m_pDXGraphicDevice)))
		{
			return;
		}

		MessageBox(
			0,
			_T("HALモードでDIRECT3Dデバイスを作成できません/nREFモードで再試行します"),
			NULL,
			MB_OK);

		if (SUCCEEDED(DXDevice->CreateDevice(	//描画をソフトウェアに依存させる 重い
			D3DADAPTER_DEFAULT, D3DDEVTYPE_REF,
			hWnd,
			D3DCREATE_MIXED_VERTEXPROCESSING | D3DCREATE_MULTITHREADED,
			&presentParameters,
			&m_pDXGraphicDevice)))
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
