#ifndef TEXTURE_UV_H_
#define TEXTURE_UV_H_

#include <d3dx9.h>

namespace gamebasemaker
{
	class TextureUV
	{
	public:
		TextureUV() {}
		
		/// <summary>
		/// アニメーションさせたいときに必要な情報をつめる
		/// </summary>
		/// <param name="topLeft">アニメーション開始地点</param>
		/// <param name="imageSize">画像の大きさ</param>
		/// <param name="illustSize">1イラストの大きさ</param>
		TextureUV(D3DXVECTOR2 topLeft, D3DXVECTOR2 imageSize, D3DXVECTOR2 illustSize)
			:m_topLeft(topLeft), m_imageSize(imageSize), m_illustSize(illustSize) 
		{
			m_bottomRight = m_topLeft + m_illustSize;

			m_startUV = { m_topLeft.x / m_imageSize.x,m_topLeft.y / m_imageSize.y };
			m_endUV = { m_bottomRight.x / m_imageSize.x,m_bottomRight.y / m_imageSize.y };
		}

		TextureUV(D3DXVECTOR2 imageSize)
			:m_imageSize(imageSize) {}

		~TextureUV() {}

		/// <summary>
		/// 画像の切り取り
		/// </summary>
		/// <param name="topLeft">左上の座標</param>
		/// <param name="bottomRight">右下の座標</param>
		void ClippingImage(D3DXVECTOR2 topLeft, D3DXVECTOR2 bottomRight);

		/// <summary>
		/// アニメーションする
		/// </summary>
		/// <param name="nextAnimationFrame">次のアニメーションに行くフレーム数</param>
		/// <param name="animationNum">アニメーションのフレーム数</param>
		void Animation(int nextAnimationFrame, int animationNum);

		/// <summary>
		/// アニメーションを可能にする
		/// </summary>
		inline void PossibleAnimation()
		{
			m_isPossibleAnimation = true;
		}

		inline D3DXVECTOR2 GetStartUV()
		{
			return m_startUV;
		}

		inline D3DXVECTOR2 GetEndUV()
		{
			return m_endUV;
		}

		inline void SetImageSize(D3DXVECTOR2 imageSize)
		{
			m_imageSize = imageSize;
		}

		inline bool GetIsPossibleAnimation() { return m_isPossibleAnimation; }

	private:
		D3DXVECTOR2 m_startUV = { 0.0f,0.0f };
		D3DXVECTOR2 m_endUV =	{ 1.0f,1.0f };

		D3DXVECTOR2 m_topLeft = { 0.0f,0.0f };
		D3DXVECTOR2 m_bottomRight;

		D3DXVECTOR2 m_imageSize;
		D3DXVECTOR2 m_illustSize;

		int  m_animationCount = 0;
		int  m_AnimationNum = 0;
		bool m_isPossibleAnimation = false;
	};
}

#endif // !TEXTURE_UV_H_
