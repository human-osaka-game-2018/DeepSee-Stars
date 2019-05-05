#ifndef MOUSE_H_
#define MOUSE_H_

#include "../../Device/DirectXDevices/DirectXDevices.h"
#include "../InputDevice/InputDevice.h"

namespace input
{
	enum DIM
	{
		DIM_LEFT,
		DIM_RIGHT,
		DIM_SUB_1,
		DIM_SUB_2,
		DIM_MAX
	};

	class Mouse :public InputDevice
	{
	public:
		Mouse() 
		{
			Create();
		}

		~Mouse()
		{
			m_pDXInputDevice->Release();
		}

		/// <summary>
		/// マウスのボタンの状態の更新
		/// メインループの初めに呼ぶ
		/// </summary>
		inline void UpdateKeyState()
		{
			AcquireInputState();
			CheckInputStateDetatils();
		}

		/// <summary>
		/// マウスのボタンの状態を保存する
		/// </summary>
		inline void PreserveKeyState()
		{
			memcpy(&m_prevState, &m_state, sizeof(DIMOUSESTATE));
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

		/// <summary>
		/// マウスカーソルの位置を取得する
		/// </summary>
		/// <returns>マウスカーソルの位置</returns>
		inline POINT CursorPos() const
		{
			return m_cursorRelativePos;
		}

		/// <summary>
		/// 前フレームからどのくらいスクロールされたか
		/// </summary>
		/// <returns>スクロールされた量</returns>
		inline long WheelScrollingFromPrev() const
		{
			return m_state.lZ;
		}

	private:
		/// <summary>
		/// デバイスの生成
		/// </summary>
		void Create();

		/// <summary>
		/// マウスの状態を取得する権限と、マウスの状態を取得する
		/// </summary>
		void AcquireInputState();

		/// <summary>
		/// マウスのボタンの状態を更新する
		/// AcquireInputState()を読んだ後に用いる
		/// </summary>
		void CheckInputStateDetatils();

		DIMOUSESTATE m_state;
		DIMOUSESTATE m_prevState;

		/// <summary>
		/// カーソルのウィンドウ基準の相対座標
		/// </summary>
		POINT m_cursorRelativePos;					

		INPUT_DETAIL m_details[DIM_MAX];
	};
}

#endif // !MOUSE_H_
