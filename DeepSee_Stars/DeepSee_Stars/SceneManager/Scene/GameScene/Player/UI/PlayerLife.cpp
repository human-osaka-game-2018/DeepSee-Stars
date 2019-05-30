#include "PlayerLife.h"

namespace deepseestars
{

	void PlayerLife::Update()
	{
		if (m_life > 5)
		{
			m_life = 5;
		}

		if (m_life < 0)
		{
			m_life = 0;
		}
	}

	void PlayerLife::Render()
	{
		D3DXVECTOR2 pos = { 70.f,70.f };
		D3DXVECTOR2 scale = { 70.f , 70.f };

		m_vertices.SetPos(pos);
		m_vertices.SetScale(scale);

		m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_LifeUITextureKey[0]));

		switch (m_life)
		{
		case 0:
			m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_LifeUITextureKey[1]));
			break;
		case 1:
			m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_LifeUITextureKey[2]));
			break;
		case 2:
			m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_LifeUITextureKey[3]));
			break;
		case 3:
			m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_LifeUITextureKey[4]));
			break;
		case 4:
			m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_LifeUITextureKey[5]));
			break;
		case 5:
			m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_LifeUITextureKey[6]));
			break;
		}
	}
}
