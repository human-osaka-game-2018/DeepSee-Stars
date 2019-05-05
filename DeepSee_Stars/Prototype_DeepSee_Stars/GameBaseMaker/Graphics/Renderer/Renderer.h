#ifndef RENDERER_H_
#define RENDERER_H_

#include <tchar.h>

#include <d3dx9.h>

#include "../../Device/DirectXDevices/DirectXDevices.h"
#include "../../GameBaseMaker/Vertices/Vertices.h"
#include "../Textures/Textures.h"

namespace graphics
{
	class Renderer
	{
	public:
		Renderer();
		~Renderer() {}

		/// <summary>
		/// 描画準備をする
		/// </summary>
		/// <remarks>メッセージループの最初で呼ぶ必要がある</remarks>
		void PrepareRendering();

		/// <summary>
		/// 描画を終了させる
		/// </summary>
		/// <remarks>メッセージループの最後に呼ぶ必要がある</remarks>
		void CleanUpRendering();

		/// <summary>
		/// 画像を描画する
		/// </summary>
		/// <param name="vertices">矩形の情報</param>
		/// <param name="texture">テクスチャの情報</param>
		void Render(gamebasemaker::Vertices vertices, Texture texture);

	private:
		device::DirectXGraphicDevice* m_DXGraphicDevice;
	};
}

#endif // !RENDERER_H_
