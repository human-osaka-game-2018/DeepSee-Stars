#include "DeviceFactory.h"

namespace device
{
	void DeviceFactory::Create(LPDIRECT3D9* ppD3D)
	{
		ppD3D = new LPDIRECT3D9();
	}

	void DeviceFactory::Create(LPDIRECTINPUT8* ppDXInput)
	{
		ppDXInput = new LPDIRECTINPUT8();
	}

	void DeviceFactory::Create(DirectXGraphicDevice* ppDXGraphicDev)
	{
		ppDXGraphicDev = new DirectXGraphicDevice();
	}
}
