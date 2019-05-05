#include "Vertices.h"

namespace gamebasemaker
{
	void Vertices::BuildRect()
	{
		m_customVertices.BuildRect(m_pos, m_scale, m_degree, m_color, m_uv);
	}

	void Vertices::Rescale()
	{
		m_customVertices.Rescale(m_scale);
	}

	void Vertices::RotateX()
	{
		m_customVertices.RotateX(m_degree.x, m_pos);
	}

	void Vertices::RotateY()
	{
		m_customVertices.RotateY(m_degree.y, m_pos);
	}

	void Vertices::RotateZ()
	{
		m_customVertices.RotateZ(m_degree.z, m_pos);
	}

	void Vertices::FadeIn(BYTE alphaMax, BYTE alphaMin, int OneCycleCount)
	{
		m_color.FadeIn(alphaMax, alphaMin, m_fadeInCount , OneCycleCount);
	}

	void Vertices::FadeOut(BYTE alphaMax, BYTE alphaMin, int OneCycleCount)
	{
		m_color.FadeOut(alphaMax, alphaMin, m_fadeOutCount, OneCycleCount);
	}

	void Vertices::Flash(BYTE alphaMax, BYTE alphaMin, int OneCycleCount)
	{
		m_color.Flash(alphaMax, alphaMin, m_flashCount, OneCycleCount);
	}

	void Vertices::ClippingImage(D3DXVECTOR2 topLeft, D3DXVECTOR2 bottomRight)
	{
		m_uv.ClippingImage(topLeft, bottomRight);
	}

	void Vertices::Animation(int nextAnimationFrame,int animationNum)
	{
		m_uv.Animation(nextAnimationFrame, animationNum);
	}
}
