#include "DirectXInputDevice.h"

namespace device
{
	void DirectXInputDevice::Create()
	{
		DirectInput8Create(
			GetModuleHandle(NULL),
			DIRECTINPUT_VERSION, IID_IDirectInput8,
			(void**)&m_DXInput,
			NULL);
	}

}
