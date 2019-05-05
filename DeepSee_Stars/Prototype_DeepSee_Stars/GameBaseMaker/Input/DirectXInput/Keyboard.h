#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include "../../Device/DirectXDevices/DirectXDevices.h"
#include "../InputDevice/InputDevice.h"

namespace input
{
	class Keyboard:public InputDevice
	{
	public:
		Keyboard() 
		{
			Create();
		}

		~Keyboard() 
		{
			m_pDXInputDevice->Release();
		}
		
		/// <summary>
		/// キーボードのボタンの状態の更新
		/// メインループの初めに呼ぶ
		/// </summary>
		inline void UpdateKeyState()
		{
			AcquireInputState();
			CheckInputStateDetatils();
		}

		/// <summary>
		/// キーボードのボタンの状態を保存する
		/// </summary>
		inline void PreserveKeyState()
		{
			memcpy(m_prevDiks, m_diks, sizeof(BYTE) * 256);
		}

		/// <summary>
		/// ボタンが押された瞬間かを返す
		/// </summary>
		/// <param name="key">ボタンのキー番号</param>
		/// <returns>押された瞬間true</returns>
		inline bool IsPressed(int key)
		{
			return (m_details[key] == IND_PRESS);
		}

		/// <summary>
		/// ボタンが押されているかを返す
		/// </summary>
		/// <param name="key">ボタンのキー番号</param>
		/// <returns>押されていたらtrue</returns>
		inline bool IsHold(int key)
		{
			return (m_details[key] == IND_HOLD);
		}

		/// <summary>
		/// ボタンが離された瞬間かを返す
		/// </summary>
		/// <param name="key">ボタンのキー番号</param>
		/// <returns>離された瞬間true</returns>
		inline bool IsReleased(int key)
		{
			return (m_details[key] == IND_RELEASE);
		}

		/// <summary>
		/// ボタンが離されているかを返す
		/// </summary>
		/// <param name="key">ボタンのキー番号</param>
		/// <returns>離されていたらtrue</returns>
		inline bool IsNeutral(int key)
		{
			return (m_details[key] == IND_NEUTRAL);
		}

	private:
		/// <summary>
		/// デバイスの生成
		/// </summary>
		void Create();

		/// <summary>
		/// キーボードの状態を取得する権限と、キーボードの状態を取得する
		/// </summary>
		inline void AcquireInputState()
		{
			m_pDXInputDevice->Acquire();		

			m_pDXInputDevice->GetDeviceState(
				sizeof(BYTE) * 256,
				m_diks);
		}

		/// <summary>
		/// キーの状態を更新する
		/// AcquireInputState()を読んだ後に用いる
		/// </summary>
		void CheckInputStateDetatils();

		BYTE m_diks[256];
		BYTE m_prevDiks[256];

		INPUT_DETAIL m_details[256];
	};
}

#endif // !KEYBOARD_H_
