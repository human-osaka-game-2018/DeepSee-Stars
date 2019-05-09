#include "TitleLogo.h"

namespace deepseestars
{
	void TitleLogo::Render()
	{
		D3DXVECTOR2 pos = 
		{ m_vertices.GetDisplaySize().x * 0.5f ,m_vertices.GetDisplaySize().y * 0.25f };
		D3DXVECTOR2 scale = m_vertices.GetDisplaySize() * 0.25f;
		
		m_vertices.SetPos(pos);
		m_vertices.SetScale(scale);

		const int FADEIN_FRAME = 180;

		m_vertices.FadeIn(0xff, 0x00, FADEIN_FRAME);

		m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_pTextureKey));
	}
}
