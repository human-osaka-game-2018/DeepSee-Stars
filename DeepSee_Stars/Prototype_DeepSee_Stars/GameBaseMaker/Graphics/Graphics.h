#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include "../Vertices/Vertices.h"
#include "Renderer/Renderer.h"
#include "Textures/Textures.h"
#include "ColorBlender/ColorBlender.h"

namespace graphics
{
	/// <summary>
	/// 描画関連で使う関数のファサードクラス
	/// </summary>
	class Graphics
	{
	public:
		Graphics() {}
		~Graphics() {}

		/// <summary>
		/// 描画準備をする
		/// </summary>
		/// <remarks>メッセージループの最初で呼ぶ必要がある</remarks>
		inline void PrepareRendering()
		{
			m_renderer.PrepareRendering();
		}

		/// <summary>
		/// 描画を終了させる
		/// </summary>
		/// <remarks>メッセージループの最後に呼ぶ必要がある</remarks>
		inline void CleanUpRendering()
		{
			m_renderer.CleanUpRendering();
		}

		/// <summary>
		/// 画像を描画する
		/// </summary>
		/// <param name="vertices">矩形の情報</param>
		/// <param name="texture">テクスチャの情報</param>
		inline void Render(gamebasemaker::Vertices vertices, Texture texture)
		{
			m_renderer.Render(vertices, texture);
		}

		/// <summary>
		/// テクスチャの生成
		/// </summary>
		/// <param name="pKey">テクスチャのキーワード</param>
		/// <param name="pTexPath">テクスチャのファイルパス</param>
		inline void CreateTex(const TCHAR* pKey, const TCHAR* pTexPath)
		{
			m_textures.CreateTex(pKey, pTexPath);
		}

		/// <summary>
		/// 指定したテクスチャの削除
		/// </summary>
		/// <param name="pKey">削除したいテクスチャのキーワード</param>
		inline void EraseTex(const TCHAR* pKey) 
		{
			m_textures.EraseTex(pKey);
		}

		/// <summary>
		/// テクスチャの全開放
		/// </summary>
		inline void ReleaseAllTex()
		{
			m_textures.ReleaseAllTex();
		}

		inline Texture GetTex(const TCHAR* pKey)
		{
			return m_textures.GetTex(pKey);
		}

		/// <summary>
		/// 色の合成を通常合成に変更する デフォルトでは通常合成になっている
		/// </summary>
		inline void DefaultBlendMode() const
		{
			m_colorBlender.DefaultBlendMode();
		}

		/// <summary>
		/// 色の合成を加算合成に変更する
		/// </summary>
		inline void AddtionBlendMode() const
		{
			m_colorBlender.AddtionBlendMode();
		}

		/// <summary>
		/// デフォルトの色合成を使用する ウィンドウモードを切り替えた時には再設定する必要がある
		/// </summary>
		inline void DefaultColorBlending() const
		{
			m_colorBlender.DefaultColorBlending();
		}

	private:
		Renderer m_renderer;
		Textures m_textures;
		ColorBlender m_colorBlender;
	};
}

#endif // !GRAPHICS_H_
