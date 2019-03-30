#ifndef DEVICE_INITIALIZER_H_
#define DEVICE_INITIALIZER_H_

#include <windows.h>

#include <d3dx9.h>
#include <dinput.h>

namespace device
{
	class DeviceInitializer
	{
	public:
		DeviceInitializer();
		~DeviceInitializer() {}
	
		static void Initialize();

	private:
		const HWND hWnd = nullptr;
		LPDIRECT3D9 m_pD3D = nullptr;
		LPDIRECTINPUT8 m_pDXInput = nullptr;
		LPDIRECT3DDEVICE9 m_pDX3DDev = nullptr;
	};
}

#endif // !DEVICE_INITIALIZER_H_1
