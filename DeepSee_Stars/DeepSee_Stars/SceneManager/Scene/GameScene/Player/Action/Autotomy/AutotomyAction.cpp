#include "AutotomyAction.h"


namespace deepseestars
{

	void AutotomyAction::Update()
	{
		D3DXVECTOR2 centerBuf = m_center + m_distanceToOrigin;

		D3DXVECTOR2 pos = { centerBuf.x ,centerBuf.y };
		D3DXVECTOR2 scale = { m_ObjectSize / 2 ,m_ObjectSize / 2 };

		m_vertices.SetPos(pos);
		m_vertices.SetScale(scale);
	}

	void AutotomyAction::Render()
	{
		m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(GetactionTextureKey()[0]));

	}
}
