#ifndef DIRECTX_GRAPHIC_DEVICE_H_
#define DIRECTX_GRAPHIC_DEVICE_H_

#include <d3dx9.h>
#include <tchar.h>

#include "../../Wnd/Wnd.h"

#include "../DirectXDevice/DirectXDevice.h"
#include "D3DPP/D3DPP.h"

namespace device
{
	/// <summary>
	///DirectXのグラフィック関連に必要な情報をまとめた構造体
	/// </summary>
	class DirectXGraphicDevice
	{
	public:
		DirectXGraphicDevice(DirectXDevice* pDirectXDevice)
		{
			Create(pDirectXDevice);
		}

		~DirectXGraphicDevice()
		{
			m_pDXGraphicDevice->Release();
			delete m_pD3Dpp;
			m_pD3Dpp = nullptr;
		}

		/// <summary>
		/// グラフィックデバイスのゲッター
		/// </summary>
		/// <returns>デバイスのポインタ</returns>
		inline LPDIRECT3DDEVICE9 GetGraphicDevice() const
		{
			return m_pDXGraphicDevice;
		}

		/// <summary>
		/// バックバッファ関係クラスのゲッター
		/// </summary>
		/// <returns>バックバッファ関係クラスのポインタ</returns>
		inline D3DPP* GetD3DPP() const
		{
			return m_pD3Dpp;
		}

	private:
		/// <summary>
		/// デバイスの生成
		/// </summary>
		/// <param name="pDirectXDevice">DirectXのデバイス情報</param>
		void Create(DirectXDevice* pDirectXDevice);

		LPDIRECT3DDEVICE9 m_pDXGraphicDevice = nullptr;

		D3DPP* m_pD3Dpp = nullptr;
	};
}

#endif // !DIRECTX_GRAPHIC_DEVICE_H_
