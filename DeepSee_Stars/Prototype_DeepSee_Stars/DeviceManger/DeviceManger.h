#ifndef DEVICE_MANAGER_H_
#define DEVICE_MANAGER_H_

#include "../Singleton/Singleton.h"

namespace device
{
	class DeviceManager:public singleton::Singleton<DeviceManager>
	{
	public:
		friend class singleton::Singleton<DeviceManager>;

		~DeviceManager() {};
	};
}

#endif // !DEVICE_MANAGER_H_
