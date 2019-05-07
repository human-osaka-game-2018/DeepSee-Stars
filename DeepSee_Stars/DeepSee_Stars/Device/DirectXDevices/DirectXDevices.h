#ifndef DIRECTX_DEVICES_H_
#define DIRECTX_DEVICES_H_


#include "../DirectXDevice/DirectXDevice.h"
#include "../DirectXInputDevice/DirectXInputDevice.h"
#include "../DirectXGraphicDevice/DirectXGraphicDevice.h"
#include "DeviceFactory/DeviceFactory.h"

namespace device
{
	/// <summary>
	/// DirectXのデバイスをまとめたクラス
	/// </summary>
	class DirectXDevices
	{
	public:	
		/// <summary>
		/// デバイスを生成する
		/// Windowを作ってから呼ぶ必要がある
		/// </summary>	
		static void Create()
		{
			DeviceFactory::Create(&m_pDXDev);
			DeviceFactory::Create(&m_pDXInput);
			DeviceFactory::Create(&m_pDXGraphicDev, m_pDXDev);
		}

		/// <summary>
		/// デバイスの解放
		/// </summary>
		static void Release()
		{
			delete m_pDXDev;
			m_pDXDev = nullptr;

			delete m_pDXInput;
			m_pDXInput = nullptr;

			delete m_pDXGraphicDev;
			m_pDXGraphicDev = nullptr;
		}

		static inline DirectXDevice* GetDXDevice()
		{
			return m_pDXDev;
		}

		static inline DirectXInputDevice* GetDXInputDevice()
		{
			return m_pDXInput;
		}

		static inline DirectXGraphicDevice* GetDXGraphicDevice()
		{
			return m_pDXGraphicDev;
		}

	private:
		DirectXDevices() {}
		~DirectXDevices() {}

		static DirectXDevice*			m_pDXDev;
		static DirectXInputDevice*		m_pDXInput;
		static DirectXGraphicDevice*	m_pDXGraphicDev;
	};
}

#endif // !DIRECTX_DEVICES_H_
