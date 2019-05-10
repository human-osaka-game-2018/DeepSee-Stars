#ifndef GAME_BASE_MAKER_H_
#define GAME_BASE_MAKER_H_

#include <functional>

#include "../Singleton/Singleton.h"
#include "Input/Input.h"
#include "Graphics/Graphics.h"
#include "Sound/Sound.h"

namespace gamebasemaker
{
	using singleton::Singleton;
	using input::Input;
	using graphics::Graphics;
	using graphics::Texture;
	using namespace SoundLib;

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
		inline void DefaultColorBlending() const
		{
			m_graphics.DefaultColorBlending();
		}

		/// <summary>
		/// 音声ファイルを追加する。
		/// </summary>
		/// <param name="pFilePath">ファイルパス</param>
		/// <param name="pKey">音声ファイルを識別するキー</param>
		/// <param name="type">音声に設定する音声種別</param>
		inline void AddFile(const TCHAR* pFilePath, const TCHAR* pKey, Sound::SoundType type)
		{
			m_sound.AddFile(pFilePath, pKey, type);
		}

		/// <summary>
		/// 音声ファイルを10個分追加する。
		/// </summary>
		/// <param name="pFilePath">ファイルパス</param>
		/// <param name="pKey">音声ファイルを識別するキー</param>
		/// <param name="type">音声に設定する音声種別</param>
		inline void AddSimultaneousFile(const TCHAR* pFilePath, const TCHAR* pKey, Sound::SoundType type)
		{
			m_sound.AddSimultaneousFile(pFilePath, pKey, type);
		}

		/// <summary>
		/// ファイルの先頭から単発再生を行う。
		/// </summary>
		/// <param name="pKey">音声ファイルを識別するキー</param>
		inline void OneShotSimultaneous(const TCHAR* pKey)
		{
			m_sound.OneShotSimultaneous(pKey);
		}

		/// <summary>
		/// ファイルの先頭からループ再生を行う。
		/// </summary>
		/// <param name="pKey">音声ファイルを識別するキー</param>
		inline void LoopStart(const TCHAR* pKey)
		{
			m_sound.LoopStart(pKey);
		}

		/// <summary>
		/// ファイルの先頭から再生を行う。
		/// </summary>
		/// <param name="pKey">音声ファイルを識別するキー</param>
		inline void OneShotStart(const TCHAR* pKey)
		{
			m_sound.OneShotStart(pKey);
		}

		/// <summary>
		/// 再生を一時停止する。
		/// </summary>
		/// <param name="pKey">音声ファイルを識別するキー</param>
		/// <returns>成否</returns>
		/// <remarks>続きから再生再開するときには<see cref="Resume(const T*)"/>を実行して下さい。</remarks>
		inline void Pause(const TCHAR* pKey)
		{
			m_sound.Pause(pKey);
		}

		/// <summary>
		/// 一時停止中の音声を続きから再生する。
		/// </summary>
		/// <param name="pKey">音声ファイルを識別するキー</param>
		/// <returns>成否</returns>
		/// <remarks><see cref="Pause(const T*)"/>で一時停止した音声の続きからの再生に使用します。</remarks>
		inline void Resume(const TCHAR* pKey)
		{
			m_sound.Resume(pKey);
		}

		/// <summary>
		/// 再生を停止する。
		/// </summary>
		/// <param name="pKey">音声ファイルを識別するキー</param>
		/// <returns>成否</returns>
		/// <remarks>後で続きから再生する必要がある場合は、<see cref="Pause(const TCHAR*)"/>を使用して下さい。</remarks>
		inline void Stop(const TCHAR* pKey)
		{
			m_sound.Stop(pKey);
		}

