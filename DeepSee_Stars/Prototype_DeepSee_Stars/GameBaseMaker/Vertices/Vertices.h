#ifndef VERTICES_H_
#define VERTICES_H_

#include "../../Wnd/Wnd.h"

#include "CustomVertices.h"
#include "../Color/Color.h"
#include "../TextureUV/TextureUV.h"

namespace gamebasemaker
{
	class Vertices
	{
	public:
		Vertices() :m_displaySize(window::Wnd::GetWndSize()) {}

		Vertices(TextureUV uv) :
			m_uv(uv), m_displaySize(window::Wnd::GetWndSize()) {}

		~Vertices() {}

		////////setter////////
		
		void SetDegree(const D3DXVECTOR3& degree){ m_degree = degree; }
		void SetDegreeX(const float& degreeX) { m_degree.x = degreeX; }
		void SetDegreeY(const float& degreeY) { m_degree.y = degreeY; }
		void SetDegreeZ(const float& degreeZ) { m_degree.z = degreeZ; }

		void SetPos(const D3DXVECTOR3& pos) { m_pos = pos; }

		void SetScale(const D3DXVECTOR2& scale) { m_scale = scale; }
		
		void SetColor(Color color) { m_color = color; }

		void SetTextureUV(TextureUV uv) { m_uv = uv; }

		/// <summary>
		/// 矩形の再設定
		/// </summary>
		void Rescale();

		/// <summary>
		/// ポリゴンの回転
		/// </summary>
		void RotateX();
		void RotateY();
		void RotateZ();

		/// <summary>
		/// フェードイン、フェードアウトさせる
		/// </summary>
		/// <param name="alphaMax">透明度の最大値</param>
		/// <param name="alphaMin">透明度の最小値</param>
		/// <param name="OneCycleCount">サイクルするためのフレーム数</param>
		void FadeIn(BYTE alphaMax, BYTE alphaMin, int OneCycleCount);
		void FadeOut(BYTE alphaMax, BYTE alphaMin, int OneCycleCount);

		/// <summary>
		/// 点滅させる
		/// </summary>
		/// <param name="alphaMax">透明度の最大値</param>
		/// <param name="alphaMin">透明度の最小値</param>
		/// <param name="OneCycleCount">サイクルするためのフレーム数</param>
		void Flash(BYTE alphaMax, BYTE alphaMin, int OneCycleCount);

		/// <summary>
		/// アニメーションさせる
		/// </summary>
		/// <param name="nextAnimationFrame">次の駒に行くためのフレーム数</param>
		/// <param name="animationNum">アニメーションの最大枚数</param>
		void Animation(int nextAnimationFrame, int animationNum);

		/// <summary>
		/// 画像の切り取る
		/// </summary>
		/// <param name="topLeft">切り取りたい位置の左上</param>
		/// <param name="bottomRight">切り取りたい位置の右下</param>
		void ClippingImage(D3DXVECTOR2 topLeft, D3DXVECTOR2 bottomRight);

		inline CustomVertex* Get()
		{
			BuildRect();
			return m_customVertices.Get();
		}

		inline D3DXVECTOR2 GetDisplaySize()
		{
			D3DXVECTOR2 displaySize =
			{
				static_cast<float>(m_displaySize.m_x),
				static_cast<float>(m_displaySize.m_y)
			};

			return displaySize;
		}

	private:
		void BuildRect();

		const RectSize m_displaySize;
	
		D3DXVECTOR3 m_pos = { 0.f,0.f,0.f };
		D3DXVECTOR2 m_scale = { m_displaySize.m_x / 2.f,m_displaySize.m_y / 2.f };
		D3DXVECTOR3 m_degree = { 0.f,0.f,0.f };
		
		int m_fadeInCount = 0;
		int m_fadeOutCount = 0;
		int m_flashCount = 0;

		TextureUV m_uv;
		Color m_color;
		CustomVertices m_customVertices;
	};
}

#endif // !VERTICES_H_
