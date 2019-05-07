#ifndef DIRECTX_DEVICE_H_
#define DIRECTX_DEVICE_H_

#include <tchar.h>

#include <d3dx9.h>

namespace device
{
	/// <summary>
	/// DirectXのデバイスをまとめたクラス
	/// </summary>
	class DirectXDevice
	{
	public:
		DirectXDevice()
		{
			Create();
		}

		~DirectXDevice() 
		{
			m_pDIRECT3D9->Release();
		}

		/// <summary>
		/// デバイスのゲッター
		/// </summary>
		/// <returns>デバイスのポインタ</returns>
		inline LPDIRECT3D9 GetDXDevice() const
		{
			return m_pDIRECT3D9;
		}

	private:
		/// <summary>
		/// デバイスの生成
		/// </summary>
		void Create();

		LPDIRECT3D9 m_pDIRECT3D9 = nullptr;
	};
}

#endif // !DIRECTX_DEVICE_H_
