#include "RetentionMissionItem.h"

namespace deepseestars
{
	void RetentionMissionItem::Update()
	{
		if (m_missionItem > 4)
		{
			m_missionItem = 4;
		}

		if (m_missionItem < 0)
		{
			m_missionItem = 0;
		}
	}

	void RetentionMissionItem::Render()
	{
		D3DXVECTOR2 pos = { 1210.f, 650.f };
		D3DXVECTOR2 scale = { 70.f , 70.f };

		m_vertices.SetPos(pos);
		m_vertices.SetScale(scale);

		m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_MissionItemUITextureKey[0]));
		switch (m_missionItem)
		{
		case 0:
			m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_MissionItemUITextureKey[1]));
			break;
		case 1:
			m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_MissionItemUITextureKey[2]));
			break;
		case 2:
			m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_MissionItemUITextureKey[3]));
			break;
		case 3:
			m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_MissionItemUITextureKey[4]));
			break;
		case 4:
			m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_MissionItemUITextureKey[5]));
			break;
		case 5:
			m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_MissionItemUITextureKey[6]));
			break;
		}
	}
}
