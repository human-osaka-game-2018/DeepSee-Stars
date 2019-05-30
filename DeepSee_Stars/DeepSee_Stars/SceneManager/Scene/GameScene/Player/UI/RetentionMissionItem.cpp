#include "RetentionMissionItem.h"

namespace deepseestars
{
	void RetentionMissionItem::Update()
	{
		m_missionItem = min(max(m_missionItem, 0), 4);
	}

	void RetentionMissionItem::Render()
	{
		D3DXVECTOR2 pos = { 1210.f, 650.f };
		D3DXVECTOR2 scale = { 70.f , 70.f };

		m_vertices.SetPos(pos);
		m_vertices.SetScale(scale);

		m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_MissionItemUITextureKey[0]));

		m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_MissionItemUITextureKey[m_missionItem + 1]));
	}
}
