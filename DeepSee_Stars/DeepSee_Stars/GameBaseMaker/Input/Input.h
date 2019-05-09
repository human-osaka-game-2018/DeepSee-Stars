#ifndef INPUT_H_
#define INPUT_H_

#include "DirectXInput/Keyboard.h"
#include "DirectXInput/Mouse.h"

namespace input
{
	class Input
	{
	public:
		Input(){}
		~Input() {}

		/// <summary>
		/// ボタンの状態を更新する
		/// メインループの初めに呼ぶ
		/// </summary>
		inline void UpdateKeyState()
		{
			m_keyboard.UpdateKeyState();
			m_mouse.UpdateKeyState();
		}

		/// <summary>
		/// ボタンの状態を保存する
		/// メインループの終わりに呼ぶ
		/// </summary>
		inline void PreserveKeyState()
		{
			m_keyboard.PreserveKeyState();
			m_mouse.PreserveKeyState();
		}

		/// <summary>
		/// キーボードのボタンが押された瞬間かを返す
		/// </summary>
		/// <param name="key">ボタンのキー番号</param>
		/// <returns>押された瞬間true</returns>
		inline bool IsPressedToKeyboard(int key)
		{
			return m_keyboard.IsPressed(key);
		}

		/// <summary>
		/// キーボードのボタンが押されているかを返す
		/// </summary>
		/// <param name="key">ボタンのキー番号</param>
		/// <returns>押されていたらtrue</returns>
		inline bool IsHoldToKeyboard(int key)
		{
			return m_keyboard.IsHold(key);
		}

		/// <summary>
		/// キーボードのボタンが離された瞬間かを返す
		/// </summary>
		/// <param name="key">ボタンのキー番号</param>
		/// <returns>離された瞬間true</returns>
		inline bool IsReleasedToKeyboard(int key)
		{
			return m_keyboard.IsReleased(key);
		}

		/// <summary>
		/// キーボードのボタンが離されているかを返す
		/// </summary>
		/// <param name="key">ボタンのキー番号</param>
		/// <returns>離されていたらtrue</returns>
		inline bool IsNeutralToKeyboard(int key)
		{
			return m_keyboard.IsNeutral(key);
		}

		/// <summary>
		/// マウスのボタンが押された瞬間かを返す
		/// </summary>
		/// <param name="key">ボタンのキー番号</param>
		/// <returns>押された瞬間true</returns>
		inline bool IsPressedToMouse(int key)
		{
			return m_mouse.IsPressed(key);
		}

		/// <summary>
		/// マウスのボタンが押されているかを返す
		/// </summary>
		/// <param name="key">ボタンのキー番号</param>
		/// <returns>押されていたらtrue</returns>
		inline bool IsHoldToMouse(int key)
		{
			return m_mouse.IsHold(key);
		}

		/// <summary>
		/// マウスのボタンが離された瞬間かを返す
		/// </summary>
		/// <param name="key">ボタンのキー番号</param>
		/// <returns>離された瞬間true</returns>
		inline bool IsReleasedToMouse(int key)
		{
			return m_mouse.IsReleased(key);
		}

		/// <summary>
		/// マウスのボタンが離されているかを返す
		/// </summary>
		/// <param name="key">ボタンのキー番号</param>
		/// <returns>離されていたらtrue</returns>
		inline bool IsNeutralToMouse(int key)
		{
			return m_mouse.IsNeutral(key);
		}

		/// <summary>
		/// マウスカーソルの位置を取得する
		/// </summary>
		/// <returns>マウスカーソルの位置</returns>
		inline POINT CursorPos() const
		{
			return m_mouse.CursorPos();
		}

		/// <summary>
		/// 前フレームからどのくらいスクロールされたか
		/// </summary>
		/// <returns>スクロールされた量</returns>
		inline long WheelScrollingFromPrev() const
		{
			return m_mouse.WheelScrollingFromPrev();
		}

	private:
		Keyboard m_keyboard;
		Mouse m_mouse;
	};
}

#endif // !INPUT_H_