		/// <summary>
		/// 再生を停止する。
		/// </summary>
		/// <param name="type">音声ファイルを識別する音声種別</param>
		/// <returns>成否</returns>
		/// <remarks>後で続きから再生する必要がある場合は、<see cref="Pause(const TCHAR*)"/>を使用して下さい。</remarks>
		inline void Stop(Sound::SoundType type = Sound::SoundType::ALL_TYPE)
		{
			m_sound.Stop(type);
		}

		/// <summary>
		/// 再生状況を示すステータスを取得する。
		/// </summary>
		/// <param name="pKey">音声ファイルを識別するキー</param>
		/// <returns>再生ステータス</returns>
		inline SoundLib::PlayingStatus GetStatus(const TCHAR* pKey) const
		{
			m_sound.GetStatus(pKey);
		}

		/// <summary>
		/// ボリュームを取得する。
		/// </summary>
		/// <param name="pKey">音声ファイルを識別するキー</param>
		/// <returns>ボリューム(0:無音　100:音源ボリューム)</returns>
		inline uint8_t GetVolume(const TCHAR* pKey)
		{
			m_sound.GetVolume(pKey);
		}

		/// <summary>
		/// 再生速度とピッチの変化率を取得する。
		/// </summary>
		/// <param name="pKey">音声ファイルを識別するキー</param>
		/// <returns>音源からの変化率</returns>
		/// <remarks>
		/// 1.0の場合、音源から変化なし。
		/// 2.0の場合、再生速度2倍で1オクターブ高音。
		/// 0.5の場合、再生速度1/2で1オクターブ低音。
		/// </remarks>
		inline float GetFrequencyRatio(const TCHAR* pKey)
		{
			m_sound.GetFrequencyRatio(pKey);
		}

		/// <summary>
		/// 再生速度とピッチの変化率を設定する。
		/// </summary>
		/// <param name="pKey">音声ファイルを識別するキー</param>
		/// <param name="ratio">音源からの変化率</param>
		/// <remarks>
		/// <para>
		/// 1.0の場合、音源から変化なし。
		/// 2.0の場合、再生速度2倍で1オクターブ高音。
		/// 0.5の場合、再生速度1/2で1オクターブ低音。
		/// </para>
		/// <para>設定可能最大値は4。</para>
		/// </remarks>
		inline void SetFrequencyRatio(const TCHAR* pKey, float ratio)
		{
			m_sound.SetFrequencyRatio(pKey, ratio);
		}

		/// <summary>
		/// 再生速度とピッチの変化率を設定する。
		/// </summary>
		/// <param name="ratio">音源からの変化率</param>
		/// <param name="type">音声ファイルを識別する音声種別</param>
		/// <returns>成否</returns>
		/// <remarks>
		/// <para>
		/// 1.0の場合、音源から変化なし。
		/// 2.0の場合、再生速度2倍で1オクターブ高音。
		/// 0.5の場合、再生速度1/2で1オクターブ低音。
		/// </para>
		/// <para>設定可能最大値は4。</para>
		/// </remarks>
		inline void SetFrequencyRatio(float ratio, Sound::SoundType type = Sound::SoundType::ALL_TYPE)
		{
			m_sound.SetFrequencyRatio(ratio, type);
		}

		/// <summary>
		/// ボリュームを設定する。
		/// </summary>
		/// <param name="vol">ボリューム(0:無音　100:音源ボリューム)</param>
		/// <param name="pKey">音声ファイルを識別するキー</param>
		inline void SetVolume(int vol, const TCHAR* pKey)
		{
			m_sound.SetVolume(vol, pKey);
		}

		/// <summary>
		/// ボリュームを設定する。
		/// </summary>
		/// <param name="vol">ボリューム(0:無音　100:音源ボリューム)</param>
		/// <param name="type">音声ファイルを識別する音声種別</param>
		inline void SetVolume(int vol, Sound::SoundType type = Sound::SoundType::ALL_TYPE)
		{
			m_sound.SetVolume(vol, type);
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
		Sound m_sound;
	};
}

#endif // !GAME_BASE_MAKER_H_
