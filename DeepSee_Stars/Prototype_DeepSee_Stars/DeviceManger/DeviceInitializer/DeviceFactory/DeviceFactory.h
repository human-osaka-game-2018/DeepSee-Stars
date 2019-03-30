#ifndef DEVICE_FACTORY_H_
#define DEVICE_FACTORY_H_

#include <d3dx9.h>
#include <dinput.h>

#include "../../DirectXGraphicDevice/DirectXGraphicDevice.h"

namespace device
{
	/// <summary>
	/// デバイス生成クラス
	/// </summary>
	class DeviceFactory
	{
	public:
		~DeviceFactory() {}

		/// <summary>
		/// DirectXのデバイスを生成する
		/// </summary>
		/// <param name="ppD3D">DirectXのデバイスのポインタのポインタ</param>
		static void Create(LPDIRECT3D9* ppD3D);

		/// <summary>
		/// DirectInputのデバイスを生成する
		/// </summary>
		/// <param name="ppDXInput">DInputのデバイスのポインタのポインタ</param>
		static void Create(LPDIRECTINPUT8* ppDXInput);
		
		/// <summary>
		/// DirectXの描画デバイスを生成する
		/// </summary>
		/// <param name="pDXDev">DirectXの描画のデバイスのポインタのポインタ</param>
		static void Create(DirectXGraphicDevice* pDXGraphicDev);

	private:
		DeviceFactory() {}
	};
}

#endif // !DEVICE_FACTORY_H_
