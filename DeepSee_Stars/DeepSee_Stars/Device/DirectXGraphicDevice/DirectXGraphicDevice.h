#ifndef DIRECTX_GRAPHIC_DEVICE_H_
#define DIRECTX_GRAPHIC_DEVICE_H_

#include <d3dx9.h>
#include <tchar.h>

#include "../../Wnd/Wnd.h"

#include "../DirectXDevice/DirectXDevice.h"
#include "PresentParam/PresentParam.h"

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
			delete m_pPresentParam;
			m_pPresentParam = nullptr;
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
		inline PresentParam* GetPresentParam() const
		{
			return m_pPresentParam;
		}

	private:
		/// <summary>
		/// デバイスの生成
		/// </summary>
		/// <param name="pDirectXDevice">DirectXのデバイス情報</param>
		void Create(DirectXDevice* pDirectXDevice);

		LPDIRECT3DDEVICE9 m_pDXGraphicDevice = nullptr;

		PresentParam* m_pPresentParam = nullptr;
	};
}

#endif // !DIRECTX_GRAPHIC_DEVICE_H_
