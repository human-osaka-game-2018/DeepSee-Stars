#include "BlockCell.h"

namespace deepseestars
{

	void BlockCell::Update()
	{

	}

	void BlockCell::Render()
	{
		D3DXVECTOR2 centerPosbBuf = m_BlockCenterPos + m_differencetoStartingPoint;

		D3DXVECTOR2 pos = { centerPosbBuf.x ,centerPosbBuf.y };
		D3DXVECTOR2 scale = { BLOCKSIZE ,BLOCKSIZE };

		m_vertices.SetPos(pos);
		m_vertices.SetScale(scale);

		if (-BLOCKSIZE <= centerPosbBuf.x && centerPosbBuf.x <= m_vertices.GetDisplaySize().x + BLOCKSIZE && -BLOCKSIZE <= centerPosbBuf.y && centerPosbBuf.y <= m_vertices.GetDisplaySize().y + BLOCKSIZE)
		{
			switch (m_BlockType)
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
