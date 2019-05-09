#include "TextureUV.h"

namespace gamebasemaker
{
	void TextureUV::ClippingImage(D3DXVECTOR2 topLeft, D3DXVECTOR2 bottomRight)
	{
		m_startUV = { topLeft.x	/ m_imageSize.x		,topLeft.y / m_imageSize.y };
		m_endUV   = { bottomRight.x / m_imageSize.x ,bottomRight.y / m_imageSize.y };
	}

	void TextureUV::Animation(int nextAnimationFrame, int animationNum)
	{
		m_animationCount = (m_animationCount > nextAnimationFrame)?
			0 : ++m_animationCount;

		if (nextAnimationFrame > m_animationCount) return;
		
		if (m_AnimationNum >= animationNum)
		{
			m_AnimationNum = 0;

			m_topLeft = { 0.f,0.f };
			m_bottomRight = { m_illustSize.x,m_illustSize.y };

			return;
		}

		++m_AnimationNum;

		m_startUV = { m_topLeft.x / m_imageSize.x,m_topLeft.y / m_imageSize.y };
		m_endUV = { m_bottomRight.x / m_imageSize.x,m_bottomRight.y / m_imageSize.y };

		m_topLeft.x += m_illustSize.x;
		m_bottomRight.x = m_topLeft.x + m_illustSize.x;

		if (m_bottomRight.x > m_imageSize.x)
		{
			m_topLeft.x = 0.f;
			m_topLeft.y += m_illustSize.y;
		}

		m_bottomRight.y = m_topLeft.y + m_illustSize.y;

		if (m_bottomRight.y > m_imageSize.y)
		{
			m_topLeft.y = 0.f;
		}
	}
}
