#ifndef DEVICE_FACTORY_H_
#define DEVICE_FACTORY_H_

#include "../../DirectXDevice/DirectXDevice.h"
#include "../../DirectXGraphicDevice/DirectXGraphicDevice.h"
#include "../../DirectXInputDevice/DirectXInputDevice.h"

namespace device
{
	/// <summary>
	/// デバイス生成クラス
	/// </summary>
	class DeviceFactory
	{
	public:
		/// <summary>
		/// DirectXのデバイスを生成する
		/// </summary>
		/// <param name="ppD3D">DirectXのデバイスのポインタ</param>
		static void Create(DirectXDevice** pDXDev) 
		{
			*pDXDev = new DirectXDevice();
		}

		/// <summary>
		/// DirectInputのデバイスを生成する
		/// </summary>
		/// <param name="ppDXInput">DInputのデバイスのポインタ</param>
		static void Create(DirectXInputDevice** pDXInput)
		{
			*pDXInput = new DirectXInputDevice();
		}
		
		/// <summary>
		/// DirectXの描画デバイスを生成する
		/// </summary>
		/// <param name="pDXGraphicDev">DirectXの描画のデバイスのポインタ</param>
		/// <param name="pDXDev">DirectXのデバイスのポインタ</param>
		static void Create(DirectXGraphicDevice** pDXGraphicDev, DirectXDevice* pDXDev)
		{
			*pDXGraphicDev = new DirectXGraphicDevice(pDXDev);
		}

	private:
		DeviceFactory() {}
		~DeviceFactory() {}
	};
}

#endif // !DEVICE_FACTORY_H_
