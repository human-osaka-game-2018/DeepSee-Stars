#include "DirectXDevice.h"

namespace device
{
	void DirectXDevice::Create()
	{
		if (m_pDIRECT3D9 = Direct3DCreate9(D3D_SDK_VERSION))
		{
			return;
		}

		MessageBox(
			0,
			_T("Direct3Dの作成に失敗しました"),
			NULL,
			MB_OK);
	}
}
