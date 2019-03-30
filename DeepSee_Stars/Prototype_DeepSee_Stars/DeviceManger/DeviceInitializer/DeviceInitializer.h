#ifndef DEVICE_INITIALIZER_H_
#define DEVICE_INITIALIZER_H_

#include <windows.h>

#include <d3dx9.h>
#include <dinput.h>

#include "../DirectXGraphicDevice/DirectXGraphicDevice.h"

namespace device
{
	/// <summary>
	/// デバイス初期化クラス
	/// </summary>
	class DeviceInitializer
	{
	public:
		/// <summary>
		/// 生成するデバイス情報
		/// </summary>
		/// <param name="ppD3D">DirectXのデバイスのポインタのポインタ</param>
		/// <param name="ppDXInput">DInputのデバイスのポインタのポインタ</param>
		/// <param name="pDXGraphicDev">DirectXの描画のデバイスのポインタのポインタ</param>
		DeviceInitializer(LPDIRECT3D9* ppD3D,LPDIRECTINPUT8* ppDXInput, DirectXGraphicDevice* pDXGraphicDev);
		
		~DeviceInitializer() 
		{
			delete m_pDXGraphicDev;
			(*m_pDXGraphicDev->m_pDXGraphicDevice).Release();
			(*m_ppD3D)->Release();
			(*m_ppDXInput)->Release();
		}
		
		/// <summary>
		/// デバイスの初期化関数をまとめたもの
		/// </summary>
		void InitializeDevices();

	private:
		/// <summary>
		/// DirectXのデバイス情報を初期化する
		/// </summary>
		void InitializeDXDevice();

		/// <summary>
		/// 入力デバイス情報を初期化する
		/// </summary>
		void InitializeInputDevice();

		/// <summary>
		/// 描画のデバイス情報を初期化する
		/// </summary>
		void InitializeGraphicDevice();

		const HWND& hWnd;
		LPDIRECT3D9* m_ppD3D;
		LPDIRECTINPUT8* m_ppDXInput;
		DirectXGraphicDevice* m_pDXGraphicDev;
	};
}

#endif // !DEVICE_INITIALIZER_H_1
