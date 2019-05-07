#ifndef DIRECTX_INPUT_DEVICE_H_
#define DIRECTX_INPUT_DEVICE_H_

#include <dinput.h>

namespace device
{
	/// <summary>
	/// DirectXInputデバイスをまとめたクラス
	/// </summary>
	class DirectXInputDevice
	{
	public:
		DirectXInputDevice()
		{
			Create();
		}

		~DirectXInputDevice()
		{
			m_DXInput->Release();
		}

		/// <summary>
		/// 入力デバイスのゲッター
		/// </summary>
		/// <returns>デバイスのポインタ</returns>
		inline LPDIRECTINPUT8 Get() const
		{
			return m_DXInput;
		}

	private:
		/// <summary>
		/// デバイスの生成
		/// </summary>
		void Create();

		LPDIRECTINPUT8 m_DXInput = nullptr;
	};
}

#endif // !DIRECTX_INPUT_DEVICE_H_
