#ifndef GAME_BASE_MAKER_H_
#define GAME_BASE_MAKER_H_

#include <functional>

#include "../Singleton/Singleton.h"
#include "Input/Input.h"
#include "Graphics/Graphics.h"

namespace gamebasemaker
{
	using singleton::Singleton;
	using input::Input;
	using graphics::Graphics;
	using graphics::Texture;

	class GameBaseMaker :public Singleton<GameBaseMaker>
	{
	public:
		friend class Singleton<GameBaseMaker>;

		/// <summary>
		/// メッセージループ
		/// </summary>
		/// <param name="Func">ゲームを動かすための関数の関数ポインタ</param>
		void Run(std::function<void()> Func);

		/// <summary>
		/// キーボードのボタンが押された瞬間かを返す
		/// </summary>
		/// <param name="key">ボタンのキー番号</param>
		/// <returns>押された瞬間true</returns>
		inline bool IsPressedToKeyboard(int key)
		{
			return m_input.IsPressedToKeyboard(key);
		}

		/// <summary>
		/// キーボードのボタンが押されているかを返す
		/// </summary>
		/// <param name="key">ボタンのキー番号</param>
		/// <returns>押されていたらtrue</returns>
		inline bool IsHoldToKeyboard(int key)
		{
			return m_input.IsHoldToKeyboard(key);
		}

		/// <summary>
		/// キーボードのボタンが離された瞬間かを返す
		/// </summary>
		/// <param name="key">ボタンのキー番号</param>
		/// <returns>離された瞬間true</returns>
		inline bool IsReleasedToKeyboard(int key)
		{
			return m_input.IsReleasedToKeyboard(key);
		}

		/// <summary>
		/// キーボードのボタンが離されているかを返す
		/// </summary>
		/// <param name="key">ボタンのキー番号</param>
		/// <returns>離されていたらtrue</returns>
		inline bool IsNeutralToKeyboard(int key)
		{
			return m_input.IsNeutralToKeyboard(key);
		}

		/// <summary>
		/// マウスのボタンが押された瞬間かを返す
		/// </summary>
		/// <param name="key">ボタンのキー番号</param>
		/// <returns>押された瞬間true</returns>
		inline bool IsPressedToMouse(int key)
		{
			return m_input.IsPressedToMouse(key);
		}

		/// <summary>
		/// マウスのボタンが押されているかを返す
		/// </summary>
		/// <param name="key">ボタンのキー番号</param>
		/// <returns>押されていたらtrue</returns>
		inline bool IsHoldToMouse(int key)
		{
			return m_input.IsHoldToMouse(key);
		}

		/// <summary>
		/// マウスのボタンが離された瞬間かを返す
		/// </summary>
		/// <param name="key">ボタンのキー番号</param>
		/// <returns>離された瞬間true</returns>
		inline bool IsReleasedToMouse(int key)
		{
			return m_input.IsReleasedToMouse(key);
		}

		/// <summary>
		/// マウスのボタンが離されているかを返す
		/// </summary>
		/// <param name="key">ボタンのキー番号</param>
		/// <returns>離されていたらtrue</returns>
		inline bool IsNeutralToMouse(int key)
		{
			return m_input.IsNeutralToMouse(key);
		}

		/// <summary>
		/// マウスカーソルの位置を取得する
		/// </summary>
		/// <returns>マウスカーソルの位置</returns>
		inline POINT CursorPos() const
		{
			return m_input.CursorPos();
		}

		/// <summary>
		/// 前フレームからどのくらいスクロールされたか
		/// </summary>
		/// <returns>スクロールされた量</returns>
		inline long WheelScrollingFromPrev() const
		{
			return m_input.WheelScrollingFromPrev();
		}

		/// <summary>
		/// 画像を描画する
		/// </summary>
		/// <param name="vertices">矩形の情報</param>
		/// <param name="texture">テクスチャの情報</param>
		inline void Render(gamebasemaker::Vertices vertices, Texture texture)
		{
			m_graphics.Render(vertices, texture);
		}

		/// <summary>
		/// テクスチャの生成
		/// </summary>
		/// <param name="pKey">テクスチャのキーワード</param>
		/// <param name="pTexPath">テクスチャのファイルパス</param>
		inline void CreateTex(const TCHAR* pKey, const TCHAR* pTexPath)
		{
			m_graphics.CreateTex(pKey, pTexPath);
		}

		/// <summary>
		/// 指定したテクスチャの削除
		/// </summary>
		/// <param name="pKey">削除したいテクスチャのキーワード</param>
		inline void EraseTex(const TCHAR* pKey)
		{
			m_graphics.EraseTex(pKey);
		}

		/// <summary>
		/// テクスチャの全開放
		/// </summary>
		inline void ReleaseAllTex()
		{
			m_graphics.ReleaseAllTex();
		}

		inline Texture GetTex(const TCHAR* pKey)
		{
			return m_graphics.GetTex(pKey);
		}

		/// <summary>
		/// 色の合成を通常合成に変更する デフォルトでは通常合成になっている
		/// </summary>
		inline void DefaultBlendMode() const
		{
			m_graphics.DefaultBlendMode();
		}

		/// <summary>
		/// 色の合成を加算合成に変更する
		/// </summary>
		inline void AddtionBlendMode() const
		{
			m_graphics.AddtionBlendMode();
		}

		/// <summary>
		/// デフォルトの色合成を使用する ウィンドウモードを切り替えた時には再設定する必要がある
		/// </summary>
		void DefaultColorBlending() const
		{
			m_graphics.DefaultColorBlending();
		}

	private:
		/// <summary>
		/// 開始準備をする
		/// </summary>
		inline void Prepare()
		{
			m_input.UpdateKeyState();
			m_graphics.PrepareRendering();
		}

		/// <summary>
		/// 1フレームの終了
		/// </summary>
		void CleanUp()
		{
			m_input.PreserveKeyState();
			m_graphics.CleanUpRendering();
		}

		Input m_input;
		Graphics m_graphics;
	};
}

#endif // !GAME_BASE_MAKER_H_
