#include "BlockCell.h"

namespace deepseestars
{

	void BlockCell::Update()
	{

	}

	void BlockCell::Render()
	{
		D3DXVECTOR2 centerBuf = m_center + m_distanceToOrigin;

		D3DXVECTOR2 pos = { centerBuf.x ,centerBuf.y };
		D3DXVECTOR2 scale = { m_blockSize/2 ,m_blockSize/2 };

		m_vertices.SetPos(pos);
		m_vertices.SetScale(scale);

		bool InRangeX = -m_blockSize <= centerBuf.x && centerBuf.x <= m_vertices.GetDisplaySize().x + m_blockSize;
		bool InRangeY = -m_blockSize <= centerBuf.y && centerBuf.y <= m_vertices.GetDisplaySize().y + m_blockSize;
		
		if (InRangeX && InRangeY)
		{
			m_isWithinRenderArea = true;
		}
		else
		{
			m_isWithinRenderArea = false;
		}

		if (!m_isWithinRenderArea) return;

		switch (m_type)
		{
		case FLOOR:
			m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(_T("FloorBlock")));
			break;
		case WHITE_BLOCK:
			m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(_T("WhiteBlock")));
			break;
		case BLACK_BLOCK:
			m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(_T("BlackBlock")));
			break;
		case HIDE_BLOCK:
			m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(_T("HideBlock")));
			break;
		case PLAYER_RECOVERY_OBJECT:
			m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(_T("FloorBlock")));
			pos = { centerBuf.x ,centerBuf.y - m_blockSize / 4};
			m_vertices.SetPos(pos);
			m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(_T("PlayerRecoveryObject")));
			break;
		case SEAWEED:
			m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(_T("FloorBlock")));
			pos = { centerBuf.x ,centerBuf.y - m_blockSize / 4 };
			m_vertices.SetPos(pos);
			m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(_T("SeaWeed")));
			break;
		case MISSION_ITEM:
			m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(_T("FloorBlock")));
			pos = { centerBuf.x ,centerBuf.y - m_blockSize / 4 };
			m_vertices.SetPos(pos);
			m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(_T("MissionItem")));
			break;
		case GAMECLEARZONE:
			m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(_T("MissionItem")));
			break;
		case MISSIONSTART_GET4ITEMS:
			m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(_T("MissionStartLine")));
			break;
		}
	}
}
