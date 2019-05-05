#ifndef INPUT_DEVICE_H_
#define INPUT_DEVICE_H_

#include <Windows.h>

#include <dinput.h>

#include "../../Wnd/Wnd.h"

namespace input
{
	/// <summary>
	/// 入力デバイス関係の基底クラス
	/// </summary>
	class InputDevice
	{
	public:
		InputDevice() :m_HWND(window::Wnd::GetHWND()) {}
		virtual ~InputDevice() {}

		/// <summary>
		/// ボタンが押された瞬間かを返す
		/// </summary>
		/// <param name="key">ボタンのキー番号</param>
		/// <returns>押された瞬間true</returns>
		virtual bool IsPressed(int key) = 0;

		/// <summary>
		/// ボタンが押されているかを返す
		/// </summary>
		/// <param name="key">ボタンのキー番号</param>
		/// <returns>押されていたらtrue</returns>
		virtual bool IsHold(int key) = 0;

		/// <summary>
		/// ボタンが離された瞬間かを返す
		/// </summary>
		/// <param name="key">ボタンのキー番号</param>
		/// <returns>離された瞬間true</returns>
		virtual bool IsReleased(int key) = 0;
		
		/// <summary>
		/// ボタンが離されているかを返す
		/// </summary>
		/// <param name="key">ボタンのキー番号</param>
		/// <returns>離されていたらtrue</returns>
		virtual bool IsNeutral(int key) = 0;

	protected:
		enum INPUT_DETAIL
		{
			IND_PRESS,										//押された瞬間のフレームだけTRUE
			IND_HOLD,										//押され続けられている間TRUE
			IND_RELEASE,									//離された瞬間のフレームだけTRUE
			IND_NEUTRAL,									//前回と現在のフレームで押されていない間TRUE
			IND_MAX
		};

		virtual void AcquireInputState() = 0;
		virtual void CheckInputStateDetatils() = 0;
		virtual void Create() = 0;

		inline bool IsInputted(const BYTE& rKey) const
		{
			return (rKey & 0x80);
		}

		const HWND m_HWND = nullptr;

		LPDIRECTINPUTDEVICE8 m_pDXInputDevice = nullptr;
	};
}

#endif // !INPUT_DEVICE_H_
