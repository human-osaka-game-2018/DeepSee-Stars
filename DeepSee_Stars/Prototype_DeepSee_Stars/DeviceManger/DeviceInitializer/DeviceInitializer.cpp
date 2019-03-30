#include "DeviceInitializer.h"

#include "../../Wnd/Wnd.h"

namespace device
{
	DeviceInitializer::DeviceInitializer()
		:hWnd(window::Wnd::GetHWND())
	{

	}
}
