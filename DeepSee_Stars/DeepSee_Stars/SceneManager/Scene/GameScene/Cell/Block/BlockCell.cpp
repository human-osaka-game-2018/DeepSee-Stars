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
		D3DXVECTOR2 scale = { m_blockSize ,m_blockSize };

		m_vertices.SetPos(pos);
		m_vertices.SetScale(scale);

		if (-m_blockSize <= centerBuf.x && centerBuf.x <= m_vertices.GetDisplaySize().x + m_blockSize && -m_blockSize <= centerBuf.y && centerBuf.y <= m_vertices.GetDisplaySize().y + m_blockSize)
		{
			switch (m_type)
			{
			case FLOOR:
				m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_pTextureKey));
				break;
			case WHITE_BLOCK:
				m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_pTextureKey));
				break;
			case BLACK_BLOCK:
				m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_pTextureKey));
				break;
			case HIDE_BLOCK:
				m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_pTextureKey));
				break;
			case PlAYER_RECOVERY_OBJECT:
				m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_pTextureKey));
				break;
			}
		}
	}
}
