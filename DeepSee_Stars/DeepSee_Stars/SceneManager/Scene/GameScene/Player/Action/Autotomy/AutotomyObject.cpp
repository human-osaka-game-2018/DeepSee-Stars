#include "AutotomyObject.h"


namespace deepseestars
{

	void AutotomyObject::Update()
	{
		D3DXVECTOR2 centerBuf = m_center + m_distanceToOrigin;

		D3DXVECTOR2 pos = { centerBuf.x ,centerBuf.y };
		D3DXVECTOR2 scale = { m_ObjectSize / 2 ,m_ObjectSize / 2 };

		m_vertices.SetPos(pos);
		m_vertices.SetScale(scale);
	}

	void AutotomyObject::Render()
	{
		m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(GetactionTextureKey()[0]));

	}
}
