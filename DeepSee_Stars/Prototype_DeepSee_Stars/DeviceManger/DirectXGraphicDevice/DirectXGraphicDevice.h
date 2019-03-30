#ifndef DIRECTX_GRAPHIC_DEVICE_H_
#define DIRECTX_GRAPHIC_DEVICE_H_

#include <d3dx9.h>

#include "../../Wnd/Wnd.h"
#include "../../Wnd/Data/RectSize.h"

#include "D3DPP/D3DPP.h"

namespace device
{
	/// <summary>
	///DirectXのグラフィック関連に必要な情報をまとめた構造体
	/// </summary>
	struct DirectXGraphicDevice
	{
	public:
		DirectXGraphicDevice()
		{
			m_pD3Dpp = new D3DPP(window::Wnd::GetHWND(), window::Wnd::GetWndSize());
		}

		~DirectXGraphicDevice()
		{
			delete m_pD3Dpp;
		}

		LPDIRECT3DDEVICE9 m_pDXGraphicDevice;

		D3DPP* m_pD3Dpp;
	};
}

#endif // !DIRECTX_GRAPHIC_DEVICE_H_
